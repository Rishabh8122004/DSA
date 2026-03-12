class Solution {
public:
    string smallestSubsequence(string s) {
        // conditions for an element to get accepted in the answer string :
        /*
        1. there is no other element of it in the rest of the string.
        2. the greatest element only occurs before the last index of the current element
        3. there is no smaller element before occuring of the index of greatest element
        */
        int n = s.size();
        vector<int>v(26,0); // will store the last appearing index of each character
        stack<char>st;
        for(int i = 0;i<n;i++){
            v[s[i]-'a'] = i;
        }
        // now let' fill up the monotonic stack , in which characters will be stored in decreaing order but maintaing the condition that if any bigger element appeared which is not coming again, it stays.
        vector<int>stack_freq(26,0);// this will help us check if the current element is already taken in stack ?
        for(int i = 0;i<n;i++){
            if(stack_freq[s[i]-'a']>0)continue;
            while(!st.empty()){
                if(st.top()>s[i] && v[st.top()-'a']>i){
                    stack_freq[st.top()-'a']--;
                    st.pop();
                }
                else break;
            }
            st.push(s[i]);
            stack_freq[s[i]-'a']++;
        }
        s = "";//using 's' as answer string
        while(!st.empty()){
            s = st.top()+s;
            st.pop();
        }
        return s;
    }
};