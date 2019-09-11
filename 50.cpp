// C++ program to find largest subarray sum with
// at-least k elements in it.
#include<bits/stdc++.h>
using namespace std;

int maxSumWithK(int a[], int n, int k)
{
    int maxSum[n];
    maxSum[0] = a[0];
    int curr_max = a[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        maxSum[i] = curr_max;
    }

    // Sum of first k elements
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];

    // Use the concept of sliding window
    int result = sum;
    for (int i = k; i < n; i++)
    {
        // Compute sum of k elements ending
        // with a[i].
        sum = sum + a[i] - a[i-k];

        // Update result if required
        result = max(result, sum);

        // Include maximum sum till [i-k] also
        // if it increases overall max.
        result = max(result, sum + maxSum[i-k]);
    }
    return result;
}

// Driver code
int main()
{
    int a[] = {1, 2, 3, -10, -3};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSumWithK(a, n, k);
    return 0;
}
