#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

//class sudoku
class Sudoku{
public:
        int ReadIn();
        int Solve();
        int GiveQuestion();
private:
        int ori[12][12],mid[12][12],recans[12][12];
        int eyn[12][12][10],con[9],rco[9];
        int rec,ita;
        int ifb();
        int rez();
        int guesssolve(int gess[12][12]);
        int det(int,int),dgs(int gus[12][12],int ii,int jj);
};

