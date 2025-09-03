class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();   
    vector<int> merged(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < m) merged[k++] = nums1[i++];
    while (j < n)  merged[k++] = nums2[j++];
    if (k % 2 == 1) {
        return merged[k / 2];
    } else {
        return (merged[(k - 1) / 2] + merged[k / 2]) / 2.0;
    }
    }
};