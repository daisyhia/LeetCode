#include <limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
    	int result = 0;
        while(x != 0) {
            result = result*10 + x%10;
            if(result%10 != x%10) return 0;
            x /= 10;
        }
        return result;
    }
};