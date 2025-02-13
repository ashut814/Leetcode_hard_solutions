class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char,int>mp;
        for(char &ch : t){
            mp[ch]++;
        }

        int reqSize = t.length();
        int i = 0, j = 0;
        int minWindow = INT_MAX;
        int minStart = 0; 
        while(j < n){
            char ch_j = s[j];
            if(mp[ch_j] > 0)
                reqSize--;
            mp[ch_j]--;
            while(reqSize == 0){
                if(minWindow > j-i+1){
                    minWindow = j-i+1;
                    minStart = i;
                }
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0)
                    reqSize++;
                i++;
            }
            j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(minStart,minWindow);
    }
};
