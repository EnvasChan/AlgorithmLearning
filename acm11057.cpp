#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int solve(int a,string b)
{
    int num = 0;

    if(b.size() == a)
    {
        return 0;
    }

    if(/*자릿수 비교해서 오림차순이면*/)
    {
        /*solve 함수로 b에 1을 증가시켜주며 num에 1을 더해준다
        ex) num = solve(a, b + 1) + 1;*/  
    }
    //solve(a, b + 1) 오름차수가 아니므로 그냥 넘겨준다 */

    return num;

}



int main()
{


}