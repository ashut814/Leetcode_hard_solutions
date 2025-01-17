class Solution {
public:
    bool allZeros(vector<int>&counter){
        for(auto &it : counter){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        vector<int>counter(26,0);
        for(char &ch : p){
            counter[ch-'a']++;
        }

        int i = 0, j = 0;
        vector<int>ans;
        while(j < n){
            counter[s[j]-'a']--;
            if(j - i + 1 == k){
                if(allZeros(counter)){
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};

// tc -> O(n)
