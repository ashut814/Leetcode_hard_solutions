class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefixSum = 0;
        long long minPrefixSum = 0;
        long long maxPrefixSum = 0;

        for (int diff : differences) {
            prefixSum += diff;
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        long long minX = lower - minPrefixSum;
        long long maxX = upper - maxPrefixSum;

        return max(0LL, maxX - minX + 1);
    }
};


// differences[i] = hidden[i+1] - hidden[i]
// differences = [2, -1, 3]
// hidden[1] is 2 more than hidden[0]
// hidden[2] is 1 more than hidden[1]
// hidden[3] is 2 more than hidden[2]
// lets say hidden[0] = x
// hidden[1] = x + 2 => because difference[0] = 2
// hidden[2] =  (x+2) - 1 = x + 1 =>  // because difference[1] = -1
// hidden[3] = (x+1) + 3 = x + 4 =>  because difference[2] = 3

// so now hidden array is : [x, x + 2, x + 1, x + 4]


// prefixSum = [0,1,-2,2]

// hidden[i] = x + prefix[0]

// minPrefix = -2;
// maxPrefix = 2

// 1 <= x -2 => x >= 3
// 6 >= x + 2 => x <= 4
// x E [3,4]
// ans = 4-3+1 => 2

