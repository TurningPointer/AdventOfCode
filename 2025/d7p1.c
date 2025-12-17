#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define maxsize 1000

int rn(char **A,int r,int c){
    if(A[r][c]=='^'){
        return r;
    }
}
int find(char **A,int r,int c){
    int index=-1;
    for(int i=0;i<r;i++){
        if(A[i][c]=='^'){
            index=i;
        }
    }
    return index;
}

int main(){
    clock_t start_time = clock();
    int cap=10;
    char **grid=malloc(cap*sizeof(char*));
    char buffer[maxsize];
    int row=0;
    while(fgets(buffer,sizeof(buffer),stdin)){
        buffer[strcspn(buffer,"\n")]='\0';
        if(row>cap-1){
            cap*=2;
            char **temp=realloc(grid,cap*sizeof(char*));
            if(temp==NULL){
                perror("Out of memory");
                return 1;
            }
            grid=temp;
        }
        grid[row]=strdup(buffer);
        row++;
    }
    int cols=strlen(grid[0]);
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]=='^'){
                if(i>=2){
                    if(grid[i-2][j]=='S'){
                        count++;
                    }
                    else{
                        if(j+1<cols && find(grid,i,j+1)!=-1){
                            int k=find(grid,i,j+1);
                            int ans=1;
                            for(int a=k+1;a<i;a++){
                                if(grid[a][j]=='^'){
                                    ans=0;
                                    break;
                                }
                            }
                            if(ans==1){
                                count++;
                                //printf("k");
                                continue;
                            }
                        }
                        if(j-1>=0 && find(grid,i,j-1)!=-1){
                            int k=find(grid,i,j-1);
                            int ans=1;
                            for(int a=k+1;a<i;a++){
                                if(grid[a][j]=='^'){
                                    ans=0;
                                    break;
                                }
                            }
                            if(ans==1){
                                count++;
                                //printf("k");
                                //continue;
                            }
                        }
                    }
                }
            }
        } 
    }
    printf("%d\n",count);
    for(int i=0;i<row;i++){
        free(grid[i]);
    }
    free(grid);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);
    return 0;
}  