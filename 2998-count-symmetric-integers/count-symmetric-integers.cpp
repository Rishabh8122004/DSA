class Solution {
public:
    bool issymmetric(string s){
        int i = 0;
        int s1 = 0;
        while(i<s.size()/2){s1+=(s[i]-'a');i++;}
        while(i<s.size()){s1-=(s[i]-'a');i++;}
        return s1 == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low;i<=high;i++){
            if(i>=1 && i<10){i = 9;continue;} 
            else if(i>=100 && i<1000){i = 999;continue;} 
            if(issymmetric(to_string(i)))ans++;
        }
        return ans;
    }
};