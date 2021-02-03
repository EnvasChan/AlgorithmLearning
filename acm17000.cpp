#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

struct job
{
    int priority = 0;
    int start_time = 0;
    char c = 0; 
    
};

struct worker
{
    int speed = 0;
    char color = 0;
    int priority = 0;
    int available_time = 0;
};

struct compare
{
bool operator()(job lhs, job rhs)
{
    return lhs.priority > rhs.priority;
}
};

int main()
{
   

    int a = 0;//상민 속도
    int b = 0;//지수 속도
    int c= 0;//손님 수

    worker sangmin;
    worker jisu;
    job umu[1001];
    priority_queue<job, vector<job>, compare> pq;
    vector<int> sangmin_s;
    vector<int> jisu_s;

    sangmin_s.reserve(100001);
    jisu_s.reserve(100001);

    cin >> a >> b >> c;
    sangmin.speed = a;
    jisu.speed = b;

    sangmin.priority = 0;
    sangmin.color = 'B';
    jisu.priority = 1;
    jisu.color = 'R';
    
    for(int i = 0; i < c; i++)
    {
        int d, f;
        char e;

        cin >> d >> e >> f;

        //umu[i].c = e;
        //umu[i].start_time = d;

        if(e == sangmin.color)//상민
        {
            if(d < sangmin.available_time)
            {
                d = sangmin.available_time;
            }
            // 5 7 9 
            // 5 7 19
            for(int j = 0; j < f; j++)
            {
                int start_time = d + j * sangmin.speed;
                job jo;
                jo.priority = start_time * 2 + sangmin.priority;
                jo.c = e;
                pq.push(jo);
            }
            sangmin.available_time = d + f * jisu.speed;
        }
        else//지수
        {
            if(d < jisu.available_time)
            {
                d = jisu.available_time;
            }

            for(int j = 0; j < f; j++)
            {
                 int start_time = d + j * jisu.speed;
                job jo;
                jo.priority = start_time * 2 + jisu.priority;
                jo.c = e;
                pq.push(jo);
            }
            jisu.available_time = d + f * jisu.speed;
        }
        
    }

    int peresent_index = 1;
    while (!pq.empty())
    {
        auto j = pq.top();
        pq.pop();
        if(j.c == sangmin.color)
        {
            sangmin_s.push_back(peresent_index); 
        }
        else
        {
            jisu_s.push_back(peresent_index); 
        }
        peresent_index +=1;
    }

    cout << sangmin_s.size();

    cout << endl;

    for(int i = 0 ; i < sangmin_s.size(); i++)
    {
        cout << sangmin_s[i] << " ";
    }

    cout << endl;

    cout << jisu_s.size() << endl;

    for(int i = 0 ; i < jisu_s.size(); i++)
    {
        cout << jisu_s[i] << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}