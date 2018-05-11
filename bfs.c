#define V 8
#include <stdio.h>
typedef struct vertex
{
	int color;
	int d;
	struct vertex * pi;
} Vertex;
void print_path(int a,int source,Vertex*vlist)
{
	if (a==source)
		printf("%d ",source);
	else if (vlist[a].pi==NULL)
		printf("no path");
	else
	{
		print_path((int)(vlist[a].pi-vlist),source,vlist);
		printf("%d ",a);
	}
		
}
int main(void)
{	
	int queue[V],qh=0,qt=0,adj[V+1][V+2]={0},i,j,c,source,u,v,loc;
	Vertex vlist[V+1]={0};

	//data input
	for(i=1,j=1;i<=V;)
	{
		scanf("%d",adj[i]+j);
		c=getchar();
		if (c==32) j++;
		if (c==10){i++;j=1;}
	}
	scanf("%d%d",&source,&loc);
	for (i=1;i<=V;i++)
	{
		printf("%d: ",i);
		for(j=1;adj[i][j]!=0;j++)
		{
			printf("%d ",adj[i][j]);
		}
		putchar(10);
	}
	
	
	//BFS
	for (i=1;i<=V;i++)
	{
		vlist[i].d=V;
	}
	vlist[source].color=1;
	vlist[source].d=0;
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
	for (i=1;i<=V;i++)
	{
		printf("%d: d=%d,color=%d,",i,vlist[i].d,vlist[i].color);
		if (i!=source)
			printf("pi=%d\n",(int)(vlist[i].pi-vlist));
		else
			printf("I am the source.\n");
	}
	printf("One shortest path from source %d to location %d is\n",
	source,loc);
	print_path(loc,source,vlist);	
}
