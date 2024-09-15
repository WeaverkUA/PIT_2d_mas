/*Дано число n. Створіть масив A [2 * n + 1] [2 * n + 1] і заповніть його по спіралі, починаючи
з числа 0 в центральній клітинці A [n + 1] [n + 1]. Спіраль виходить вгору, далі
закручується проти годинникової стрілки.*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void out_2dmas(int mas[][100], int row, int col){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++)
        {
            cout << setw(3) << mas[i][j]; 
        }
        cout  << '\n';
    }
}

int main()
{
    //freopen("Spiral.dat", "r", stdin);
    //freopen("Spiral.res", "w", stdout);
    int N, cnt=0, prohid=1, currROW, currCOL;
    cin >> N;
    const int side=2*N+1;
    int mas[100][100]; 
    currROW=N+1;
    currCOL=N+1;
    
    mas[currROW][currCOL]=cnt;
    cnt++;
    while(cnt<side*side-1)
    {
        currROW--;
        for (int i = 1; i <= prohid*2-1; i++)
        {
            mas[currROW][currCOL]=cnt;
            currCOL--;
            cnt++;
        }
        
        for (int i = 1; i <= prohid*2; i++)
        {
            mas[currROW][currCOL]=cnt;
            currROW++;
            cnt++;
        }
        
        for (int i = 1; i <= prohid*2; i++)
        {
            mas[currROW][currCOL]=cnt;
            currCOL++;
            cnt++;
        }
        mas[currROW][currCOL]=cnt;

        for (int i = 1; i <= prohid*2; i++)
        {
            mas[currROW][currCOL]=cnt;
            currROW--;
            cnt++;
        }
        mas[currROW][currCOL]=cnt;
        cnt++;
        prohid++;
    }
    out_2dmas(mas, side, side);

    return 0;
}