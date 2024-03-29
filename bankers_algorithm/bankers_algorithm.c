#include<stdio.h> 
#include<stdlib.h> 

int alloc[10][10],max[10][10],need[10] 
[10],avail[10],work[10],finish[10],request[10]; 
int p,r,j,i,k,v=0,req=0,pno; 
int check(int i) { 
    for(j=0;j<r;j++) 
    if(need[i][j]>work[j]) 
    return 0; 
    return 1; 
} 

int main() { 
    printf("Enter the number of processes and resources\n"); 
    scanf("%d%d",&p,&r); 
    int seq[p]; 
    
    printf("Enter the allocation matrix\n"); 
    for(i=0;i<p;i++) 
    for(j=0;j<r;j++) 
    scanf("%d",&alloc[i][j]); 
    
    printf("Enter the maximum matrix\n"); 
    for(i=0;i<p;i++) 
    for(j=0;j<r;j++) 
    scanf("%d",&max[i][j]); 
    
    for(i=0;i<p;i++) 
    for(j=0;j<r;j++) 
    need[i][j]=max[i][j]-alloc[i][j]; 
    
    printf("Enter the available array\n"); 
    for(i=0;i<r;i++) { 
        scanf("%d",&avail[i]); 
        work[i]=avail[i]; 
    } 
    for(i=0;i<p;i++) 
        finish[i]=0; 
    while(v<p) { 
        int allocated=0; 
        for(i=0;i<p;i++) 
        if(!finish[i]&&check(i)) { 
            for(k=0;k<r;k++) 
            work[k]=work[k]+alloc[i][k]; 
            allocated=finish[i]=1; 
            seq[v]=i; 
            v++; 
        } 
        if(!allocated) 
            break; 
    
    } 
    for(i=0;i<p;i++) 
    if(finish[i]==0) { 
        printf("Safe Sequence is not generated\n"); 
        exit(0); 
    } 
    printf("Safe Sequence is: \n"); 
    
    for(i=0;i<v;i++) 
        printf("%d\t",seq[i]); 
} 
