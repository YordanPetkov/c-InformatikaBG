#include<iostream>
using namespace std;
#define MAXN 9
unsigned char Sudoku[MAXN][MAXN],n=MAXN;
//char CanPut[MAXN][MAXN][MAXN];
bool CanPutNumber(unsigned char k, unsigned char x, unsigned char y){
    for(int j = 0; j < n; j++){//For row
        if(j == y)continue;
        if(Sudoku[x][j] == k)return false;
    }
    for(int i = 0; i < n; i++){//For column
        if(i == x)continue;
        if(Sudoku[i][y] == k)return false;
    }

    unsigned char Fx,Fy,Lx,Ly;
    Fx = x/3*3;
    Fy = y/3*3;
    Lx = x/3*3+2;
    Ly = y/3*3+2;
    for(int i = Fx; i <= Lx; i++){
        for(int j = Fy; j <= Ly; j++){
            if(i == x && j == y)continue;
            if(Sudoku[i][j] == k)return false;
        }
    }
    return true;
}

bool SolveSudoku(unsigned char CurX, unsigned char CurY){
    if(CurX >= MAXN || CurY >= MAXN)return true;
    if(Sudoku[CurX][CurY] != 0)SolveSudoku(CurX/MAXN,CurY%MAXN);

    for(int i = 1; i <= MAXN; i++){
        if(CanPutNumber(i,CurX,CurY) && Sudoku[CurX][CurY] == 0){
            Sudoku[CurX][CurY] = i;
            SolveSudoku(CurX/MAXN,CurY%MAXN);
            Sudoku[CurX][CurY] = 0;
        }
    }

    return false;
}

int main (){
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            cin>>Sudoku[i][j];


    if(SolveSudoku(0,0)){
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                if(j == MAXN - 1)cout<<Sudoku[i][j];
                else cout<<Sudoku[i][j]<<" ";
            }
        }
    }
    else cout<<-1<<endl;
    return 0;
}
