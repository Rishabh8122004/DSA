class Solution {
public:
    int space_provider_board(int w,int s){ /* this is a space provider board inaugrated by rishabh pareek to solve the conflict of space acquire between every two words in justification manner . 
    OUR MOTTO IS ->  "WE DO JUSTICE !"*/
    if(w == 0) return 0;// why need space if there are no two words.
    int x = 0; // number of space;
    while(s!=0){
        if(s>0 && s<w){x+=1;break;}
        x+=s/w;
        s = s%w;
    }
    return x;
    }
    vector<string> fullJustify(vector<string>& w, int width) {
        vector<string>ans;
        vector<vector<int>>v; // v will store the number of words can be inserted in each line .
        for(int i = 0;i<w.size();i++){
            int j = i;
            int now = 0,cw = width; // no. of words, current width
            if(w[j].size()<=cw){now++;cw-=w[j].size();j++;}
            while(j<w.size() && cw>=w[j].size()+1){
                now++;
                cw-=w[j].size()+1;
                j++;
            }
            v.push_back({now,cw}); // here, cw is the extra space which we will have to adjust to justify text
            i = j-1;
        }
        int j = 0;
        for(int i = 0;i<v.size()-1;i++){
            cout<<v[i][0]<<" "<<v[i][1]<<"     ";
            string text = "";
            if(v[i][0] == 1){text += w[j];while(v[i][1]--){text+=' ';}j++;}
            else{
                while(v[i][0]){
                    text+=(v[i][0] > 1?((w[j])+' '):(w[j]));
                    int x = space_provider_board(v[i][0]-1,v[i][1]);
                    while(x){text+=' ';x--;v[i][1]--;}
                    j++;v[i][0]--;
                }
            }
            ans.push_back(text);
        }
        // now, last line is due to be filled 
        int x = v[v.size()-1][0];
        string text = "";
        while(x>0){
            if(x>1)text+=w[j]+' ';
            else{
                text+=w[j];
                while(v[v.size()-1][1]--)text+=' ';
            }
            j++;
            x--;
        }
        ans.push_back(text);
        return ans;
    }
};