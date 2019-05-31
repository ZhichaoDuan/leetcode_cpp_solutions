#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> in_degree(numCourses, 0);
		if (prerequisites.size() == 0)
			return true;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			in_degree[prerequisites[i][0]]++;
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		

		queue<int> Q;
		for (int i = 0; i < numCourses; i++)
		{
			if (in_degree[i] == 0)
				Q.push(i);
		}

		while (!Q.empty())
		{
			int course = Q.front();
			Q.pop();
			vector<int> v = graph[course];
			for (int i = 0; i < v.size(); i++)
			{
				if (--in_degree[v[i]] == 0)
					Q.push(v[i]);
			}
		}
		for (int d : in_degree)
		{
			if (d!=0)
				return false;
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	int numCourses = 2;
	vector<vector<int>> pre{{1,0}};
	Solution sol;
	cout<<sol.canFinish(numCourses, pre);
	return 0;
}
