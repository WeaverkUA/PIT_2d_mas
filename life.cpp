/*У деяких клітинках квадрата N x N живуть мікроорганізми (не більше одного в
одній клітці). Кожну секунду відбувається наступне:
- всі мікроорганізми, у яких менше 2-х сусідів, вмирають від нудьги (сусідами
називаються мікроорганізми, які живуть в клітинах, що мають спільну сторону
або вершину);
- всі мікроорганізми, у яких більше 3-х сусідів, вмирають від
перенаселеності;
- на всіх порожніх клітинках, у яких рівно в трьох сусідніх клітках жили
мікроорганізми, з'являються нові мікроорганізми.
Всі зміни відбуваються одночасно, тобто для кожної клітини спочатку
з'ясовується її доля, а потім відбуваються зміни відразу у всіх клітинах.
Потрібно за даної конфігурації визначити, на що вона перетвориться через T секунд.*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mas[100][100]={0}; 
int mas2[100][100]={0};

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
            cout << mas[i][j] << " ";
        }
        cout << '\n';
    }
}

void mas_equal(int mas[][100], int mas2[][100], int row, int col)
{
    for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                mas[i][j] = mas2[i][j];
            }
        }

}

int main()
{
    int  N, time;
    cin >> N >> time;
    in_2dmas(mas, N, N);
    int cnt=0;
    for (int k = 1; k <= time; k++)
    {
        mas_equal(mas2, mas, N, N);
        for (int i = 1; i <= N; i++)
        {
            
            for (int j = 1; j <= N; j++)
            {
                if (mas[i+1][j-1]==1) cnt++;
                if (mas[i+1][j]==1) cnt++;
                if (mas[i+1][j+1]==1) cnt++;
                if (mas[i][j-1]==1) cnt++;
                if (mas[i][j+1]==1) cnt++;
                if (mas[i-1][j-1]==1) cnt++;
                if (mas[i-1][j]==1) cnt++;
                if (mas[i-1][j+1]==1) cnt++;

                if ((cnt<2) or (cnt>3)) mas2[i][j]=0;
                if (cnt==3) mas2[i][j]=1;
                cnt=0;
            }
        }
        swap(mas, mas2);
    }
    out_2dmas(mas, N, N);

    return 0;
}