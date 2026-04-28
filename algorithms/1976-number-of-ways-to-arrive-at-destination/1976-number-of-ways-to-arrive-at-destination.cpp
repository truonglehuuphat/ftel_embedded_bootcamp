class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        long long MOD = 1e9 + 7;
        map<int,vector<pair<int,int>>> graph;
        for(int i = 0 ; i < m; i++ ){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<long long> dst(n, LLONG_MAX);
        vector<int> path(n,0);
        dst[0] = 0;
        path[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            // pair<int,long long> top = pq.top(); 
            int node = pq.top().second;
            long long time = pq.top().first ;
            pq.pop();
            if(time > dst[node]) continue;
            for(auto d: graph[node]){
                int v = d.first;
                int w = d.second;
                if(time + w < dst[v]){
                    dst[v] = time + w;
                    path[v] = path[node];
                    pq.push({dst[v], v});
                } else if(time + w == dst[v]){
                    path[v] = (path[node] + path[v]) % MOD; 
                }
            }
        }

        return path[n-1];
    }
};