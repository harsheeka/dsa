class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closestSum = nums[0]+nums[1]+nums[2];
        int minDiff = abs(target - closestSum);
        for(int i=0; i < nums.size() ; i++){
            int p1=i+1, p2= nums.size()-1;
            while(p1<p2){
                int temp = nums[i]+nums[p1]+nums[p2];
                int diff = abs(target - temp);
                if(diff<minDiff){
                    minDiff= diff;
                    closestSum = temp;
                }
                
                if(temp>target){
                    p2--;
                }
                else if(temp<target){
                    p1++;
                }
                else{
                    return closestSum;
                }
                
            }
        }
        return closestSum;
    }
};