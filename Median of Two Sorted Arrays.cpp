//Question 4.Median of Two Sorted Arrays Leetcode
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size() + nums2.size()) & 0x1) {
            return findKthInSortedArrays(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,(nums1.size()+nums2.size())/2+1);
        } else {
            int tmp1 = findKthInSortedArrays(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,(nums1.size()+nums2.size())/2);
            int tmp2 = findKthInSortedArrays(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,(nums1.size()+nums2.size())/2+1);
            return (tmp1+ tmp2)/2.0;
        }
        return 0;

    }

    int findKthInSortedArrays(vector<int>& nums1,int s1,int f1, vector<int>&nums2, int s2, int f2, int k) {

        if(f1-s1<f2-s2) {
            return findKthInSortedArrays(nums2,s2,f2,nums1,s1,f1,k);
        }
        if(f1-s1 < 0) {
            return nums2[s2+k-1];
        }
        if(f2-s2<0) {
            return nums1[s1+k-1];
        }
        if(1 == k) {
            return min(nums1[s1],nums2[s2]);
        }
        int p2 = min(k/2, f2-s2+1);
        int p1 = k-p2;
        int tmp1 = s1+p1-1;
        int tmp2 = s2+p2-1;
        if(nums1[tmp1] < nums2[tmp2]) {
            return findKthInSortedArrays(nums1,s1+p1,f1,nums2,s2,f2,k-p1);
        } else if (nums1[tmp1] > nums2[tmp2]) {
            return findKthInSortedArrays(nums1,s1,f1,nums2,s2+p2,f2,k-p2);
        } else {
            return nums1[tmp1];
        }

    }

};
