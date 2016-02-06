class Solution {
public:
    bool isValid(string s) {
        const char *p = s.c_str();
        while(*p) {
            if(*p=='('||*p=='['||*p=='{') {
                if(!*(p+1)) return false;
                if(*(p+1)-*p==1) p+=2;
                else return false;
            } else return false;
        }
        return true;
    }
};