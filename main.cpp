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
	int ori[12][12],mid[12][12];
	int eyn[12][12][10],byn[16][9][10];
	int ifb();
	int rez();
	int det(int,int);
};

//readin
int Sudoku::ReadIn(){
int i,j;
for(i=0;i<12;i++){for(j=0;j<12;j++){scanf("%d",&ori[i][j]);}}
//for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",ori[i][j]);}printf("\n");}
}

//solve
int Sudoku::Solve(){
int i,j,k,l,m;
for(i=0;i<12;i++){for(j=0;j<12;j++){mid[i][j]=ori[i][j];}}
rez();
if(ifb()==0){printf("0\n");exit(1);}

for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]!=0&&mid[i][j]!=-1){det(i,j);}}}

for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",mid[i][j]);if(mid[i][j]==-1){printf("\b");}}printf("\n");}printf("\n");
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",ori[i][j]);if(mid[i][j]==-1){printf("\b");}}printf("\n");}
printf("%d\n",eyn[3][6][0]);
printf("%d\n",eyn[6][3][0]);


}

//ifb
int Sudoku::ifb(){
int i,j,k,l,co=0,ib=1;
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[i][j]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[j][i]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i+=3){for(j=0;j<12;j+=3){co=0;for(k=0;k<3;k++){for(l=0;l<3;l++){if(ori[i+k][j+l]==-1){co++;}}}if(co!=0&&co!=9){ib=0;}}}
return ib;}

//rez
int Sudoku::rez(){
int i,j,k,l;
for(i=0;i<12;i++){for(j=0;j<12;j++){for(k=1;k<10;k++){eyn[i][j][k]=1;}eyn[i][j][0]=9;}}
for(i=0;i<12;i++){for(j=0;j<9;j++){for(k=1;k<10;k++){byn[i][j][k]=1;}byn[i][j][0]=9;}}
return 0;}

//det
int Sudoku::det(int ii,int jj){
int i,j;
for(i=0;i<12;i++){if(eyn[ii][i][mid[ii][jj]]==1){eyn[ii][i][mid[ii][jj]]=0;eyn[ii][i][0]--;}
		  if(eyn[i][jj][mid[ii][jj]]==1){eyn[i][jj][mid[ii][jj]]=0;eyn[i][jj][0]--;}}
for(i=ii/3*3;i<ii/3*3+3;i++){for(j=jj/3*3;j<jj/3*3+3;j++){if(eyn[i][j][mid[ii][jj]]==1){eyn[i][j][mid[ii][jj]]=0;eyn[i][j][0]--;}}}
for(i=1;i<10;i++){if(mid[ii][jj]==i){continue;}eyn[ii][jj][i]=0;}eyn[ii][jj][0]=1;
return 0;}

//main
int main(){
Sudoku wi;
wi.ReadIn();
wi.Solve();
return 0;}
