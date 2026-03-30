class Solution {
public:
    bool is_number(string s,bool dot,bool digit,bool exp){
        if(s == "." || s == "e" || s == "E")return false;
        if(s == "0")return true;
        string type = ""; // this will tell the type of previously occured entity(i.e. e,int,dot,sign,etc)
        for(int i = 0;i<s.size();i++){
            if(s[i] >= '0' && s[i]<='9'){
                if(type != "int" && type != "exp" && type != "dot" && type != "sign" && type != "") return false;
                digit = true;
                type = "int";
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(type != "")return false;
                type = "sign";
            }
            else if(s[i] == 'E' || s[i] == 'e'){
                if((type != "int" && type!= "dot") || ( exp || !digit))return false;
                exp = true;
                if(!is_number((i+1<s.size()?s.substr(i+1,s.size()-(i+1)):""),dot,digit,exp))return false;
                else return true;
                type = "exp";
            }
            else if(s[i] == '.'){
                if((type!="int" && type != "" && type != "sign" )||(exp))return false;
                if(dot)return false;
                type = "dot";
                dot = true;
            }
            else return false;
        }
        //if(s[0] == '0' && (type != "exp" && type != "sign" && type != ""))return true;
        return (type != "exp" && type != "sign" && type != "" && !(!digit && type == "dot"));
    }
    bool isNumber(string s) {
        return is_number(s,false,false,false);
    }
};