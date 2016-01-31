class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
        	int other = target - nums.at(i);
        	if(m[other] != NULL) {
        		result.push_back(m[other]);
        		result.push_back(i + 1);
        	} else {
        		m[nums.at(i)] = i + 1;
        	}	
        		
        }
        return result;
    }
};
