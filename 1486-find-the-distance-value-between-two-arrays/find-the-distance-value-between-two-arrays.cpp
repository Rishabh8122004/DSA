class Solution {
public:
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        sort(a2.begin(),a2.end());
        int ans = 0;
        for(int i = 0;i<a1.size();i++){
            int lo = 0,hi = a2.size()-1,mid;
            bool f = true;
            while(lo<=hi){
                mid = (lo+(hi-lo)/2);
                if(a2[mid] == a1[i]){
                    if(d >= abs(a2[mid]-a1[i])){
                        f = false;
                        break;
                    }
                    break;
                }else if(a2[mid] > a1[i]){
                    if(d >= abs(a2[mid]-a1[i])){
                        f = false;
                        break;
                    }
                    hi = mid-1;
                }else{
                    if(d >= abs(a2[mid]-a1[i])){
                        f = false;
                        break;
                    }
                    lo = mid+1;
                }
            }
            if((mid-1 >= 0) && (abs(a2[mid-1]-a1[i]) <= d)){
                f = false;
            }
            if((mid+1 <a2.size()) && (abs(a2[mid+1] - a1[i]) <= d)){
                f = false;
            }
            if(f)ans++;
        }
        return ans;
    }
};