class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 0 ; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};


// [1,1,2]

// i = 0;

// nums[i] != nums[j] then count++ and nums[i] = nums[j]

//  nums[0] != nums[0] -> false
// nums[0] != nums[1] =>  -> 
