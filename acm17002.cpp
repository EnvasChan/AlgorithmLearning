#include <iostream>
#include <array>
#include <queue>

using namespace std;

// 끝나는 조건


/*
4
    1
        0 r
    2
        0 r
        1
            0 r
        r
    r
    3
        0 r
        1
            0 r
        r
        2
            0 r
            1
                0 r
            r
        r
    r
3
    0r
    2
        0r
        1
            0r
        


*/

int b = 0;
long long dp[1001] = { 0 };

// f(n) = f(n-1) + f(n-2) + f(n-3)
// f(10) = f(7) + f(8) + f(9)
// f(n) = f(n-3) + f(n-2) + f(n-1)
long long solve(int n )
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