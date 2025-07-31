class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count_1 = 0;
        int count_2 = 0;
        int majority_1 = INT_MIN, majority_2 = INT_MIN;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == majority_1){
                count_1++;
            } else if(nums[i] == majority_2){
                count_2++;
            } else if(count_1 == 0){
                majority_1 = nums[i];
                count_1 = 1;
            } else if(count_2 == 0){
                majority_2 = nums[i];
                count_2 = 1;
            } else{
                count_1--;
                count_2--;
            }
        }
        vector<int> majority;

        int freq_1 = 0, freq_2 = 0;
        for(int num : nums){
            if(num == majority_1) freq_1++;
            else if(num == majority_2) freq_2++;
        }
        if(freq_1 > n / 3) majority.push_back(majority_1);
        if(freq_2 > n / 3) majority.push_back(majority_2);

        return majority;
    }
};