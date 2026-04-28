class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n,0);
        dist[start_node] = 1.0;
        int m = edges.size();
        for(int i = 0 ; i < n-1; i++){
            int flag = 0;
            for(int j = 0; j < m; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double w = succProb[j]; 
                if(w*dist[u] > dist[v]){
                    dist[v] = w*dist[u];
                    flag=1;
                }
                if(w*dist[v] > dist[u]){
                    dist[u] = w*dist[v];
                    flag=1;
                }
            }
            if(flag==0){
                break;
            }
        }

        return dist[end_node];
    }
};