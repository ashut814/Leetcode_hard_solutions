class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_till = INT_MIN;
        int chunks = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            max_till = max(arr[i],max_till);

            if(max_till == i){
                chunks++;
            }
        }
        return chunks;
    }
};