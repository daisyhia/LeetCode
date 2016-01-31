#include <vector>
using namespace std;
// 长度大的数列为m，长度小的数列为n
// 比较中间值，如果n的小，n砍掉前面n/2个数，m砍掉后面n/2个数，反之，n砍后面的m砍前面的
// 复杂度logn
// n没有n剩1个、n剩俩m剩偶数、n在m单边的情况单写了60行，估计揉吧揉吧可以十几行弄一个方法里，以后再弄吧
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 < 1) return medium(nums2, 0, size2 - 1);
        if(size2 < 1) return medium(nums1, 0, size1 - 1);
        if(size1 >= size2) return qSort(nums1, nums2, 0, size1-1, 0, size2-1);
        return qSort(nums2, nums1, 0, size2-1, 0, size1-1);
    }
    double qSort(vector<int> &a, vector<int> &b,  int aleft, int aright, int bleft, int bright) {
	int bn = bright - bleft;
	int an = aright - aleft;
	if(a[aright] <= b[bleft]) {
		if(an == bn) return (double)(a[aright] + b[bleft])/2;
		int size = an + bn + 2;
		if(size%2 == 0) {
			size /= 2;
			return (double)(a[aleft+size-1] + a[aleft+size])/2;
		} else {
			size /= 2;
			return a[aleft+size];
		}
	} 
	if(a[aleft] >= b[bright]) {
		if(an == bn) return (double)(a[aleft] + b[bright])/2;
		int size = an + bn + 2;
		if(size%2 == 0) {
			size /= 2;
			return (double)(a[aright-size] + a[aright-size+1])/2;
		} else {
			size /= 2;
			return a[aright-size];
		}
	}
	if(bn == 0) {
		double result = 0;
		if(an == 0) return double(a[aleft] + b[bleft])/2;
		if(an%2 == 0) {
			int ax = an/2 + aleft;
			if(b[bleft] < a[ax]) {
				if(b[bleft] < a[ax - 1]) result = a[ax] + a[ax - 1];
				else result = a[ax] + b[bleft];
			} else {
				if(b[bleft] > a[ax + 1]) result = a[ax] + a[ax + 1];
				else result = a[ax] + b[bleft];
			}
			return result/2;
		} 
		else {
			int ax = an/2 + aleft;
			if(b[bleft] <= a[ax]) return a[ax];
			else if(b[bleft] < a[ax + 1]) return b[bleft];
			else return a[ax + 1];
		}
	}
	if(bn==1 && an%2==1) {
		if(an==1 && b[bleft]<a[aleft]) return qSort(b, a, bleft, bright, aleft, aright);
		an/=2;
		if(b[bleft]>=a[an+aleft] && b[bleft] <=a[aleft+an+1]
			&& b[bright] >=a[aleft+an] && b[bright]<=a[aleft+an+1]) return (double)(b[bleft] + b[bright])/2;
        an*=2;
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
	return qSort(a, b, aleft, aright, bleft, bright);
	
}
    double medium(vector<int> v, int left, int right) {
	int size = right - left + 1;
	int n = size/2 + left;
	double result = 0;
	if(size%2 == 0) return (double)(v[n] + v[n-1])/2;
	return v[n];
}
};
