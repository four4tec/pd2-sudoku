#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"Sudoku.h"
using namespace std;
//印出預設的題目
int Sudoku::GiveQuestion(){
int i,j,gq[12][12]={
{ 0, 0, 0, 8, 7, 0, 0, 0, 1,-1,-1,-1},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1},
{ 9, 5, 0, 0, 0, 4, 0, 0, 0,-1,-1,-1},
{-1,-1,-1, 0, 0, 0, 0, 0, 7, 0, 0, 0},
{-1,-1,-1, 0, 0, 5, 0, 0, 0, 4, 0, 3},
{-1,-1,-1, 0, 0, 0, 2, 3, 0, 8, 7, 1},
{ 1, 0, 7, 0, 0, 0,-1,-1,-1, 0, 0, 5},
{ 0, 0, 0, 0, 6, 9,-1,-1,-1, 0, 0, 0},
{ 0, 0, 0, 0, 1, 0,-1,-1,-1, 0, 8, 0},
{ 0, 0, 0,-1,-1,-1, 0, 4, 0, 0, 6, 0},
{ 0, 4, 8,-1,-1,-1, 0, 0, 9, 3, 1, 0},
{ 0, 0, 9,-1,-1,-1, 3, 1, 0, 7, 0, 8}};
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d",gq[i][j]);if(j!=11){printf(" ");}}printf("\n");}
return 0;
}

//readin
//讀入黨案
int Sudoku::ReadIn(){
int i,j;
for(i=0;i<12;i++){for(j=0;j<12;j++){scanf("%d",&ori[i][j]);}}
}

//solve
int Sudoku::Solve(){
int i,j,k,l,m,n,cou=1;

rec=0;ita=0;rgt=0;
for(i=0;i<12;i++){for(j=0;j<12;j++){mid[i][j]=ori[i][j];if(ori[i][j]!=0&&ori[i][j]!=-1){rec++;}}}
rez();
for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]!=0&&mid[i][j]!=-1){det(i,j);}}}
if(ifb()==0){printf("0\n");exit(1);}

while(cou!=0){
	cou=0;
	//唯一候選數法
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0&&eyn[i][j][0]==1){for(k=1;k<10;k++){if(eyn[i][j][k]==1){m=k;break;}}mid[i][j]=m;rec++;cou++;det(i,j);}
					else if(mid[i][j]==0&&eyn[i][j][0]==0){printf("0\n");exit(1);}}}
	//隱性唯一候選數法
	for(i=0;i<4;i++){for(j=0;j<4;j++){
		memset(con,0,sizeof(con));memset(rco,0,sizeof(rco));
		for(k=i*3;k<i*3+3;k++){for(l=j*3;l<j*3+3;l++){for(n=0;n<9;n++){if(mid[k][l]==0&&eyn[k][l][n+1]==1){con[n]++;rco[n]=k*1000+l;}
										else if(mid[k][l]==n+1){con[n]--;}}}}
		for(n=0;n<9;n++){if(con[n]==1){mid[rco[n]/1000][rco[n]%1000]=n+1;cou++;rec++;det(rco[n]/1000,rco[n]%1000);}
				else if(con[n]<-1){printf("0\n");exit(1);}}}}}
//判斷是否解完  若無則進猜測
if(rec==108){printf("1\n");for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d ",mid[i][j]);}printf("\n");}exit(1);}
else{
	int ii=-1,jj=-1;
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0){ii=i;jj=j;break;}}if(ii!=-1&&jj!=-1){break;}}
	for(k=1;k<10;k++){
		if(eyn[ii][jj][k]==1){
			//for(l=0;l<12;l++){for(n=0;n<12;n++){ges[l][n]=mid[l][n];}}
			mid[ii][jj]=k;rec++;printf("%d %d %d\n",ii,jj,k);
			guesssolve();mid[ii][jj]=0;rec--;
			rez();for(l=0;l<12;l++){for(n=0;n<12;n++){if(mid[l][n]!=0&&mid[l][n]!=-1){det(l,n);}}}
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d",mid[i][j]);if(j!=11){printf(" ");}}printf("\n");}
}}}
printf("1\n");
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d",mid[i][j]);if(j!=11){printf(" ");}}printf("\n");}
}
//guesssolve
//猜測解法  大致跟Solve一樣
int Sudoku::guesssolve(){
int i,j,k,l,m,n,cou=1,reg=1;
rgt++;
//if(rgt>1000){printf("2p\n");exit(1);}
rez();for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]!=0&&mid[i][j]!=-1){dgs(mid,i,j);}}}

while(cou!=0){
        cou=0;
        for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0&&eyn[i][j][0]==1){for(k=1;k<10;k++){if(eyn[i][j][k]==1){m=k;break;}}mid[i][j]=m;rec++;reg++;cou++;dgs(mid,i,j);}}}
        for(i=0;i<4;i++){for(j=0;j<4;j++){
                memset(con,0,sizeof(con));memset(rco,0,sizeof(rco));
                for(k=i*3;k<i*3+3;k++){for(l=j*3;l<j*3+3;l++){for(n=0;n<9;n++){if(mid[k][l]==0&&eyn[k][l][n+1]==1){con[n]++;rco[n]=k*1000+l;}
                                                                                else if(mid[k][l]==n+1){con[n]--;}}}}
                for(n=0;n<9;n++){if(con[n]==1){mid[rco[n]/1000][rco[n]%1000]=n+1;cou++;reg++;rec++;dgs(mid,rco[n]/1000,rco[n]%1000);}
				else if(con[n]<-1){return 0;}}}}}
rec=108;
for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0){rec--;}}}
if(rec==108){
for(i=0;i<12;i++){for(j=0;j<12;j++){printf("%d",mid[i][j]);if(j!=11){printf(" ");}}printf("\n");}
ita++;rec-=reg;if(ita>1){printf("2o\n");exit(1);};for(i=0;i<12;i++){for(j=0;j<12;j++){recans[i][j]=mid[i][j];}};return 0;}
else{
	int ii=-1,jj=-1;
	//for(l=0;l<12;l++){for(n=0;n<12;n++){ges[l][n]=gess[l][n];}}
	for(i=0;i<12;i++){for(j=0;j<12;j++){if(mid[i][j]==0){ii=i;jj=j;break;}}if(ii!=-1&&jj!=-1){break;}}
	for(k=1;k<10;k++){
		if(eyn[ii][jj][k]==1){
			mid[ii][jj]=k;rec++;printf("%d %d %d %d %d\n",rec,ii,jj,k,rgt);
			guesssolve();mid[ii][jj]=0;rec--;
			rez();for(l=0;l<12;l++){for(n=0;n<12;n++){if(mid[l][n]!=0&&mid[l][n]!=-1){dgs(mid,l,n);}}}
}}}
rgt--;
return 0;
}

//ifb
//判斷題目是否無解
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
//初始化變數
int Sudoku::rez(){
int i,j,k,l;
for(i=0;i<12;i++){for(j=0;j<12;j++){for(k=1;k<10;k++){eyn[i][j][k]=1;}eyn[i][j][0]=9;}}
return 0;}

//dgs
//和det類似但只用在guesssolve裡
int Sudoku::dgs(int gus[12][12],int ii,int jj){
int i,j;
for(i=0;i<12;i++){if(eyn[ii][i][gus[ii][jj]]==1){eyn[ii][i][gus[ii][jj]]=0;eyn[ii][i][0]--;}
                  if(eyn[i][jj][gus[ii][jj]]==1){eyn[i][jj][gus[ii][jj]]=0;eyn[i][jj][0]--;}}
for(i=ii/3*3;i<ii/3*3+3;i++){for(j=jj/3*3;j<jj/3*3+3;j++){if(eyn[i][j][gus[ii][jj]]==1){eyn[i][j][gus[ii][jj]]=0;eyn[i][j][0]--;}}}
for(i=1;i<10;i++){if(gus[ii][jj]==i){continue;}eyn[ii][jj][i]=0;}eyn[ii][jj][0]=1;
return 0;}

//det
//以輸入位置的數字為準將行列九宮格中的數字消去可能
int Sudoku::det(int ii,int jj){
int i,j;
for(i=0;i<12;i++){if(eyn[ii][i][mid[ii][jj]]==1){eyn[ii][i][mid[ii][jj]]=0;eyn[ii][i][0]--;}
		  if(eyn[i][jj][mid[ii][jj]]==1){eyn[i][jj][mid[ii][jj]]=0;eyn[i][jj][0]--;}}
for(i=ii/3*3;i<ii/3*3+3;i++){for(j=jj/3*3;j<jj/3*3+3;j++){if(eyn[i][j][mid[ii][jj]]==1){eyn[i][j][mid[ii][jj]]=0;eyn[i][j][0]--;}}}
for(i=1;i<10;i++){if(mid[ii][jj]==i){continue;}eyn[ii][jj][i]=0;}eyn[ii][jj][0]=1;
return 0;}
