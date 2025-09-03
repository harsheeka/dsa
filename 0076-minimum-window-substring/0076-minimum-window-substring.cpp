class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqS(256,0);
        vector<int> freqT(256,0);
        int distchar = 0;
        for(int i=0;i<t.length();i++){
            if(freqT[t[i]]==0) distchar++;
            freqT[t[i]]++;
        }
        int c=0,start=0,end;
        for(int i=0;i<s.length();i++){
            freqS[s[i]]++;
            if(freqS[s[i]]==freqT[s[i]]) c++;
            if(c==distchar){
                end=i;
                break;
            }
        }
        if(c<distchar) return "";
        int ansStart=start,ansEnd= end, minlength = end-start+1;
        while(end<s.length()){
            while(freqS[s[start]]>freqT[s[start]]){
                freqS[s[start]]--;
                start++;
            }
            if(end-start+1 < minlength){
                ansStart = start;
                ansEnd = end;
                minlength = end - start+1;
            }
            end++; 
            if(end<s.length()){
                freqS[s[end]]++;
            }
        }
        return s.substr(ansStart,minlength);
    }
};