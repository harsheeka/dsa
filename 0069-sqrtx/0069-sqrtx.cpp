class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        while(l<=h){
            long long m= l + (h-l)/2;
            if(m*m>x){
                h=m-1;
            }else{
                if((m+1)*(m+1)>x){
                    return m;
                }
                else l=m+1;
            }
        }
        return -1;
    }
};