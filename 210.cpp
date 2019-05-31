#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			in_degree[prerequisites[i][0]]++;
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		

		vector<int> res(numCourses, 0);
        
        int first=0,last=0;
        
        for (int i=0;i<numCourses;i++) {
            if (in_degree[i]==0) {
                res[last++] = i;
            }
        }
        while(first<last) {
            vector<int> tmp = graph[res[first]];
            if (tmp.size()!=0) {
                for (int c:tmp) {
                    if (--in_degree[c]==0) res[last++] = c;
                }
            }
            first++;
        }
        if (last!=numCourses) return vector<int>();
        return res;
    }
};