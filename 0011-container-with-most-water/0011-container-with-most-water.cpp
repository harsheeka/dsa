class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area = min(height[i],height[j])*(j-i);
        while(i<j){
            if(height[i]<height[j]){
                i++;
                if(i<height.size()) {int temp= min(height[i],height[j])*(j-i);
                area = max(temp,area);}
            }
            else{
                j--;
                if(j>0) {int temp= min(height[i],height[j])*(j-i);
                area = max(temp,area); }
            }
        }
        return area;
    } 
};