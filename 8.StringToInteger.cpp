#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int INT_MAX = 2147483647;
        int INT_MIN = -2147483648;
        const char *c = str.c_str();
        long result(0);
        int k(1);
        while(*c == ' ') c++;
        if(*c == '-') {
            k = -1;
            c++;
        } else if(*c == '+') {
            c++;
        }
       for(int i=0;i<11;i++) {
            if(*c<'0'||*c>'9') break;
            result *= 10; 
            result = result + *c - '0';
            c++;
        }
        result *= k;
        if(result > INT_MAX) return INT_MAX;
        if(result < INT_MIN) return INT_MIN;
        
        return result;
    }
};