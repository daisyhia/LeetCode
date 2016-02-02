#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        char a[20] = "";
        int t = num/1000;
        int i = -1;
        while(t>0) {
            a[++i] = 'M';
            t--;
        }
        num = num%1000;
        t = num/100;
        if(t==9) {
            a[++i] = 'C';
            a[++i] = 'M';
        } else if(t>=5) {
            a[++i] = 'D';
            while(t>5) {
                a[++i] = 'C';
                t--;
            }
        } else if(t==4) {
            a[++i] = 'C';
            a[++i] = 'D';
        } else {
            while(t>0) {
                a[++i] = 'C';
                t--;
            }
        }
        num = num%100;
        t = num/10;
        if(t==9) {
            a[++i] = 'X';
            a[++i] = 'C';
        } else if(t>=5) {
            a[++i] = 'L';
            while(t>5) {
                a[++i] = 'X';
                t--;
            }
        } else if(t==4) {
            a[++i] = 'X';
            a[++i] = 'L';
        } else {
            while(t>0) {
                a[++i] = 'X';
                t--;
            }
        }
        t = num%10;
        if(t==9) {
            a[++i] = 'I';
            a[++i] = 'X';
        } else if(t>=5) {
            a[++i] = 'V';
            while(t>5) {
                a[++i] = 'I';
                t--;
            }
        } else if(t==4) {
            a[++i] = 'I';
            a[++i] = 'V';
        } else {
            while(t>0) {
                a[++i] = 'I';
                t--;
            }
        }
        return a;
    }
};