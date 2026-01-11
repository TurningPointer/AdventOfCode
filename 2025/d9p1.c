#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct p{
    int x;
    int y;
}p;

typedef struct np{
    int x;
    int y;
    struct np* next;
}np;

int compare(const void *a,const void *b){
    const p *p1=(const p*)a;
    const p *p2=(const p*)b;
    if(p1->x!=p2->x){
        return p1->x-p2->x;
    }
    else{
        return p1->y-p2->y;
    }
}

int cpdt(np *p1,np *p2,np *p3){
    return((p2->x-p1->x)*(p3->y-p1->y)-(p3->x-p1->x)*(p2->y-p1->y));
}

int main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    FILE *f;
    f=fopen("huge_input.txt","r");    
    char line[256];
    p *pl=malloc(sizeof(p));
    int c=0;    
    while(fgets(line,sizeof(line),f)){
        line[strcspn(line,"\n")]='\0';
        int val=strcspn(line,",");
        int num1=0;
        int num2=0;
        int i=0;
        for(;i<val;i++){
            num1=num1*10+(line[i]-48);
        } 
        i+=1;
        pl[c].x=num1;
        for(;line[i]!='\0';i++){
            num2=num2*10+(line[i]-48);
        }
        pl[c].y=num2;
        pl=realloc(pl,(c+2)*sizeof(p));
        c++;
    }
    fclose(f);
    qsort(pl,c,sizeof(p),compare);
    np **newp=malloc(sizeof(np*));
    int k=0;
    for(int i=0;i<c;i++){
        np *temp = malloc(sizeof(np));
        temp->x = pl[i].x;
        temp->y = pl[i].y;
        temp->next = NULL;
        while(k>=2 && cpdt(newp[k-2], newp[k-1], temp)<=0){
            k--;
        }
        newp = realloc(newp, (k+2)*sizeof(np*));
        newp[k] = temp;
        newp[k]->next = newp[k+1];
        k++;
    }
    int t=k;
    for(int i=c-2;i>=0;i--){
        np *temp = malloc(sizeof(np));
        temp->x = pl[i].x;
        temp->y = pl[i].y;
        temp->next = NULL;
        while(k>=t && cpdt(newp[k-2], newp[k-1], temp)<=0){
            k--;
        }
        newp = realloc(newp, (k+2)*sizeof(np*));
        newp[k] = temp;
        newp[k]->next = newp[k+1];
        k++;
    }
    k--;
    newp[k]->next = NULL;
    free(newp[k+1]);
    long long max_area = 0;
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            long long width = abs(newp[i]->x - newp[j]->x) + 1;
            long long height = abs(newp[i]->y - newp[j]->y) + 1;
            long long area = width * height;
            if(area > max_area){
                max_area = area;
            }
        }
    }
    printf("Max Area: %lld\n", max_area);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%ld",CLOCKS_PER_SEC);
    printf("Code took %f seconds to execute\n", cpu_time_used);

}