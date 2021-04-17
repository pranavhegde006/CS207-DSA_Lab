#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u){
	//TODO
	int temp, front = -1, rear = -1;
	int visited[n], queue[100];
	int all = 0;
	while(all < n){
		visited[all] = 0;
		all++;
	}

	visited[v] = 1;
	rear++;
	queue[rear] = v;
	if(front == -1) front=0;

	do{
		temp = queue[front];
		if(front == rear) front = rear = -1;
		else front++;

		int count = 0;
		while(count <= n){
			if(graph[temp][count] && !visited[count]){
				visited[count] = 1;
				rear++;
				queue[rear]=count;
				if(front == -1) front=0;
			}
			count++;
		}
	}while(front!=-1);

	if(visited[u]) return 1;
	return 0;
}	
