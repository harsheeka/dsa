class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if((m==0 || arr[m-1]<arr[m]) && (m==n-1 || arr[m]> arr[m+1])){
               return m;
            }
            else if(m==n-1 || arr[m]> arr[m+1]){
                h=m-1;
            }
            else {
                l=m+1;
            }
        }
        return -1;
    }
};