#include <iostream>
#include <vector>
#include <queue>
#include <climits>   // INT_MAX
using namespace std;

typedef pair<int, int> edge;

int V, E, K;

vector<int> mdistance;
vector<bool> visited;
vector<vector<edge>> mlist;
priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
    cin >> V >> E;
    cin >> K;

    mdistance.resize(V + 1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);

    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);

    mlist.resize(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    mdistance[K] = 0;
    q.push(make_pair(0, K));

    while (!q.empty())
    {
        edge current = q.top();
        q.pop();

        int c_v = current.second;

        if (visited[c_v]) continue;
        visited[c_v] = true;

        for (int i = 0; i < (int)mlist[c_v].size(); i++)
        {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if (mdistance[next] > mdistance[c_v] + value)
            {
                mdistance[next] = mdistance[c_v] + value;
                q.push(make_pair(mdistance[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (mdistance[i] == INT_MAX) cout << "INF\n";
        else cout << mdistance[i] << "\n";
    }

    return 0;
}