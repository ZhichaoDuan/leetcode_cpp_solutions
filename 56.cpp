#include <bits/stdc++.h>
using namespace std;
bool myCmp(const vector<int> lhs, const vector<int> rhs) {
  if (lhs[0]!=rhs[0])  {
    return lhs[0]<rhs[0];
  }
  return lhs[1]<rhs[1];
}

class Solution {
public:
  vector<vector<int> > merge(vector<vector<int> >& intervals) {
    if (intervals.size()<2)  {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), myCmp);
    vector<vector<int>> res;
    for (size_t i = 1; i < intervals.size(); i++) {
      if (intervals[i-1][1]>=intervals[i][0]) {
        intervals[i][0]=intervals[i-1][0];
        intervals[i][1]=max(intervals[i][1], intervals[i-1][1]);
        // intervals.erase(intervals.begin()+i);
        // i--;
      }
      else {
        res.push_back(intervals[i-1]);
      }
    }
    res.push_back(intervals[intervals.size()-1]);
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<vector<int> > v;
  std::vector<int> v1{0,1};
  std::vector<int> v2{1,2};
  std::vector<int> v3{10,1};
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v=sol.merge(v);
  for (vector<int> t : v) {
    cout<<t[0]<<"-"<<t[1]<<endl;
  }
  return 0;
}
