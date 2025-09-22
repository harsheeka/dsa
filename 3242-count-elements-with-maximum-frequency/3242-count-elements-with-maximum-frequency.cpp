class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq (101,0);
        int max_freq=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            max_freq = max(max_freq, freq[nums[i]]);
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==max_freq){
                count++;
            }
        }
        return count;
    }
};