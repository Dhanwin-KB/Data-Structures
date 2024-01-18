#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct graph {
    int nVertices;   
    int nEdges;      
    int **adjMatrix;
} Graph;

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

QueueNode *head = NULL;

void printGraph(Graph *);
Graph *createAdjMatrixOfGraph(Graph *);
void enqueue(int item);
int dequeue();
void breadthFirstTraversal(Graph *, int, int *);
void depthFirstTraversal(Graph *, int, int *);

Graph *createAdjMatrixOfGraph(Graph *g) {
    int i, u, v;

    g = (Graph *)malloc(sizeof(Graph));

    printf("Enter the number of Vertices and Edges:");
    scanf("%d%d", &g->nVertices, &g->nEdges);

    g->adjMatrix = (int **)malloc(sizeof(int *) * g->nVertices);

    for (i = 0; i < g->nVertices; i++)
        g->adjMatrix[i] = (int *)malloc(sizeof(int) * g->nVertices);

    for (i = 0; i < g->nEdges; i++) {
        printf("Reading the endpoints of an edge (u v):\n");
        scanf("%d %d", &u, &v);
        g->adjMatrix[u][v] = 1;
        g->adjMatrix[v][u] = 1;
    }

    return g;
}

void printGraph(Graph *g) {
    int i, j;

    printf("\n***Adjacency Matrix of Graph***\n");

    for (i = 0; i < g->nVertices; i++) {
        printf("\n\t");
        for (j = 0; j < g->nVertices; j++) {
            if (g->adjMatrix[i][j]) {
                printf("1 ");
            } else
                printf("0 ");
        }
    }
}

void enqueue(int item) {
    QueueNode *list = head;
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));

    temp->data = item;
    temp->next = NULL;

    if (list)
        temp->next = list;

    head = temp;
}

int dequeue() {
    int itemDequeued;
    QueueNode *list = head;
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));

    if (!list) {
        return INT_MIN;
    } else if (!list->next) {
        itemDequeued = list->data;
        head = NULL;
        free(list);
        return itemDequeued;
    } else {
        while (list->next) {
            temp = list;
            list = list->next;
        }
    }

    itemDequeued = list->data;
    temp->next = NULL;
    free(list);

    return itemDequeued;
}

void breadthFirstTraversal(Graph *g, int u, int *visited) {
    int i, j;
    int vertexDequeued;
    visited[u] = 1;
    enqueue(u);

    for (j = 0; j < g->nVertices; j++) {
        vertexDequeued = dequeue();

        if (vertexDequeued == INT_MIN)
            return;

        printf(" %d", vertexDequeued);

        for (i = 0; i < g->nVertices; i++) {
            if ((g->adjMatrix[vertexDequeued][i]) && (!(visited[i]))) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void depthFirstTraversal(Graph *g, int u, int *visited) {
    int i;
    visited[u] = 1;
    printf(" %d", u);
    for (i = 0; i < g->nVertices; i++) {
        if ((g->adjMatrix[u][i]) && (!(visited[i]))) {
            depthFirstTraversal(g, i, visited);
        }
    }
}

int main(void) {
    Graph *g = NULL;
    int *visited;

    g = createAdjMatrixOfGraph(g);
    printGraph(g);

    visited = (int *)malloc(g->nVertices * sizeof(int));

    printf("\nBreadth First Traversal of the graph: ");
    breadthFirstTraversal(g, 2, visited);

    for (int i = 0; i < g->nVertices; i++)
        visited[i] = 0;

    printf("\nDepth First Traversal of the graph: ");
    depthFirstTraversal(g, 2, visited);

    return 0;
}
