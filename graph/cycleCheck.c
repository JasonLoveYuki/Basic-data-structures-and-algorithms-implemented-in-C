#include <stdio.h>
#include <stdbool.h>
#include "Graph.h"
#define MAX_NODES 1000

bool dfsCycleCheck(Graph g, Vertex v, Vertex u);
bool hasCycle(Graph g);

int visited[MAX_NODES];

int main(int argc, char *argv[]){
	Edge e;
  	int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");
    if (hasCycle(g)){
    	printf("The gaph has a cycle\n");
    }
    else{
    	printf("The graph is acyclic\n");
    }
	return 0;
}
bool dfsCycleCheck(Graph g, Vertex v, Vertex u){
	visited[v] = true;
	Vertex w;
	for (w = 0; w < numOfVertices(g); w++){
		if (adjacent(g, v, w)) {
			if (!visited[w]){
				if (dfsCycleCheck(g, w, v)){
					return true;
				}
			}
			else if (w != u){
				return true;
			}
		}
	}
	return false;
}
bool hasCycle(Graph g) {
	Vertex v;
	int nV = numOfVertices(g);
	for (v = 0; v < nV; v++){
		visited[v] = false;
	}
	for (v = 0; v < nV; v++){
		if (!visited[v]){
			if (dfsCycleCheck(g,v,v)){
				return true;
			}
		}
	}
	return false;
}