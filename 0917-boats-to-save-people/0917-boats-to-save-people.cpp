class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,count=0;
        while(i<j){
            int sum = people[i]+people[j];
            if(sum<=limit){
                i++;
            }
            count++;
            j--;
        }
        return i==j ? count+1: count;
    }
    
};