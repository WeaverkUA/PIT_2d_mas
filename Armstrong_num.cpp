/*Дано прямокутний масив, що містить row рядків та column стовпчиків. Знайти
у ньому всі числа Армстронга. Числом Армстронга називається число, що
дорівнює сумі своїх цифр, піднесених до степеню, що дорівнює кількості цифр
у числі, наприклад*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void in_2dmas(int mas[][100], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> mas[i][j];
        }
    }
}

int cnt_digit(int N)
{
    N=abs(N);
    int cnt=0;
    if (N==0) return 1;
    while(N!=0)
    {
        cnt++;
        N/=10;
    }
    return cnt;
}

bool Armstrong(int N) {
    int original = N; 
    int cnt = cnt_digit(N), sum = 0;
    while (N != 0) {
        sum = sum + pow(N % 10, cnt);
        N /= 10;
    }
    if (original == sum) return true;
    return false;
}

void out_2dmas_if_good(int mas[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        bool found = false;
        for (int j = 0; j < col; j++) {
            if (Armstrong(mas[i][j])) {
                cout << mas[i][j] << " ";
                found = true;
            }
        }
        if (!found) {
            cout << "-1";
        }
        cout << '\n';
    }
}

int main()
{
    int row, col, N;
    cin >> row >> col;
    int mas[100][100]; 
    in_2dmas(mas, row, col);
    out_2dmas_if_good(mas, row, col);

    return 0;
}