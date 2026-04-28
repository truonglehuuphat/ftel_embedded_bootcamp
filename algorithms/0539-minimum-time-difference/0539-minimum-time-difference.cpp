class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(string s: timePoints){
            int hour = s[0] *10 + s[1];
            int min = s[3]*10 + s[4];
            int totalMin = hour*60 + min;
            minutes.push_back(totalMin);
        }
        int res = 10000;
        int diff = 0;
        sort(minutes.begin(), minutes.end());
        for(int i = 0; i < timePoints.size()-1; i++){
            diff = min( abs(minutes[i]- minutes[i+1]), 24*60-abs(minutes[i]- minutes[i+1]));
            if(diff < res){
                res = diff;
            }
        }
        // diff = minutes[minutes.size() - 1] - minutes[0];
        diff = min( abs(minutes[minutes.size() - 1]- minutes[0]), 24*60-abs(minutes[0]- minutes[minutes.size() - 1]));
        if(diff < res) res = diff;
        return res;
    }
};