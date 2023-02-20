
#include<stdio.h>
#include<stdlib.h>
int source,v,e,g[20][20],visited[20],q[20];
int front=-1;
int rear=-1;
void enqueue(int data){
    if(rear==-1){
        front=0;
    }
    q[++rear]=data;
}
int dequeue(){
    if(front==-1){
        return 02;
    }
    else{
        return q[front--];
    }
}
void dfs(int i){
    int j;
    visited[i]=1;
    printf("%3d",i);
    for(j=1;j<=v;j++)
    {
        if(g[i][j]==1 && visited[j]==0)
        dfs(j);
    }
}

void bfs(int s){
    int i;
    visited[s]=1;
    printf("%3d", s);
    enqueue(s);
    while(front!=-1){
        s=dequeue();
        for(i=1;i<=v;i++)
        {
            if (g[s][i]==1 && visited[i]==0)
            {
                printf("%3d",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}

void main(){
    int i,j,v1,v2,opt;
    printf("enter the no: of vertices of the graph");
    scanf("%d",&v);
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            g[i][j]=0;
        }
    }
    printf("enter the number of edges ");
    scanf("%d",&e);

    for(int i=1;i<=e;i++)
    {
        printf("enter the edges(v1 v2): ");
        scanf("%d %d", &v1,&v2);
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
    printf("adjacency matrix\n");
    for(int i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("%3d",g[i][j]);
        }
        printf("\n");
    }
    
    for (int i=1;i<=v;i++){
        visited[i]=0;}
    printf("source");
    scanf("%d",&source);
    printf("dfs:\n");
     
    dfs(source);
    for (int i=1;i<=v;i++){
        visited[i]=0;}
     printf("\nbfs:\n");
    bfs(source);

}
