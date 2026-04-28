class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(int i = 0; i < queries.size(); i++){
            string wordQ = queries[i];
            for(int j = 0 ; j < dictionary.size(); j++){
                string wordD = dictionary[j];
                int count =differentWord(wordQ, wordD);
                if(count <= 2){
                    // auto it = find(res.begin(), res.end(), wordQ);
                    // if(it == res.end()){
                       res.push_back(wordQ);
                       break;
                    // }
                }
            }
        }
        return res;
    }
    int differentWord(string s1, string s2){
        int count = 0;
        for(int i =0; i< s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
        }
        return count;
    }
};