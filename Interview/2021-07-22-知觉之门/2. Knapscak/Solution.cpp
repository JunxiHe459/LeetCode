class Solution
{
    int Knapsack(vector<int> arr, int maxCapacity)
    {
        int DP[arr.size() + 1][maxCapacity + 1];

        // Iterate through the 2d array, DP
        for(int i = 0; i <= arr.size(); i++)
        {
            for(int j = 0; j <= maxCapacity; j++)
            {
                // i = 0 means there is no item covered in arr 
                // so dp[i][j] should be 0
                // j = 0 means that the maxCapacity allowed is 0
                // so nothing should be put, dp[i][j] should be 0
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                // idx means which item we are looking at in the arr.
                int idx = i - 1;
                // If the item we are going to put is not big enough to outweight the maxCapacity
                if(arr[idx] <= maxCapacity)
                {
                    // This line is the key of the DP
                    // It says that if the dp[i][j] should be the max of 2 possiblities
                    // 1.
                    // dp[i - 1][j - arr[i - 1]] means that we take the i-th item in the arr,
                    // so now the total value is the max value of the value of i-th item +
                    // selcting from 1-th to (i-1)-th item in the arr with maxCpacity at maxCapacity - the value of i-th item
                    // 2.
                    // the max value can be dp[i - 1][j] which means that selcting 
                    // from 1-th to (i-1)-th item in the arr with maxCpacity not changed.
                    dp[i][j] = max(dp[idx - 1][j - arr[idx]] + arr[idx], dp[idx - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[idx - 1][j];
                }
            }
        }
    }
}