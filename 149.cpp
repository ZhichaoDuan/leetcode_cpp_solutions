int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()==0) {
            return 0;
        }
        int max_num = 0;
        int same_point_num = 0;
        for (int i=0;i<points.size();i++) {
            map<pair<int, int>, int> slope_map;
            same_point_num = 0;
            for (int j=0;j<points.size();j++) {
                if (j==i) continue;
                if (points[i][0]==points[j][0]&&points[i][1]==points[j][1]) {
                    same_point_num++;
                }
                else if(points[i][0]==points[j][0]&&points[i][1]!=points[j][1]) {
                    slope_map[make_pair(1,0)]++;
                }
                else {
                    int delta_x = points[i][0]-points[j][0];
                    bool x_pos = delta_x > 0?true:false;
                    int delta_y = points[i][1]-points[j][1];
                    bool y_pos = delta_y > 0?true:false;
                    int common = gcd(abs(delta_x), abs(delta_y));
                    delta_x = abs(delta_x)/common;
                    delta_y = abs(delta_y)/common;
                    if (x_pos^y_pos) delta_x /= -1;
                    slope_map[make_pair(delta_x, delta_y)]++;
                }
            }
            int tmp_max = 0;
            for(map<pair<int, int>, int>::iterator it=slope_map.begin();it!=slope_map.end();it++) {
                if (it->second>tmp_max) {
                    tmp_max = it->second;
                }
            }
            if (tmp_max+same_point_num>max_num) {
                max_num = tmp_max + same_point_num;
            }
        }
        return max_num+1;
    }
};
