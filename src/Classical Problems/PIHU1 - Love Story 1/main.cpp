#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_RANGE       1001

int solve(long long* a, int* checked, int n, long long p);
int isPairSum(long long* a, int* checked, int n, long long sum);

int isPairSum(long long* a, int* checked, int n, long long sum)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (checked[left])
        {
            left++;
        }
        if (checked[right])
        {
            right--;
        }

        if (a[left] + a[right] == sum && left != right)
        {
            return 1;
        }
        else if (a[left] + a[right] < sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return 0;
}

int solve(long long* a, int* checked, int n, long long p)
{
    int found = 0;
    long long sum;

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        checked[i] = 1;
        sum = p - a[i];
        if (sum < 0)
        {
            break;
        }
        if (isPairSum(a, checked, n, sum))
        {
            found = 1;
            break;
        }
        else
        {
            checked[i] = 0;
        }
    }

    return found;
}

int main()
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        long long a[MAX_RANGE], p;
        int checked[MAX_RANGE];

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        cin >> p;

        memset(checked, 0, n);

        if (solve(a, checked, n, p))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
