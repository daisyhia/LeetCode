#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        const char *p = strs[0].c_str();
        int k = strs[0].size();
        for(int i=1;i<strs.size();i++) {
            k = startWith(strs[i].c_str(), p, k);
        }
        return strs[0].substr(0,k);
    }
    int startWith(const char *s, const char *p, int k) {
        int i = 0;
        while(s[i]&&p[i]&&i<k) {
            if(s[i]!=p[i]) break;
            i++;
        }
        return i;
    }
};