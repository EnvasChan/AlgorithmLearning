
#include <iostream>
#include <array>
#include <queue>

using namespace std;

// 연산을 하는 횟수를 구해주는 함수
// void: 없다

// 끝나는 조건! n = 1 일때 반복한 횟수
// 반복하는 조건 (부분 문제)

int a, b, c = 0;

int solve(int n = 0)
{
    int a;
    if (n == 1)
        return 0; // 싸이감성;

    a =  solve(n-1) + 1;

    if(n%3 == 0)
    a = min(solve(n/3) + 1, a);

    if(n%2 == 0)
    a = min(solve(n/2) + 1,a);
    //괘씸하네요
    return a;
}


int main()
{
    int count = 0;
    int n = 0;

    cin >> n;

    
    
    cout << solve(n);


    return 0;
}