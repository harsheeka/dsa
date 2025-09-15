class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> freq(26,0);
        for(int i=0;i<brokenLetters.length();i++){
            freq[brokenLetters[i]-'a']++;
        }
        int j=0,count=0;
        while(j<text.length()){
            bool flag=false;
           while(j<text.length() &&text[j]!=' '){
            if(freq[text[j]-'a']==1){
                flag = true;
            }
            j++;
           }
           if(!flag) count++;
           if(j < text.length() && text[j] == ' ') j++;
        }
        return count;
    }
};