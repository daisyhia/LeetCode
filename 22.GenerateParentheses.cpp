class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int m[n];
        for(int i=0;i<n-1;i++) {
            m[i] = i;
        }
        m[n-1] = n-2;
        int j = n-1;
        while(j>=0) {
            m[j]++;
            for(j;j<n-1;j++) m[j+1] = m[j]+1;
            char *tmp = new char[2*n];
            j = 0;
            for(int i=0;i<n;i++) {
                while(m[i]>j) tmp[j++] = ')';
                tmp[j++] = '(';
            }
            while(j<2*n) tmp[j++] = ')';
            result.push_back(string(tmp, 2*n));
            j = n-1;
            while(m[j]==2*j) j--;
        }
        return result;
    }
};