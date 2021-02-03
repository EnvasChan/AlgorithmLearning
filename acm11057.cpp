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
 


*/
int solve(int prev, int current, int n)
{
  // ...
  int sum = 0;

  if(current == n)
  {
    return 1;
  }

  for (int i=prev; i<10; i++)
  {
    sum += solve(i, current+1, n);
  }

  return sum;
  // ...
}



int main()
{


}