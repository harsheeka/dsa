class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                i++,j--;
            }
            while(i<nums.size() && nums[i]!=val){
                i++;
            }
            while(j>=0 && nums[j]==val){
                j--;
            }
        }
        int cnt=nums.size();
        for(int k=nums.size()-1; k>=0;k--){
            if(nums[k]!=val){
                break;
            }
            else{
                cnt--;
            }
        }
        return cnt;
    }
};