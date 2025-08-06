class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int l =0, h= n-1;
        if(n==1)return 0;
        while(l<=h){
            int m = l + (h-l)/2;
            if((m==0 || nums[m-1]<nums[m]) && (m==nums.size()-1 || nums[m+1]<nums[m])){
                return m;
            }
            else if(m < n-1 && nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};