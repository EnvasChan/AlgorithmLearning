#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;
int dp[275] = {0};

int main()
{
    return 0;
}
/*
n = 4
    1+1+1+1
    1+1+2
    1+2+1
    2+1+1
    2+2
    1+3
    3+1
n = 5
    1+1+1+1+1
    1+1+1+2
    ... 1과 2의 조합 4개
    1+1+3
    ... 1과 3의 조합 3개
    2+3
    ... 2개


*/


/*
int acm9095(int n)
{

    dp[0] = 1;
    for (int i=0; i<n; i++)
    {
        for (int j=1; j<=3; j++)
        {
            if ( ? ) continue;
            dp[i] += dp[ ? ];
        }
    }



}


int main()
{
    int n = 0;
    cin >> n;
    cout << acm9095(n);
}
*/