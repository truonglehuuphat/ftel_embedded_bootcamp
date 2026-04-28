class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // vector<int> res;
        // int n = nums.size();
        // for(int d : queries){
        //     int val = nums[d];
        //     int flag = 0;
        //     for(int i = 1 ; i < n; i++){
        //         int forward = (d + i) % n;
        //         int backward = (d - i + n) % n;
        //         if(nums[forward] == val || nums[backward] == val){
        //             res.push_back(i);
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag == 0){
        //         res.push_back(-1);
        //     }
        // }
        // return res;
        map<int,vector<int>> mp;
        vector<int> res;
        int n = nums.size();
        for(int i = 0;i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto& [_,pos]: mp){
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x+n);
        }
        for(int i = 0 ; i < queries.size(); i++){
            int diff = 0;
            int minIndex = n;
            int y = queries[i];
            int x = nums[y];       
            if(mp[x].size() == 3){
                res.push_back(-1);
                continue;
            }
            // for(int d : mp[x]){
            int left = 0;
            int right = mp[x].size()-1;
            int mid = left + (right - left)/ 2;
            while(left <= right){
                if(mp[x][mid] < y ){
                    left = mid + 1;
                } else if(mp[x][mid] > y) {
                    right = mid - 1;
                } else {
                    break;
                }
                mid = left + (right - left)/ 2;
            }
            minIndex = min(mp[x][mid+1]- mp[x][mid], mp[x][mid] - mp[x][mid-1]);
            // }
            if(minIndex != n) {
                res.push_back(minIndex);
            }
            else {
                res.push_back(-1);
            }
        }
            
        return res;
    }
};