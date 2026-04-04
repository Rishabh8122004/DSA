class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long i = 1; i <= n; i *= 10) { // i -> position
            long digit = (n/i)%10; // if position = 3 in the number  14567, digit = 5 
            long left = n/(i*10); // left hand side value i.e if digit = 3 in the number 14357, left = 14
            long right = n%i; // right hand side value , i.e. if digit = 3 in 14357 ,  right = 57

            if (i == 1) {                  // first position i.e _ _ _ _ X
                if(digit == 0){
                    count += left;
                }
                if (digit >= 1){
                    count += left+1; // i.e. _ _ _ _ + 1
                }
            } 
            else if (i*10>n) { // last position i.e. X _ _ _ _
                if(digit == 1) count += (right+1);
                if(digit>1){
                    count += i;
                } 
            } 
            else {  // the rest of the positions i.e. _ X X X _

                if(digit == 0){
                    count += (left)*i; // (14)*(100) in the number 14057 for the positon i = 100 (00100 - 00199) to (13100 - 13199)
                }
                else if (digit == 1){ // number on that position is 1 ?
                    count +=  (left)*(i) + (1*(right+1));
                }
                else if(digit > 1){ // number on the position is > 1?
                    count += (left+1)*(i); // (15)*(100) in the number 14357 for the positon i = 100
                }
            }
        }
        return count;
    }
};