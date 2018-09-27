class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]) i++;
            else {
                nums1.erase(nums1.end()-1);
                nums1.insert(nums1.begin()+i, nums2[j]);
                m++;
                i++;
                j++;
            }
        }
        if(j<n){
            nums1.erase(nums1.end()-(n-j), nums1.end());
            nums1.insert(nums1.begin()+i, nums2.begin()+j, nums2.end());
        }
    }
};
