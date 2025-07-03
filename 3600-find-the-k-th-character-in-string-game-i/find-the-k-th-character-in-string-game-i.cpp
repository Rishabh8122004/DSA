class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        if(k==1){return 'a';}
        while(s.size()<k)
        {
            string n = "";
            for(int i = 0;i<s.size();i++)
            {
                char ch = s[i];
                if(ch == 'z'){n+='a';continue;}
                n+=char((int)(ch)+1);
            }
            s+=n;
        }
        return s[k-1];

    }
};