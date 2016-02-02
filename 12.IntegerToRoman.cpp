#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        char s[15] = "";
        char r[7] = {'M','D','C','L','X','V','I'};
        int t = num/1000;
        int i = -1;
        while(t>0) {
            s[++i] = 'M';
            t--;
        }
        int times = 1000;
        for(int j=2;j<7;j=j+2) {
            num %= times;
            times /= 10;
            t = num/times;
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