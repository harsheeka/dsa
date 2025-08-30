class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                long long r = nums[i]+nums[j];
                long long sum = target - r;
                int p1 = j+1, p2= nums.size()-1;
                while(p1<p2 ){
                    if(nums[p1]+nums[p2]> sum){
                        p2--;
                    }
                    else if(nums[p1]+nums[p2]<sum){
                        p1++;
                    }
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[p1]);
                        temp.push_back(nums[p2]);
                        ans.push_back(temp);
                        int x= nums[p1], y= nums[p2];
                        while(p1 < nums.size() && nums[p1]==x) p1++;
                        while(p2>=0 && nums[p2]==y) p2--;
                    }
                }

            }
        }
        return ans;
    }
};