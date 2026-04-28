class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = INT_MIN;
        int sum = 0 ;
        for(int i = 0; i < nums.size(); i++)
        {
            // 
            // for(int j = i ; j < nums.size();j++){
            sum += nums[i];
            maxValue = max(maxValue, sum);
            if(sum < 0) sum =0;
            // }
        }
        return maxValue;
    }
};