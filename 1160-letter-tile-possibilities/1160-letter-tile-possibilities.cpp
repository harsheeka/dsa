class Solution {
public:
    void permutate(string& temp, int& count, int index) {
        if(index==temp.length()-1){
            count++;
            return;
        }
        vector<int> freq(26,0);
        for(int i=index;i<temp.size();i++){
            if(freq[temp[i]-'A']==0){
                swap(temp[i],temp[index]);
                permutate(temp,count,index+1);
                swap(temp[i],temp[index]);
            }
            freq[temp[i]-'A']++;
        }

    }
    void res(int& count, string& tiles, string& temp, int level) {
        for (int i = level; i < tiles.length(); i++) {
            if (i > level && tiles[i] == tiles[i - 1])
                continue;
            temp.push_back(tiles[i]);
            permutate(temp, count,0);
            res(count, tiles, temp, i + 1);
            temp.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int count = 0;
        string temp;
        res(count, tiles, temp, 0);
        return count;
    }
};