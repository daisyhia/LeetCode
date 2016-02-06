class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int size = nums.size();
        if(size<4) return result;
        sort(nums.begin(), nums.end());
        int i = 0;
        int ir = size-3;
        while(i<ir&&nums[i]+nums[i+1]+nums[i+2]+nums[i+3]<=target) {
            int it = target - nums[i];
            int j = i+1;
            int jr = size-2;
            while(j<jr) {
                int jt = it - nums[j];
                int k = j+1;
                int t = size-1;
                while(k<t) {
                    int sum = nums[k]+nums[t];
                    if(sum==jt) {
                        result.push_back(vector<int>{nums[i],nums[j],nums[k],nums[t]});
                        while(nums[k]==nums[++k]) {}
                        while(nums[t]==nums[--t]) {}
                    } else if(sum>jt) {
                        while(nums[t]==nums[--t]) {}
                        ir = t-1;
                        jr = t;
                    } else while(nums[k]==nums[++k]) {}
                }
                while(nums[j]==nums[++j]) {}
            }
            while(nums[i]==nums[++i]) {}
        }
    }
};