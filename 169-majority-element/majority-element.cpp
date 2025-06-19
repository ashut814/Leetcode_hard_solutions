class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                majority = nums[i];
                count++;
            } else{
                if(majority == nums[i]) count++;
                else count--;
            }
        }
        return majority;
    }
};


// [3,2,3]

// itr1:
// count = 0
// majority = 3
// count 1

// itr2:
// majority = 3
// nums[i] = 2
// count - 1 = 0

// itr3:

// majority = 3
// count = 1

