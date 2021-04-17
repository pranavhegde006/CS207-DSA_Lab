#include <stdio.h>
#include <stdlib.h>

// Checks if there exists a path between u and v.
// Returns 1 if a path is present, returns 0 otherwise.
int check_path(int **graph, int n, int u, int v);

/*#include<stdio.h>
#include "bfs.h"*/

int check_path(int **graph, int n, int v, int u)
{
	//TODO  
	int a,b;
	int visit[n];            
	int q[100];
	int f=-1,r=-1;
	for(int a=0;a<=n;a++)
	{
		visit[a]=0;
	}
	
	visit[v]=1;
	
	//printf("%d",v);
	
	r++;
	q[r]=v;
	if(f==-1)
	{
		f=0;
	}

do
{
	b=q[f];
	if(f==r)
	{f=r=-1;}
	else
	{f++;}

	for(int i=0;i<=n;i++)
	{
		if((graph[b][i]==1)&&(visit[i]==0))
		{
			visit[i]=1;
			
			//printf("%d",i);
			
			r++;
			q[r]=i;
			if(f==-1)
			{f=0;}
			
		}
	}
}while(f!=-1);
if(visit[u]==1)
{
	return 1;
}
else 
{
	return 0;
}

	
}	


/*#include<stdio.h>
#include "bfs.h"*/

int main()
{
    int n, q, u, v;
    scanf("%d %d", &n, &q);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &u, &v);
        if (check_path(graph, n, u - 1, v - 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    return 0;
}


