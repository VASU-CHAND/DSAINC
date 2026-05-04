#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------- Adjacency Matrix ----------
int adjMatrix[MAX][MAX];
int vertices;

// ---------- Adjacency List ----------
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdgeList(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// ---------- Display Adjacency Matrix ----------
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ---------- Display Adjacency List ----------
void displayList() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = adjList[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ---------- DFS ----------
int visitedDFS[MAX];

void DFS(int v) {
    visitedDFS[v] = 1;
    printf("%d ", v);

    struct Node* temp = adjList[v];
    while (temp) {
        if (!visitedDFS[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

// ---------- BFS ----------
int visitedBFS[MAX];

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    visitedBFS[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adjList[v];
        while (temp) {
            if (!visitedBFS[temp->vertex]) {
                visitedBFS[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

// ---------- Main ----------
int main() {
    int edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize structures
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);

        // Matrix
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;

        // List
        addEdgeList(src, dest);
    }

    // Display
    displayMatrix();
    displayList();

    // DFS
    for (int i = 0; i < vertices; i++) visitedDFS[i] = 0;

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(start);

    // BFS
    for (int i = 0; i < vertices; i++) visitedBFS[i] = 0;

    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}