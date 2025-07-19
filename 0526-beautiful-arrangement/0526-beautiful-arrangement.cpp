class Solution {
public: 
    void perm(vector<int>& temp, int index, int &count, int &n){
        if(index==n){
            count++;
            return;
        }
        for(int i=index;i<n;i++){
            swap(temp[i],temp[index]);
            int pos = index+1;
            if(temp[index]%(pos)==0 || pos%temp[index]==0){
                 perm(temp,index+1,count,n);
            }
            swap(temp[i],temp[index]);
        }
    }
    int countArrangement(int n) {
        int count =0;
        vector<int> temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        perm(temp,0,count,n);
        return count;
    }
};