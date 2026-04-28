class Solution {
public:
    int isDestroyAll(long mass, vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            if(mass >= nums[i]){
                mass += nums[i];
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        if(asteroids.size() == 1) {
            if (mass >= asteroids[0]) {
                return true;
            } else {
                return false;
            }
        }
        // vector<int> ans(asteroids.begin(), asteroids.end());
        sort(asteroids.begin(), asteroids.end());
        if(isDestroyAll(mass, asteroids) == true){
            return true;
        } else {
            return false;
        }
    }
};