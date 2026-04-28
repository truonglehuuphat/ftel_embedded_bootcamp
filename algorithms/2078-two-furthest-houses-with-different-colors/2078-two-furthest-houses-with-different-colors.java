class Solution {
    public int maxDistance(int[] colors) {
        int left = 0;
        int n = colors.length;
        int right = n - 1;
        int maxVal = Integer.MIN_VALUE;
        while(left <= right){
            if(colors[left] != colors[right]){
                maxVal = Math.max(maxVal, right - left);
                right--;
            } else {
                // right--;
            }
            left++;
        }
        left = 0;
        right = n-1;
        while(left <= right){
            if(colors[left] != colors[right]){
                maxVal = Math.max(maxVal, right - left);
                left++;
            } else {
                // right--;
            }
            right--;
        }
        return maxVal;
    }
}