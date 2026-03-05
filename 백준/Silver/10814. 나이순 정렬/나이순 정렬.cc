#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int age;
	string name;
	
	vector<pair<int, string>> v; //주의1

	bool compare(pair<int, string> a, pair<int, string> b);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;

		v.push_back({age,name}); //2
		
	}

	stable_sort(v.begin(), v.end(), compare); //3

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
}

bool compare(pair<int, string> a, pair<int, string> b) //4
{
	return a.first < b.first;
}

