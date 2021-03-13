#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int dp[10000] = {0};

// recursive (재귀)
int fibonacci(int f = 0)
{
    if(dp[f] != 0)
    {
        return dp[f];
    }

    if(f == 0)
    {
        return 0;
    }

    if(f == 1)
    {
        return 1;
    }

    dp[f] = fibonacci(f -1) + fibonacci(f - 2);

    return dp[f];
}

// non-recursive (재귀아님)
int fibonacci2(int f)
{
    int fib[10000] = {0};
    fib[1] = 1;
    fib[2] = 1;
    for (int i=3; i<=f; i++)
    {
        fib[i] = fib[i -1] + fib[i - 2];
    }

    return fib[f];
}



int main()
{
    int n = 0;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}