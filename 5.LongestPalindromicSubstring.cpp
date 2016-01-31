#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    	int size = s.size();
    	int left = 0;
    	int max = 1;
    	for(int i=1; i<size; i++) {
    		if(isPali(s, i-max, i)) {
    			left = i-max;
    			max ++;
    		}
    		else if(isPali(s, i-max-1, i)) {
    			left = i-max-1;
    			max += 2;
    		}
		}
    	return s.substr(left, max);
    }
    bool isPali(string s, int left, int right) {
    	while(left < right) {
    		if(s[left++] != s[right--]) return false;
    	}
    	return true;
    }
    
};