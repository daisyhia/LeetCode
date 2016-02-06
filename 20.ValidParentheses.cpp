class Solution {
public:
    bool isValid(string s) {
        const char *p = s.c_str();
        char *m = new char[100];
        while(*p) {
            if(*p=='('||*p=='['||*p=='{') {
                m++;
                *m = *p;
            } else if(*p==')') {
                if(!*m||*m!='(') return false;
                m--;
            } else if(*p==']') {
                if(!*m||*m!='[') return false;
                m--;
            } else if(*p=='}') {
                if(!*m||*m!='{') return false;
                m--;
            }
            p++;
        }
        return !*m;
    }
};