class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0; 
		int size = 1;
		int ssize = s.length();
		if(ssize < 1) return 0;
		int max = 0;
		for(int k = 1; k < ssize; k++) {
			string sub = s.substr(start, size);
			int i = sub.find(s.at(k));
			if(i != -1) {
				max = max > size ? max : size;
				start += i + 1;
				size = k - start + 1;
			} else {
				size++;
			}
		}
		return max > size ? max : size;
	}
}
