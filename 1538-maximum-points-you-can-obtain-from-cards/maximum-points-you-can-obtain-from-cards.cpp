class Solution {
public:
    int totalSum(vector<int>&a){
        int n = a.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        return sum;
    }
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int total_sum = totalSum(a);

        if(k == n){
            return totalSum(a);
        }

        int subArraySum = 0, currentSum = 0;

        for(int i = 0 ; i < n-k; i++){
            currentSum += a[i];
        }

        subArraySum = currentSum;

        int i = 0 ,  j = n-k;
        while(j < n){
            currentSum += (a[j] - a[i]);
            subArraySum = min(subArraySum,currentSum);
            i++;
            j++;
        }
        return total_sum - subArraySum;
    }
};