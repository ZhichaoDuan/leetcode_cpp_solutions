class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m==0&&n==0) return ;
    while(m>0&&n>0) {
      if (nums2[n-1]>=nums1[m-1]){
        nums1[m+n-1]=nums2[n-1];
        n--;
      }
      else {
        int temp=nums1[m+n-1];
        nums1[m+n-1]=nums1[m-1];
        nums1[m-1]=temp;
        m--;
      }
    }
    for(int k=0;k<n;k++) {
      nums1[k]=nums2[k];
    }
  }
};
