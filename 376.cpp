class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) {
            return nums.size();
        }
        
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int state = BEGIN;
        int max_length = 1;
        
        for(int i=1; i<nums.size(); i++){
            switch (state){
                case BEGIN:
                    if (nums[i-1]<nums[i]) {
                        state=UP;
                        max_length++;
                    }
                    else if (nums[i-1]>nums[i]) {
                        state = DOWN;
                        max_length++;
                    }
                    break;
                case UP:
                    if (nums[i-1]>nums[i]) {
                        state=DOWN;
                        max_length++;
                    }
                    break;
                case DOWN:
                    if (nums[i-1]<nums[i]) {
                        state = UP;
                        max_length++;
                    }
                    break;
                    
            }
        }
        return max_length;
    }
};
