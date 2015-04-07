#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"Sudoku.h"
using namespace std;
/*class Sudoku{
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
	int det(int,int),dgs(int gus[12][12],int ii,int jj);};*/

int Sudoku::GiveQuestion(){
int i,j,gq[12][12]={
{ 1, 2, 3, 4, 5, 6, 7, 8, 0,-1,-1,-1},
{ 4, 5, 6, 7, 8, 9, 1, 2, 0,-1,-1,-1},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1},
{ 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0},
{ 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
{-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",gq[i][j]);}printf("\n");}
}

//readin
int Sudoku::ReadIn(){
int i,j;
for(i=0;i<12;i++){for(j=0;j<12;j++){scanf("%d",&ori[i][j]);}}
}

//solve
int Sudoku::Solve(){
int i,j,k,l,m,n,cou=1;

rec=0;ita=0;
for(i=0;i<12;i++){for(j=0;j<12;j++){mid[i][j]=ori[i][j];if(ori[i][j]!=0&&ori[i][j]!=-1){rec++;}}}
if(rec<18){printf("2\n");exit(1);}
rez();
for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]!=0&&mid[i][j]!=-1){det(i,j);}}}
if(ifb()==0){printf("0\n");exit(1);}

while(cou!=0){
	cou=0;
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0&&eyn[i][j][0]==1){for(k=1;k<10;k++){if(eyn[i][j][k]==1){m=k;break;}}mid[i][j]=m;rec++;cou++;det(i,j);}
					else if(mid[i][j]==0&&eyn[i][j][0]==0){printf("0\n");exit(1);}}}
	for(i=0;i<4;i++){for(j=0;j<4;j++){
		memset(con,0,sizeof(con));memset(rco,0,sizeof(rco));
		for(k=i*3;k<i*3+3;k++){for(l=j*3;l<j*3+3;l++){for(n=0;n<9;n++){if(mid[k][l]==0&&eyn[k][l][n+1]==1){con[n]++;rco[n]=k*1000+l;}
										else if(mid[k][l]==n+1){con[n]--;}}}}
		for(n=0;n<9;n++){if(con[n]==1){mid[rco[n]/1000][rco[n]%1000]=n+1;cou++;rec++;det(rco[n]/1000,rco[n]%1000);}
				else if(con[n]<-1){printf("0\n");exit(1);}}}}}

//for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",mid[i][j]);}printf("\n");}
if(rec==108){printf("1\n");for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",mid[i][j]);}printf("\n");}exit(1);}
else{
	int ges[12][12];
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0){for(k=1;k<10;k++){
		if(eyn[i][j][k]==1){
			for(l=0;l<12;l++){for(n=0;n<12;n++){ges[l][n]=mid[l][n];}}
			ges[i][j]=k;rec++;
			guesssolve(ges);
rez();for(l=0;l<12;l++){for(n=0;n<12;n++){if(mid[l][n]!=0&&mid[l][n]!=-1){det(l,n);}}}
}}}}}}
printf("1\n");for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",mid[i][j]);}printf("\n");}
//for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",ori[i][j]);}printf("\n");}
}
//guesssolve
int Sudoku::guesssolve(int gess[12][12]){
int i,j,k,l,m,n,cou=1,reg=1;

for(i=0;i<12;i++){for(j=0;j<12;j++){if(gess[i][j]!=0&&gess[i][j]!=-1){dgs(gess,i,j);}}}

while(cou!=0){
        cou=0;
        for(i=0;i<12;i++){for(j=0;j<12;j++){if(gess[i][j]==0&&eyn[i][j][0]==1){for(k=1;k<10;k++){if(eyn[i][j][k]==1){m=k;break;}}gess[i][j]=m;rec++;reg++;cou++;dgs(gess,i,j);}}}
        for(i=0;i<4;i++){for(j=0;j<4;j++){
                memset(con,0,sizeof(con));memset(rco,0,sizeof(rco));
                for(k=i*3;k<i*3+3;k++){for(l=j*3;l<j*3+3;l++){for(n=0;n<9;n++){if(gess[k][l]==0&&eyn[k][l][n+1]==1){con[n]++;rco[n]=k*1000+l;}
                                                                                else if(gess[k][l]==n+1){con[n]--;}}}}
                for(n=0;n<9;n++){if(con[n]==1){gess[rco[n]/1000][rco[n]%1000]=n+1;cou++;reg++;rec++;dgs(gess,rco[n]/1000,rco[n]%1000);}
				else if(con[n]<-1){printf("0\n");exit(1);}}}}}
//printf("%d %d\n",rec,ita);
if(rec==108){ita++;rec-=reg;if(ita>1){printf("2\n");exit(1);};for(i=0;i<12;i++){for(j=0;j<12;j++){recans[i][j]=gess[i][j];}};return 0;}
else{
	int ges[12][12];
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(gess[i][j]==0){for(k=1;k<10;k++){
		if(eyn[i][j][k]==1){
			for(l=0;l<12;l++){for(n=0;n<12;n++){ges[l][n]=gess[l][n];}}
			ges[i][j]=k;rec++;
//printf("%d %d %d\n",i,j,k);
			guesssolve(ges);
rez();for(l=0;l<12;l++){for(n=0;n<12;n++){if(gess[l][n]!=0&&gess[l][n]!=-1){dgs(gess,l,n);}}}
}}}}}}

//for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",ori[i][j]);}printf("\n");}
}

//ifb
int Sudoku::ifb(){
int i,j,k,l,co=0,ib=1,che[11];
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[i][j]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i++){co=0;for(j=0;j<12;j++){if(ori[j][i]==-1){co++;}}if(co!=3){ib=0;}}
for(i=0;i<12;i+=3){for(j=0;j<12;j+=3){co=0;for(k=0;k<3;k++){for(l=0;l<3;l++){if(ori[i+k][j+l]==-1){co++;}}}if(co!=0&&co!=9){ib=0;}}}
for(i=0;i<12;i++){for(j=0;j<12;j++){if(ori[i][j]==0&&eyn[i][j][0]==0){ib=0;break;}}}
for(i=0;i<12;i+=3){for(j=0;j<12;j+=3){memset(che,0,sizeof(che));
					for(k=0;k<3;k++){for(l=0;l<3;l++){che[ori[i+k][j+l]+1]++;}}
					for(k=2;k<11;k++){if(che[k]>1){ib=0;}}}}
return ib;}

//rez
int Sudoku::rez(){
int i,j,k,l;
for(i=0;i<12;i++){for(j=0;j<12;j++){for(k=1;k<10;k++){eyn[i][j][k]=1;}eyn[i][j][0]=9;}}
//for(i=0;i<12;i++){for(j=0;j<9;j++){for(k=1;k<10;k++){byn[i][j][k]=1;}byn[i][j][0]=9;}}
return 0;}

//dgs
int Sudoku::dgs(int gus[12][12],int ii,int jj){
int i,j;
for(i=0;i<12;i++){if(eyn[ii][i][gus[ii][jj]]==1){eyn[ii][i][gus[ii][jj]]=0;eyn[ii][i][0]--;}
                  if(eyn[i][jj][gus[ii][jj]]==1){eyn[i][jj][gus[ii][jj]]=0;eyn[i][jj][0]--;}}
for(i=ii/3*3;i<ii/3*3+3;i++){for(j=jj/3*3;j<jj/3*3+3;j++){if(eyn[i][j][gus[ii][jj]]==1){eyn[i][j][gus[ii][jj]]=0;eyn[i][j][0]--;}}}
for(i=1;i<10;i++){if(gus[ii][jj]==i){continue;}eyn[ii][jj][i]=0;}eyn[ii][jj][0]=1;
return 0;}

//det
int Sudoku::det(int ii,int jj){
int i,j;
for(i=0;i<12;i++){if(eyn[ii][i][mid[ii][jj]]==1){eyn[ii][i][mid[ii][jj]]=0;eyn[ii][i][0]--;}
		  if(eyn[i][jj][mid[ii][jj]]==1){eyn[i][jj][mid[ii][jj]]=0;eyn[i][jj][0]--;}}
for(i=ii/3*3;i<ii/3*3+3;i++){for(j=jj/3*3;j<jj/3*3+3;j++){if(eyn[i][j][mid[ii][jj]]==1){eyn[i][j][mid[ii][jj]]=0;eyn[i][j][0]--;}}}
for(i=1;i<10;i++){if(mid[ii][jj]==i){continue;}eyn[ii][jj][i]=0;}eyn[ii][jj][0]=1;
return 0;}
