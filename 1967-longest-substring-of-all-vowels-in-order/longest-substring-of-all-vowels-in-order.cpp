class Solution {
public:
    pair<int,int> get_beautiful_string_lenght(string &w,int i){
        int x = i;
        while(i<w.size() && w[i] == 'a')i++;
        if(w[i]!='e')return {i-x,-1};
        while(i<w.size() && w[i] == 'e')i++;
        if(w[i]!='i')return {i-x,-1};
        while(i<w.size() && w[i] == 'i')i++;
        if(w[i]!='o')return {i-x,-1};
        while(i<w.size() && w[i] == 'o')i++;
        if(w[i]!='u')return {i-x,-1};
        while(i<w.size() && w[i] == 'u')i++;
        return {i-x,1};
    }
    int longestBeautifulSubstring(string w) {
        int n = w.size();
        int i = 0;
        int ans = 0;
        while(i<n){
            if(w[i] == 'a'){// a beautifull substring always starts with 'a'
                auto len = get_beautiful_string_lenght(w,i);// this will return a pair (len,valid or not), if len.seocnd == 1 means beautifull substring , if len.second == -1 , means not so beautifull... 
                i+=len.first-1; // increment i no matter what..
                if(len.second == 1)ans = max(ans,len.first); // updating answer if the substring was beautifull
            }
            i++;
        }
        return ans;
    }
};