class Solution {
  public:
    bool allZeros(vector<int> &counter){
        for(auto & i : counter){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
       int n = txt.length();
       int k = pat.length();
       vector<int> counter(26,0);
       
       // count the frequency of each letter in the pat
        for(char &ch : pat) {
            counter[ch-'a']++;
        }
       
       int i = 0,j = 0;
       int ans = 0;
       while(j < n){
           int idx = txt[j]-'a';
	       counter[idx]--;
           if(j-i+1 == k){
               if(allZeros(counter)){
                   ans++;
               }
                counter[txt[i]-'a']++;
	            i++;
           }
           j++;
       }
       return ans;
    }
};
