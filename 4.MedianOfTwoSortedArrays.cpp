#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        if(size%2==1) {
            if(size1 > size2) return qSort(nums1, nums2, 0, size1-1, 0, size2-1, size/2);
            return qSort(nums2, nums1, 0, size2-1, 0, size1-1, size/2);
        } else {
            if(size1 > size2) return (qSort(nums1, nums2, 0, size1-1, 0, size2-1, size/2-1) + qSort(nums1, nums2, 0, size1-1, 0, size2-1, size/2))/2.0;
            return (qSort(nums2, nums1, 0, size2-1, 0, size1-1, size/2-1) + qSort(nums2, nums1, 0, size2-1, 0, size1-1, size/2))/2.0;
        }
    }
	double qSort(vector<int> &a, vector<int> &b,  int aleft, int aright, int bleft, int bright, int i) {
    	int bn = bright - bleft;
    	int an = aright - aleft;
    	if(bn<0) return a[i+aleft];
    	if(bn==0) {
    	    if(i>an) return a[aright]>b[bleft] ? a[aright]:b[bleft];
    	    if(a[i+aleft]<b[bleft]) return a[i+aleft];
    	    else if(i==0 || a[i+aleft-1]<b[bleft]) return b[bleft];
    	    else return a[i+aleft-1];
    	}
    	if(a[aright] <= b[bleft]) return an>=i ? a[i+aleft] : b[bleft];
	    if(a[aleft] >= b[bright]) return bn>=i ? b[bright] : a[aleft+i-bn-1];
    	if(bn==1 && an%2==1) {
    		if(an==1 && b[bleft]<a[aleft]) return qSort(b, a, bleft, bright, aleft, aright, i);
    		if(b[bleft]>=a[aleft+an/2] && b[bright]<=a[aleft+an/2+1]) return b[bleft+i-an/2-1];
    	}
    	bn /= 2;
    	an /= 2;
    	int bv = b[bn + bleft];
    	if(bn==0) bn=1;
    	if(bv <= a[an + aleft]) {
    		bleft += bn;
    		aright -= bn;
    	} else {
    		aleft += bn;
    		bright -= bn;
    	}
    	return qSort(a, b, aleft, aright, bleft, bright, i-bn);
    }
};
