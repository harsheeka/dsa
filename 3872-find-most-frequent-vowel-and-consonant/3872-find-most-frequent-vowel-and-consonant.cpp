class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int f1=0,f2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
                f1 = max(f1,freq[s[i]-'a']);
            }
            else{
                f2 = max(f2,freq[s[i]-'a']);
            }
        }
        return f1+f2;
    }
};