class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        vector<int> freq(limit+1);
        int ans = 0;
        for(int j = 0;j<=n-1;j++){
            freq[people[j]]++;
        }
        ans+=freq[limit];
        n -=freq[limit];
        freq[limit] = 0;
        for(int i = 0;i<n;i++){
            if(freq[people[i]]>0){
            if(freq[limit-people[i]]>0){freq[limit-people[i]]--;}
            else{
                for(int j = n-1;j>i;j--){
                    if((freq[people[j]]>0) &&(people[i]+people[j]<=limit)){freq[people[j]]--;break;}
                }
            }
            ans++;
            freq[people[i]]--;}
        }
        return ans;
    }
};