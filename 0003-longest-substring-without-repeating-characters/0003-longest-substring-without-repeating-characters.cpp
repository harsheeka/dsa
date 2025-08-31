class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=0,j=0,ans=1;
        vector<int> freq(257,0);
        freq[s[0]]++;
        while(j<s.length()-1){
            if(freq[s[j+1]]==0){
                j++;
                freq[s[j]]++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};