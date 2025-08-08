class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, h = nums.size()-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]==target){
                return true;
            }
            else if(nums[m]==nums[l] && nums[m]==nums[h]){
                //basically to avoid the case where we cant tell if the right part is sorted or left
                l++;
            }
            else if(nums[m]>=nums[l]){
                //left sorted 
                if(target>=nums[l] && target<nums[m]){
                    h=m-1;
                    //if target is in the left sorted space then discard the right pile
                }
                else l=m+1;
            }
            else if(nums[m]<=nums[h]){
            //right sorted
            if(target>nums[m] && target<=nums[h]){
                l=m+1;
                //discard the left half
            }
            else h=m-1;
            }
        }
        return false;
        
       
    }
};