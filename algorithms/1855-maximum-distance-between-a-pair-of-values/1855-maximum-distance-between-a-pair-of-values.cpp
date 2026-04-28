class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxValue = INT_MIN;
        int len2 = nums2.size();
        int len1 = nums1.size();
        for(int i = 0; i < len2; i++){
            int val = nums2[i];
            int left = 0;
            int right = len1;
            int mid = 0;
            while(left <= right){
                mid = left + (right - left)/2;
                if(mid < len1){
                     if(nums1[mid] < val){
                        right = mid - 1;
                    } else if(nums1[mid] > val){
                        left = mid + 1;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            // cout << left << " " << right << " "<< mid <<endl;
            // cout << i << " " << maxValue <<endl;
            if(left < len1 && left <= i && nums1[left] <= val) {
                maxValue = max(maxValue, abs(i - left));
            } else if(mid < len1 && mid <= i &&  nums1[mid] <= val) {
                maxValue = max(maxValue, abs(i - mid));
            }
            // if(maxValue > 460) {
            //     cout << left << " " << right << " "<< mid <<endl;
            //     cout << i << " " << maxValue <<endl;     
            // }
            // } else if(right < len1 && right <= i && nums1[right] <= val) {
            //     maxValue = max(maxValue, abs(i - right));
            // }
        }

        return maxValue == INT_MIN ? 0: maxValue;
    }
};