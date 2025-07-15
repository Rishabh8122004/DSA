class Solution {
public:
    bool isvowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool isValid(string word) {
        if(word.size()<3)return false;
        bool digits = false,upper = false,lower = false,vowel = false,consonant = false;
        for(int i = 0;i<word.size();i++){
            if(word[i] >= '0' && word[i] <= '9')digits = true;
            else if(word[i] >='a' && word[i] <= 'z'){
                if(isvowel(word[i]))vowel = true;
                else consonant = true;
                lower = true;
            }
            else if(word[i] >='A' && word[i] <= 'Z'){
                if(isvowel(word[i]))vowel = true;
                else consonant = true;
                upper = true;
            }
            else return false;
        }
        return (vowel && consonant);
    }
};