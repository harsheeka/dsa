/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p,n=mountainArr.length();
        int l=0,h=n-1;
        while (l < h) {
    int m = (l + h) / 2;
    if (mountainArr.get(m) < mountainArr.get(m + 1)) l = m + 1;
    else h = m;
}
p = l;

        l=0,h=p;
        while(l<=h){
            int m = l + (h-l)/2;
            if(mountainArr.get(m)==target){
                return m;
            }
            else if(mountainArr.get(m)> target){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=p+1,h=n-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(mountainArr.get(m)==target){
                return m;
            }
            else if(mountainArr.get(m)> target){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};