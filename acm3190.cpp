#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>

using namespace std;

//일정시간마다 꼬리가 늘어난다
//사과 먹으면 꼬리가 늘어남
//못먹으면 그대로
//1번째 입력은 판의 크기 n * n 인듯
//2번째는 사과의 개수
//3번째 입력은 사과의 x좌표
//4번째 입력은 사과의 y좌표
// * 사과의 위치는 모두 다름
// (0,0) 좌표에는 사과가 없음
// X 와 C를 입력함
//X는 일정시간마다 방향을 꺽는 시간 C값은 방향(L이면 왼쪽 D면 오른쪽)

//방향을 꺾을때 꺽는 방향을 신경써야함

//대가리의 방향을 생각해야함

//이중배열에서 왼쪽이 세로 오른쪽이 가로임 - 주의

// 머리가 오른쪽이면 오른쪽으로 꺾는건 아래 왼쪽은 위 머리가 왼쪽이면 반대 머리가 위 아래면 괜찮음

int head_direction = 0;//머리의 방향 //0이면 오른쪽 1이면 아래 2면 왼쪽 3이면 위
int apple = 0;// 사과의 개수
int map[101][101] = { 0 }; // 맵크기
int tim[101] = { 0 };//시간
int n = 0;
struct cor
{
    int x = 0;
    int y = 0;
};
deque<cor> tails;
int c = 0; // 횟수
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, 0-1};
char l[101] = { 0 };
cor a;

int solve(int x, int y , int during ,int t) // during은 몇번째 움직인건지
{
    int num = 0;
    a.x = x;
    a.y = y;
   
    //cout << "Debug Value" << x << y << endl;

    for (int i = 0; i < tails.size(); i++) // 지몸에 꼴아 박으면 죽는다
    {
        if (x == tails[i].x && y == tails[i].y)
        {
            return t;
        }
    }

    if (x < 0 || y < 0 || x>= n || y >=n)
    {
        return t;
    }


    if (map[y][x] == 2) // 사과를 먹는지
    {
        //cout << " Debug Value : " << "음~ 맛있다~" << endl;
        map[y][x] = 1;
    }
    else
    {
        tails.pop_back(); // 사과 안먹으면 꼬리 박살냄
    }

    tails.push_front(a);


    if (t == tim[during])//꺾는 코드
    {
        if (l[during] == 'L')
        {
            head_direction -= 1;
            if (head_direction > 3)
            {
                head_direction = 0;
            }
            if (head_direction < 0)
            {
                head_direction = 3;
            }
            int new_x = x + dx[head_direction];
            int new_y = y + dy[head_direction];
          
            return solve(new_x, new_y, during + 1, t + 1);

        }
        else
        {
            head_direction += 1;
            if (head_direction > 3)
            {
                head_direction = 0;
            }
            if (head_direction < 0)
            {
                head_direction = 3;
            }
            int new_x = x + dx[head_direction];
            int new_y = y + dy[head_direction];
            
 
            return solve(new_x, new_y, during + 1, t + 1);
        }
    }

    int new_x = x + dx[head_direction]; // 그냥 앞으로 한칸 가는거
    int new_y = y + dy[head_direction];

    return solve(new_x, new_y, during, t + 1);
}

int main()
{ 
    
    cin >> n; // 판 크기 정하기

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 1; // 지렁이 게임의 맵으로 쓰일 만큼의 공간을 1로 설정 그외 영역은 0 즉 0은 벽을 의미
        }
    }

    cin >> apple;

    for (int i = 0; i < apple; i++)
    {
        int x, y = 0;
        cin >> y >> x;
        map[y - 1][x -1 ] = 2; //사과가 잇는 영역을 2로 설정

    }

    cin >> c;

    for (int i = 0; i < c; i++)//꺾는 시간이랑 꺾는 방향 입력
    {
        int a = 0;
        char b = 0;
        cin >> a;
        cin >> b;
        tim[i] = a;
        l[i] = b; 
    }

    a.x = 0;
    a.y = 0;
    tails.push_front(a);

    cout << solve(1, 0, 0,1);



    return 0;
}