// C++ program to find largest subarray sum with
// at-most k elements in it.
#include<bits/stdc++.h>
using namespace std;

// Returns maximum sum of a subarray with at-least
// k elements.
void maxSumWithK(int a[], int n, int k)
{
    int curr_max = a[0];
    for (int i = 1; i < k; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
    }

    int max_so_far = curr_max, max_ending_here = curr_max;

    for (int i=k; i< n; i++ )
    {
        max_ending_here += a[i];
        max_ending_here -= a[i-k];
        curr_max = max(a[i],max_ending_here);
        if (max_so_far < curr_max)
        {
            max_so_far = curr_max;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
}
// Driver code
int main()
{
    int a[] = {-1, 2, 3, 10, -3, -7, 5, 4, -8, 9};
    int k = 2;
    int n = sizeof(a)/sizeof(a[0]);
    maxSumWithK(a, n, k);
    return 0;
}
