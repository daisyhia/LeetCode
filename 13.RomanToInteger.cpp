#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        const char *p = s.c_str();
        char r[7] = {'I','V','X','L','C','D','M'};
        int num[7] = {1,5,10,50,100,500,1000};
        p += s.size()-1;
        for(int i=0;i<7;i++) {
            while(*p) {
                if(*p==r[i]) result+=num[i];
                else if(i>0&&i<3&&*p==r[0]) result-=num[0];
                else if(i>2&&i<5&&*p==r[2]) result-=num[2];
                else if(i>4&&*p==r[4]) result-=num[4];
                else break;
                p--;
            }
        }
        return result;
    }
};