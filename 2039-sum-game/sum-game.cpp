class Solution {

public:

    bool sumGame(string num) {

        int n = num.size();

        int l = 0, lq = 0;

        for(int i = 0; i < n/2; i++){

            if(num[i] != '?')
                l += num[i] - '0';
            else
                lq++;
        }

        int r = 0, rq = 0;

        for(int i = n/2; i < n; i++){

            if(num[i] != '?')
                r += num[i] - '0';
            else
                rq++;
        }

        if(lq == rq){
            return l != r;
        }

        else{

            if(lq > rq){
                lq -= rq;
                rq = 0;
            }

            else{
                rq -= lq;
                lq = 0;
            }
        }

        // Convert to difference
        if(l > r){
            l -= r;
            r = 0;
        }
        else{
            r -= l;
            l = 0;
        }

        if(lq){

            if(l >= r){
                return true;
            }

            if(lq % 2 == 1)
                return true;

            return r != (lq/2)*9;
        }

        // rq > 0

        if(r >= l){
            return true;
        }

        if(rq % 2 == 1)
            return true;

        return l != (rq/2)*9;
    }
};