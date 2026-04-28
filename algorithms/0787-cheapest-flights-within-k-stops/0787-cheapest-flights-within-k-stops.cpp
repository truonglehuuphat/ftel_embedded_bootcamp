class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        map<int, vector<pair<int,int>>> graph;
        for(int i =0; i < m; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back({v,w});
        }
        vector<long long> costFlight(n+1, INT_MAX);
        vector<int> path(n+1, 0);
        costFlight[src] = 0;
        path[src] = 1;
        priority_queue<pair<int, pair<long long, int>>, vector<pair<int, pair<long long, int>>>, greater<>> pq;
        pq.push({0,{0,src}});

        while(!pq.empty()){
            long long stopStation = pq.top().first;
            long long costFlightNode = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(k < stopStation) continue;
            for(auto d: graph[node]){
                long long w = d.second;
                int v = d.first;
                if(w + costFlightNode < costFlight[v] && stopStation <= k){
                    costFlight[v] = w + costFlightNode;
                    pq.push({stopStation+1, {costFlight[v], v}});
                }
            }
        }
        return costFlight[dst] != INT_MAX ? costFlight[dst] : -1;
    }
};