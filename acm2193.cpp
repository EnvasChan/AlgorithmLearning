#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

/*

이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.

len = 1
1

len = 2

10

len = 3
101, 100

len = 4

1001,  1010, 

len = 5

10100 10010 10101 10001

len  = 6 화가나는

101010 101001 100101 100010 

*/

int dp[91][2] = {0};

int solve2(int n, int befo, int after, string a)
{
    if (dp[befo][after] != 0)
    {
        return dp[befo][after];
    }


    int r = 0;
    dp[befo][after] = r;
}

int solve(int n , string a)
{

    int b = 0;
    
    if(n==1 || n == 2)
    {
        return 1;
    }

    if (a.size() == n)
    {
        cout << a << endl;
        return 1;
    }
        
   
    if(a.size() == 0)
        a.push_back('1');

    int r1 = 0;
    if (a.back() == '0')
    {
        r1 = solve(n, a + '1' );
        //dp[a.size()][1] = r1;
    }
        
    int r2 = solve(n, a + '0');
    //dp[a.size()][0] = r2;
    b = r1 + r2;
    return b;

}

int main()
{
    int num = 0;

    cin >> num;

    cout << solve(num,"");

    return 0;
}