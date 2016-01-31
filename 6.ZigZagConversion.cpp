#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows == 1) return s;
    	string result = s;
    	int size(s.size()), n((numRows-1)*2), left(0), loc1(0), loc2(0);
    	for(int i=0; i<numRows; i++) {
    		for(int j=0; j<size; j++) {
    			loc1 = j*n+i;
    			if(loc1 >= size) break;
    			result[left] = s[loc1];
    			left++;
    			loc2 = j*n+n-i;
    			if(loc2 >= size) break;
    			if(loc2 == loc1) continue;
    			if(loc2-loc1==n) continue;
    			result[left] = s[loc2];
    			left++;
    		}
    	}
    	return result;
    	
    }
};