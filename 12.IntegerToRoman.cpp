#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        char s[15] = "";
        char r[9] = {0,0,'M','D','C','L','X','V','I'};
        int i = -1;
        int times = 1000;
        for(int j=2;j<9;j=j+2) {
            int t = num/times;
            num %= times;
            times /= 10;
            if(t==9) {
                s[++i] = r[j];
                s[++i] = r[j-2];
            } else if(t>=5) {
                s[++i] = r[j-1];
                while(t>5) {
                    s[++i] = r[j];
                    t--;
                }
            } else if(t==4) {
                s[++i] = r[j];
                s[++i] = r[j-1];
            } else {
                while(t>0) {
                    s[++i] = r[j];
                    t--;
                }
            }
        }
        return s;
    }
};