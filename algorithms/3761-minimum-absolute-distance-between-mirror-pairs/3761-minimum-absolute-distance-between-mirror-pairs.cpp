class Solution {
public:
    int reverseNum(int x){
        // int digit = 0;
        int sum = 0;
        int n = x;
        // string s = "";
        while(n > 0){
            // digit = n % 10;
            // s = s + to_string(digit);
            sum = sum*10 + n %10;
            n = n /10;
        }
        // if(s[0] == '0'){
        //    s.erase(s.begin()+0);
        // }
        // cout << "reverseNum " << s << endl;
        // return stoi(s);
        return sum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0 ;i < len;i++){
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        for(int i = 0; i < len -1 ; i++){
            int x = nums[i];
            int reverseValue = reverseNum(x);
            // di tu upper_bound lower-bound de tim gia tri lon hon no ke tiep tron mp[reverseValue];
            if (mp[reverseValue].size() == 1){

            }
            auto upper_bd = upper_bound(mp[reverseValue].begin(), mp[reverseValue].end(), i);
            auto lower_bd = lower_bound(mp[reverseValue].begin(), mp[reverseValue].end(), i);
            if(upper_bd != mp[reverseValue].end() && lower_bd != mp[reverseValue].end()){
                // cout << *lower_bd << " " << i << " " << *upper_bd << endl;
                if(*upper_bd != i && *lower_bd != i){
                    int diff = min(abs(*upper_bd - i), abs(*lower_bd - i));
                    minDist = min(minDist, diff);
                }
                if(*upper_bd == i){
                    int diff = abs(*lower_bd - i);
                    minDist = min(minDist, diff); 
                } 
                if(*lower_bd == i){
                    int diff = abs(*upper_bd - i);
                    minDist = min(minDist, diff); 
                } 
            }
            // for(int j = i+1; j < len ; j++){
            //     int reverseValue = reverseNum(x);
            //     if(reverseValue == nums[j]){
            //         int diff = abs(j-i);
            //         minDist = min(minDist, diff);
            //     }
            // }
            // int left = i;
            // int right = len -1;
            // while(left <= right){
            //     mid = left + (right - left)/2;
            //     if(nums[mid] > x){
            //         right = mid -1;
            //     } else if(nums[mid] < x){
            //         left = mid +1;
            //     } else {
            //         break;
            //     }
            // }
            // minDist = min(minDist, abs(mid - i));
        }
        // cout << minDist << endl;
        return minDist != INT_MAX ? minDist:-1;
    }
};