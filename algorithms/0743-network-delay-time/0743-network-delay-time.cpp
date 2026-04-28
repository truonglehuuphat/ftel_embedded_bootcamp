class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m =times.size();
        unordered_map<int ,vector<pair<int,int>>> mp;

        for(int i = 0 ; i  < m; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            mp[u].push_back({v,w});
            // mp[w].push_back({u,w});
        }
        vector<int> ans(n+1, INT_MAX);
        ans[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            pair<int,int> top = q.top(); q.pop();
            int dis=top.first;
            int node=top.second;
            if(dis > ans[node]) continue;
            for(auto d: mp[node]){
                int v = d.first;
                int w = d.second;
                if((dis + w ) < ans[v]) {
                    ans[v] = dis + w;
                    q.push({ans[v], v});                    
                }
            }
        }
        int maxValue = ans[1];
        for(int i = 1; i <= n; i++){
            if(ans[i] == INT_MAX) return -1;
            maxValue = max(maxValue, ans[i]);
        }
        return maxValue;
    }
};