class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<int> ans;
        vector<vector<int>> res;
        if(firstList.size() == 0 || secondList.size()== 0) return res;
        int m = firstList.size();
        int n = secondList.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            vector<int> a = firstList[i];
            vector<int> b = secondList[j];

            int startMax = max(a[0], b[0]);
            int endMin = min(a[1], b[1]);

            if(endMin >= startMax){
                res.push_back({startMax,endMin});
            }
            if(a[1] == endMin ){i++;}
            if(b[1] == endMin){j++;}
        }
        return res;
    }
};