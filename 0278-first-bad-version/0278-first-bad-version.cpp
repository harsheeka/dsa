// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,h= n;
        while(l<=h){
            int m = l + (h-l)/2;
            if(isBadVersion(m)){
                if(m==1){
                    return 1;
                }
                else if(!isBadVersion(m-1)){
                    return m;
                }
                else{
                    h=m-1;
                }
            }
            else{
                l=m+1;
            }
        }
        return 1;
    }
};