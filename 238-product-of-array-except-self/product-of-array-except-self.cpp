class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long overall_product = 0;
        long long product_without_zero = 1;
        int count_of_zero = 0;
        vector<int> result(n, 0);

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count_of_zero++;
                overall_product *= nums[i];
            } else {
                product_without_zero *= nums[i];
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0){
                if(count_of_zero > 0){
                    result[i] = 0;
                } else{
                    result[i] = product_without_zero / nums[i];
                }
            } else{
                if(count_of_zero > 1){
                    result[i] = 0;
                } else{
                    result[i] = product_without_zero;
                }
            }
        }

        return result;
    }
};