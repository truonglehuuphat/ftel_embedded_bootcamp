class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minVal = INT_MAX;
        int len = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        for(right = 0; right < len; right++){
            sum += nums[right];
            while(sum >= target){
                minVal = min(minVal,right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        // while(left < len || sum >= target){
        //     sum -= nums[left];
        //     left++;
        //     if(sum >= target){
        //         minVal = min(minVal,right - left);
        //     }
        // }
        // while(left < right && right < len){
        //     // cout << right << " left " << left << " " <<minVal << endl;
        //     sum += nums[right];
        //     if(sum >= target){
        //         left++;
        //         minVal = min(minVal, right - left);
        //         sum -= nums[left];
        //     }
        //     if(right < len){
        //         right++;
        //     }
        // }     
        // while(left < len && sum >= target){
        //     if(sum >= target){
        //         minVal = min(minVal,right - left);
        //         sum -= nums[left];
        //         left++;
        //     }
        // }        
        return minVal == INT_MAX ? 0: minVal;
    }
};