class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int k = n/3;
        for(int i =k; i < n ; i+=2){
            sum += nums[i];
        }
        return sum;
    }
};
