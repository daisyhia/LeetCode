#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int max = 0;
        for(int j=0;j<size;j++) {
            if(height[j] <= left) continue;
            left = height[j];
            int right = height[size-1];
            for(int i=size-1;i>j;i--) {
                if(height[i]>=height[j]) {
                    max = getMax(height[j]*(i-j), max);
                    break;
                }
                if(height[i]>=right) {
                    right = height[i];
                    max = getMax(height[i]*(i-j), max);
                }
            }
        }
        return max;
    }
    int getMax(int i, int j) {
        return i>j?i:j;
    }
};