#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int a[100001] = {0};
int b[100001] = {0};
int n , m = 0;

int solve(int num1)
{
    int num = 0;

    for(int j = 0; j < m;j++)
    {
        if(b[num1] == a[j])
        {
            num = max(num, solve(j) + 1);
        }
    }

    return num;
}

int main()
{
    
    vector<int> sort1;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int n1= 0;
        int m1 = 0;

        cin >> n1 >> m1;
        a[i] = n1;
        b[i] = m1;
    } 

    cout << solve(1);

    return 0;
}