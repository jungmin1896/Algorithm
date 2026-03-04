#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> classes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes.begin(), classes.end());

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++)
    {
        int S = classes[i].first;
        int T = classes[i].second;

        if (!q.empty() && q.top() <= S)
        {
            q.pop();
        }

        q.push(T);
    }

    cout << q.size() << endl;
}