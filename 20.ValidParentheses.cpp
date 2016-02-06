class Solution {
public:
    bool isValid(string s) {
        const char *p = s.c_str();
        stack<char> sta;
        while(*p) {
            if(*p=='('||*p=='['||*p=='{') {
                sta.push(*p);
            } else {
                if(sta.empty()) return false;
                if(*p==')') {if(sta.top()!='(') return false;}
                else {if(!(*p-sta.top()==2)) return false;}
                sta.pop();
            }
            p++;
        }
        return sta.empty();
    }
};