#include <iostream>
#include <array>
#include <queue>

using namespace std;

// 끝나는 조건

int b = 0;
long long dp[1001] = { 0 };

long long solve(int n = 0)
{
    long long a = 0;

    if (dp[n] != 0)
    {
        return dp[n];
    }

    if (n == 0)
    {
        return 1;
    }

    if (n - 3 >= 0)
    {
        a += solve(n - 3);

    }

    if (n - 2 >= 0)
    {
        a += solve(n - 2);
    
    }

    if (n - 1 >= 0)
    {
        a += solve(n - 1);
    }

    dp[n] = a;

    return a;
}

int main()
{
    int n = 0;

    cin >> n;

    

    cout << solve(n);
    return 0;
}