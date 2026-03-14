class Solution {
public:
    string getHappyString(int n, int k) {
        if(k>(3*(pow(2,n-1))))return ""; // n bit string -> 3*(2*2*2....(n-1 times)) 
        string ans = "";
        int mg = 3*(pow(2,n-1));
        for(int i = 0;i<n;i++){
            if(i == 0){
                if(k<=mg/3)ans+='a';
                else if(k<=(2*mg/3))ans+='b';
                else ans+='c';
                mg/=3;
                k %= mg;
                if(k == 0) k = mg;
            }
            else{
                if(k<=mg/2){
                    if(ans.back() == 'a')ans+='b';
                    else ans+='a';
                }
                else{
                    if(ans.back() == 'c')ans+='b';
                    else ans+='c';
                }
                mg /= 2;
                k %= mg;
                if(k == 0)k = mg;
            }
        }
        return ans;
    }
};