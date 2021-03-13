#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

// solve(0, 0,  n);
//
/*
0 0 n
  0 1 n
    0 2 n
    return
    1 2 n
    return
    2 2 n
    return
    
  1 1 n
    1 2 n
    return
  2 1 n
 
0 0 3
  0 1 3
    0 2 3 -> return 10
      0 3 3 -> return 1 
      1 3 3 ->
      2 3 3 ->
      ...
      9 3 3 
    1 2 3
      1 3 3
      2 3 3
      ...
      9 3 3
    2 2 3
      2 3 3
      3 3 3
      ...
      9 3 3

  1 1 3
    1 2 3
      
    2 2 3






*/

//sum이란 변수는 그저 solve함수에 값을 넣어주는 용도


int dp[10][1001] = {0};



int solve(int prev, int current, int n)
{
  // ...
  int sum = 0;
  // 저장되어있는지 확인
  // 꺼내기
  if (dp[prev][n-current] != 0)
  {
    return dp[prev][n-current];
  }

  if(current == n)
  {
    return 1;
  }

  for (int i=prev; i<10; i++)
  {
    sum += solve(i, current+1, n);
    
  }
  dp[prev][n-current] = sum;
  return sum;
  // ...
}



int main()
{
    int n = 0;
    cin >> n;
    cout << solve(0,0,n);
    return 0;

}