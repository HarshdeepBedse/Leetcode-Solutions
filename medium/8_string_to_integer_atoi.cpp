class Solution {
public:
    int myAtoi(string s) {
        int num=0,i=0,sign=1;
        while(s[i]==' '){
            i++;
        }
        while(i<s.size()&& (s[i]=='-'||s[i]=='+')){
            sign=s[i]=='+'?1:-1;
            i++;
            break;
            
        }
        while(i<s.size()&&isdigit(s[i])){
            if(num>INT_MAX/10||(num==INT_MAX/10 && s[i]>'7')){
                return sign==-1?INT_MIN:INT_MAX;
            }
            num=num*10+(s[i]-'0');
            i++;
        }
        return num*sign;
    }
};