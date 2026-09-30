#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int middle_int = (nums1.size() + nums2.size())/2.0;
        if  ((nums1.size() + nums2.size())%2 != 0)
        {
            middle_int = (nums1.size() + nums2.size() + 1)/2;
        }
        int i = 0,j = 0,k = 0;
        double it ,next;
        while (k < middle_int )
        {
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] < nums2[j])) {
                it = nums1[i++];
            } else {
                it = nums2[j++];
            }
            
            k++;
            
        }
        if ((nums1.size() + nums2.size())%2 == 0)
        {
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] < nums2[j])) {
                next = nums1[i];
            } else {
                next = nums2[j];
            }
            it = (it + next)/2.0;
        }
        
        return it;
        
    }
};