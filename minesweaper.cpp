/*Якось Вероніка у вільний час вирішила пограти в усім відому гру
«Сапер». Однак тільки вона з головою занурилася в гру, Оксана
Сергіївна покликала її на черговий квест. Вероніка зажурилася, що не
закінчила гру, але що робити – Оксані Сергіївні потрібна допомога…
Володимир, побачивши незавершену гру, вирішив допомогти дівчинці і
записав стан поля на момент, коли Вероніка зупинила гру. В цей опис
входили такі параметри:
• розмір поля;
• кількість мін;
• координати мін.
Ваша задача відновити поле по записах Володимира*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void in_2dmas(int mas[][100], int row, int col){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            cin >> mas[i][j];
        }
    }
}

void out_2dmas(int mas[][100], int row, int col){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++)
        {
            if (mas[i][j]==-1)
            {
                cout << "* ";
            }
            else
            {
                cout << mas[i][j] << " ";
            }

        }
        cout << '\n';
    }
}


void calculating_cnt(int mas[][100], int row, int col)
{
    int cnt=0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (!(mas[i][j]==-1))
            {
                if (mas[i+1][j-1]==-1) cnt++;
                if (mas[i+1][j]==-1) cnt++;
                if (mas[i+1][j+1]==-1) cnt++;
                if (mas[i][j-1]==-1) cnt++;
            
                if (mas[i][j+1]==-1) cnt++;
                if (mas[i-1][j-1]==-1) cnt++;
                if (mas[i-1][j]==-1) cnt++;
                if (mas[i-1][j+1]==-1) cnt++;
                mas[i][j]=cnt;
                cnt=0;
            }
        }
    }
}


int main()
{
    int row, col, N, x, y;
    cin >> row >> col >> N;
    int mas[100][100]={0}; 
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        mas[x][y]=-1;
    }
    calculating_cnt(mas, row, col);
    out_2dmas(mas, row, col);

    return 0;
}