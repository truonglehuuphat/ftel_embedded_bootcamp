class Solution {
    public int removeDuplicates(int[] nums) {
        int length = nums.length;
        int k = 0;
        for(int i = 0; i < length ; i++){
            if(nums[i] != nums[k]){
                k++;
                nums[k] = nums[i];
            }
        }
        return k+1;
    }
}