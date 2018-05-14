#include <stdio.h>
#define V 9
typedef struct vertex
{
	int color;
	struct vertex * next;
} Vertex;
void DFS_VISIT(int u,Vertex*vlist,int(*adj)[V+2],Vertex**head)
{
	int j,v;
	vlist[u].color=1;
	for(j=1;v=adj[u][j];j++)
		if (vlist[v].color==0)
			DFS_VISIT(v,vlist,adj,head);
	vlist[u].next=*head;
	*head=vlist+u;
}

int main(void)
{
	int adj[V+1][V+2]={0},i,j,c;
	Vertex vlist[V+1]={0},*head=NULL;
	
	//data input
	for(i=1;i<=V;i++)
	{
		j=1;
		while((c=getchar())!=10)
		{
			ungetc(c,stdin);
			scanf("%d",adj[i]+j++);
		}
	}
	
	//DFS
	for(i=1;i<=V;i++)
		if (vlist[i].color==0)
			DFS_VISIT(i,vlist,adj,&head);
	
	//topological sort result output
	while (head!=NULL)
	{
		printf("%d ",(int)(head-vlist));
		head=head->next;
	}
	
	return 0;		
}
