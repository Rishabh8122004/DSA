class Solution {
public:
    int minimumPushes(string word) {
        long long cost = 0;
        sort(word.begin(),word.end());
        vector<vector<int> > v; // for storing letter frequency cost of each character.
        for(int i = 0;i<word.size();i++)
        {
            vector<int> a(2);  
            long long freq = 1;
            while(word[i] == word[i+1])
            {
                freq++;
                i++;
            }
            a[0] = freq; // frequency
            v.push_back(a); // frequency stored in vector
        }
        sort(v.begin(),v.end()); // sorted to get non decreasing order
        reverse(v.begin(),v.end()); // reversed it to get non increasing order
        for(int j=0;j<v.size();j++)
        {
                if(j<8)
                {
                    v[j][1] = 1;
                }
                else if(j<16)
                {
                    v[j][1] = 2;
                }
                else if(j<24)
                {
                    v[j][1] = 3;
                }
                else{
                    v[j][1] = 4;
                }
            
        }
        for(int i = 0;i<v.size();i++)
        {
            cost += (v[i][0]*v[i][1] );
        }

        return cost;
    }
};