#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;
// 위 : x , y + 1 오른쪽 x +1, y  아래 x, y -1 왼쪽 x -1 , y
//x :0 1 0 -1
//y :1 0 -1 0
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[102][102] = {0};
bool visited[102][102] = {false}; //안간거면 FALSE 간거면 TRUE
int n = 0;
int m = 0;

int solve(int x,int y)// 이 함수가 리턴해 주는것은? n,m에서부터 x,y까지 거쳐온 칸들의 수를 출력 
{
    visited[x][y] = true;
    int num = 2100000000;
    if(x == m && y == n)
    {
        return 1;
    }

    for(int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(visited[x + dx[i]][y + dy[i]] == false && map[x + dx[i]][y + dy[i]] == 1)
        {
            visited[x + dx[i]][y + dy[i]] = true;
            num = min(solve(x + dx[i],y + dy[i]) + 1,num);
            visited[x + dx[i]][y + dy[i]] = false;
        }
    }

    return num;
}

int main()
{
    
    cin >> n >> m;
    string line;
    for(int i = 1; i <= n; i++)
    {
        cin >> line;
        for(int j = 1; j <= m; j++)
        {
            map[j][i] = line[j-1] - '0';
        }
    }

    cout << solve(1,1);

    return 0;
}