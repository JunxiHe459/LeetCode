class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // largest element in nums1
        int i = m - 1;
        // largest element in nums1
        int j = n - 1;
        // start position of the largest element after merge
        int idx = m + n - 1;

        while( idx >= 0)
        {
            // If run out of elements in nums1
            if(i == -1)
            {
                nums1[idx] = nums2[j];
                idx--;
                j--;
                continue;
            }
            
            // If run out of elements in nums2
            if(j == -1)
            {
                nums1[idx] = nums1[i];
                idx--;
                i--;
                continue;
            }
            
            // Normal case
            if(nums1[i] > nums2[j])
            {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else
            {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
    }
};