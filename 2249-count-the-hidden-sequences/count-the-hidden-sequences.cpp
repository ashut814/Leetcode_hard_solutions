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