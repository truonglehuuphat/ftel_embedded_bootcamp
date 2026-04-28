class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;

    void DFS (vector<string> & mergedAccount, string & email){
        visited.insert(email);
        mergedAccount.push_back(email);
        for(string & neighbor: adjacent[email]){
            if(visited.find(neighbor) == visited.end()){
                DFS(mergedAccount, neighbor);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountsListSize = accounts.size();
        //build graph
        for(vector<string> account: accounts){
            int accountSize = account.size();
            string accountFirstMail = account[1];
            for(int i = 2; i < accountSize; i++){
                string email = account[i];
                adjacent[accountFirstMail].push_back(email);
                adjacent[email].push_back(accountFirstMail);
            }
        }
        // travese 
        vector<vector<string>> mergedAccounts;
        for(vector<string> account: accounts){
            string accountName = account[0];
            string accountFirstEmail = account[1];

            if(visited.find(accountFirstEmail) == visited.end()){
                vector<string> mergedAccount;
                mergedAccount.push_back(accountName);
                DFS(mergedAccount, accountFirstEmail);
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }
        return mergedAccounts;
    }
};