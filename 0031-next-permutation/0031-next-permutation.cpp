class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = nums.size()-1;
        while(x>0 && nums[x]<=nums[x-1]){
            x--;
        }
        if(x-1>=0){
            int y = nums.size()-1;
            while(y>=x){
                if(nums[y]>nums[x-1]){
                    swap(nums[x-1],nums[y]);
                    break;
                }
                y--;
            }
        }
        int i=x,j=nums.size()-1;
        while(j>i){
            swap(nums[i],nums[j]);
            i++,j--;
        }
        return;
    }
};