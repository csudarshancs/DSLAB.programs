#include <stdio.h>

int adj[20][20], visited[20], stack[20];
int n, top = -1;

/* Push into stack */
void push(int v) {
    stack[++top] = v;
}

/* Pop from stack */
int pop() {
    return stack[top--];
}

/* DFS using stack */
void dfs(int start) {
    int i, v;
    push(start);
    visited[start] = 1;

    while (top != -1) {
        v = pop();

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, flag = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    /* Start DFS from vertex 0 */
    dfs(0);

    /* Check connectivity */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("Graph is CONNECTED\n");
    else
        printf("Graph is NOT CONNECTED\n");

    return 0;
}

