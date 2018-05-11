#define V 8
#include <stdio.h>
typedef struct vertex
{
	int color;
	int d;
	struct vertex * pi;
} Vertex;

int main(void)
{	
	int queue[V],qh=0,qt=0,adj[V+1][V+2]={0},i,j,c,source,u,v,k;
	Vertex vlist[V+1]={0};

	//data input
	for(i=1,j=1;i<=V;)
	{
		scanf("%d",adj[i]+j);
		c=getchar();
		if (c==32) j++;
		if (c==10){i++;j=1;}
	}
	scanf("%d",&source);
	for (i=1;i<=V;i++)
	{
		printf("%d: ",i);
		for(j=1;adj[i][j];j++)
		{
			printf("%d ",adj[i][j]);
		}
		putchar(10);
	}
	
	
	//BFS
	vlist[source].color=1;
	queue[0]=source;
	while(qh<=qt)
	{
		u=queue[qh++];
		for(i=1;v=adj[u][i];i++)
		{
			if (vlist[v].color==0)
			{
				vlist[v].color=1;
				vlist[v].d=vlist[u].d+1;
				vlist[v].pi=vlist+u;
				queue[++qt]=v;
			}
		}
	}
	
	//result output
	for (k=1;k<=V;k++)
	printf("%d: d=%d,color=%d\n",k,vlist[k].d,vlist[k].color);
}
