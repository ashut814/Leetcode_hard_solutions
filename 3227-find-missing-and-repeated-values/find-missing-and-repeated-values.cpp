class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1, repeat = -1;


        unordered_map<int,int>freq;
        for(auto &row : grid){
            for(int num : row){
                freq[num]++;
            }
        }

        for(int i = 1; i <= n*n ; i++){
            if(!freq.count(i)){
                missing = i;
            } else if(freq[i] == 2){
                repeat = i;
            }
        }

        return {repeat,missing};
    }
};