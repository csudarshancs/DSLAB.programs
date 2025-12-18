#include <stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20], adj[20][20], n;

/* Insert element into queue */
void enqueue(int v) {
    if (rear == 19)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

/* Remove element from queue */
int dequeue() {
    return queue[front++];
}

/* BFS Function */
void bfs(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
