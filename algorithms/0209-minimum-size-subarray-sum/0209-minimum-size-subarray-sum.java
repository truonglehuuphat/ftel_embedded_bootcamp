class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left =0;
        int right = 0;
        int minValue = Integer.MAX_VALUE;
        int len = nums.length;
        int sum =0;
        for(right = 0 ;right < len; right++){
            sum += nums[right];
            while(left < len && sum >= target){
                minValue = Math.min(minValue, right -left + 1);
                sum-=nums[left];
                left++;
            }
        }
        return minValue == Integer.MAX_VALUE ? 0: minValue;
    }
}