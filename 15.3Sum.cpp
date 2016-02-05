#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int size = nums.size();
        if(size<3) return result;
        sort(nums.begin(), nums.end());
        if(nums[0]>0||nums[size-1]<0) return result;
        int i = 0;
        while(nums[i]<=0&&i<size-2) {
            int j = i+1;
            int k = size-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0) {
                    result.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    while(nums[j]==nums[++j]) {}
                    while(nums[k]==nums[--k]) {}
                } 
                else if(sum>0) while(nums[k]==nums[--k]) {}
                else while(nums[j]==nums[++j]) {}
            }
            while(nums[i]==nums[++i]) {}
        }
        return result;
    }
};