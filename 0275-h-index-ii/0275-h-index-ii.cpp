class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l=0, h=n-1,ans=0;
        while(l<=h){
            int m = l + (h-l)/2;
            if(citations[m]<(n-m)){
                l=m+1;
            }else{
                ans=max(ans,(n-m));
                h=m-1;
            }

        }
        return ans;
    }
};