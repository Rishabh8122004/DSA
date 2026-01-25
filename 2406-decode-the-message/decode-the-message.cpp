class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int>v(26,-1);
        int x = 0;
        for(int i = 0;i<key.size();i++){
            if(key[i] == ' ')continue;
            if(v[key[i]-'a'] == -1)v[key[i]-'a'] = x++;
        }
        string ans = "";
        for(int i = 0;i<message.size();i++){
            if(message[i] == ' ')ans+=' ';
            else{
                ans += 'a'+ v[message[i]-'a'];
            }
        }
        return ans;
    }
};