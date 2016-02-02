#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char* ps, const char* pp) {
        while(*pp) { 
            if(*pp=='*') return isMatch(ps, pp+1);
            if(!*(pp+1)) { 
                if(!*ps) return false;
                if(*pp!='.' && *ps!=*pp) return false;
                return !*(ps+1);
            }
            if(*(pp+1)=='*') {
                if(isMatch(ps, pp+2)) return true;
                while(*ps && (*ps==*pp||*pp=='.')) {
                    if(isMatch(++ps,pp+2)) return true;
                }
                return false;
            } else {
                if(!*ps) return false;
                if(*pp!='.' && *ps!=*pp) return false;
                return isMatch(ps+1, pp+1);
            }
        }
        return !*ps;
    }
};