#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maximum_length 10000

int valid(char **A,int r,int c,int row,int col){
    int dr[3]={-1,0,1};
    int dc[3]={-1,0,1};
    int nr,nc;
    int count=0;
    for(int i=0;i<3;i++){
        nr=r+dr[i];
        for(int j=0;j<3;j++){
            nc=c+dc[j];
            if((i==1 && j==1) || nc<0 || nr<0 || nr>row-1 || nc>col-1){
                continue;
             }
            else{
                if(A[nr][nc]=='@'){
                    count++;
                }
            }
        }
    }
    return count;
}
int main(){
    int cap=10;
    int rows=0;
    int col=0;
    char**grid=malloc(cap*sizeof(char*));
    if(!grid){perror("Initial allocation failed"); return 1;}
    char buffer[maximum_length];
    while(fgets(buffer,sizeof(buffer),stdin)){
        buffer[strcspn(buffer, "\n")]=0;
        if(rows>=cap){
            cap*=2;
            char**temp=realloc(grid,cap*sizeof(char*));
            if(!temp){
                perror("realloc failed");
                return 1;
            }
            grid=temp;
        }
        grid[rows]=strdup(buffer);
        rows+=1;
    }
    if(rows>0) col=strlen(grid[0]);
    int sum=0;
    int count=0;
    do{
        count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='@'){
                    if(valid(grid,i,j,rows,col)<4){
                        count++;
                        grid[i][j]='.';
                    }
                }
            }
        }
        sum+=count;
    }while(count>0);
    printf("%d", sum);
    for(int i=0;i<rows;i++) free(grid[i]);
    free(grid);
}