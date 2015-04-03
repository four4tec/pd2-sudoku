#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//class sudoku
class Sudoku{
public:
	int ReadIn();
	int Solve();
	int GiveQuestion();
private:
	int ori[12][12];
	int mid[12][12];
	int ifb();
};
//readin
int Sudoku::ReadIn(){
int i,j;
for(i=0;i<12;i++){for(j=0;j<12;j++){scanf("%d",&ori[i][j]);}}
//for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",ori[i][j]);}printf("\n");}
}
//solve
int Sudoku::Solve(){
int i,j;
for(i=0;i<12;i++){for(j=0;j<12;j++){mid[i][j]=ori[i][j];}}
if(ifb()==0){printf("0\n");exit(1);}







}
//ifb
int Sudoku::ifb(){
int i,j,k,l,co=0,ib=1;
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[i][j]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[j][i]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i+=3){for(j=0;j<12;j+=3){co=0;for(k=0;k<3;k++){for(l=0;l<3;l++){if(ori[i+k][j+l]==-1){co++;}}}if(co!=0&&co!=9){ib=0;printf("s");}}}
return ib;}
//main
int main(){
Sudoku wi;
wi.ReadIn();
wi.Solve();
return 0;}
