#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

//today problem : https://www.acmicpc.net/problem/1110

int main()
{
    string a;
    string num;
    char num1;
    int num2 = 0;
    cin >> a;
    int first = atoi(a.c_str());
    int c= 0;
    int i = 0;
    
    if(first == 0)
    {
        cout << 1;
        return 0;
    }


    for(;;)
    {
        if(c == first)
        {
            cout << i;
            return 0;
        }
         i++;
        
        if(first > 9 || (i > 1 &&(c > 9)))
        {
            num.push_back(a[0]);
            num.push_back(a[1]);
            num2 = (atoi(num.c_str()) / 10) + (atoi(num.c_str()) % 10);
        }
        else
        {
            num1 = '0';
            num2 = a.back() - '0';
            num.push_back(num1);
            num.push_back(num2 + '0');
            a.clear();
            a.push_back(num2 + '0');
            a.push_back(((num1 - '0') + num2) + '0');
            c =  atoi(a.c_str());
            num.clear();
            continue;
        }
        if(num2 > 9)
        {
            num2 = num2 % 10;
        }
        num1 = a[1];
        a.clear();
        a.push_back(num1);
        a.push_back(num2 + '0');
        c =  atoi(a.c_str());
        num.clear();
    }
    
    return 0;
}