#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_ISLANDS 50

typedef struct {
    int cost;
    int island;
    int mode;
} State;

typedef struct {
    State *states;
    int size;
} PriorityQueue;

void swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue *queue, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < queue->size && queue->states[left].cost < queue->states[smallest].cost) {
        smallest = left;
    }

    if (right < queue->size && queue->states[right].cost < queue->states[smallest].cost) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&queue->states[i], &queue->states[smallest]);
        heapify(queue, smallest);
    }
}

void push(PriorityQueue *queue, State state) {
    queue->states[queue->size] = state;
    queue->size++;

    int i = queue->size - 1;
    while (i > 0 && queue->states[(i - 1) / 2].cost > queue->states[i].cost) {
        swap(&queue->states[i], &queue->states[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

State pop(PriorityQueue *queue) {
    if (queue->size == 0) {
        State empty = {INF, -1, -1};
        return empty;
    }

    State root = queue->states[0];
    queue->states[0] = queue->states[queue->size - 1];
    queue->size--;
    heapify(queue, 0);

    return root;
}

int find_min_cost(int matrix[MAX_ISLANDS][MAX_ISLANDS], int n, int start, int end) {
    PriorityQueue queue;
    queue.states = malloc(n * n * 3 * sizeof(State)); // Considering 3 modes per state per island
    queue.size = 0;

    int cost[n][3];
    bool visited[n][3];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cost[i][j] = INF;
            visited[i][j] = false;
        }
    }

    for (int mode = 0; mode < 3; mode++) {
        cost[start][mode] = 0;
        push(&queue, (State){0, start, mode});
    }

    while (queue.size > 0) {
        State current = pop(&queue);

        if (current.island == end) {
            free(queue.states);
            return current.cost;
        }

        if (visited[current.island][current.mode]) {
            continue;
        }

        visited[current.island][current.mode] = true;

        for (int i = 0; i < n; i++) {
            if (matrix[current.island][i] > 0) {
                int new_cost = current.cost + matrix[current.island][i];
                for (int new_mode = 0; new_mode < 3; new_mode++) {
                    if (new_mode != current.mode) {
                        if (new_cost < cost[i][new_mode]) {
                            cost[i][new_mode] = new_cost;
                            push(&queue, (State){new_cost, i, new_mode});
                        }
                    }
                }
            }
        }
    }

    free(queue.states);
    return -1;
}

int main() {
    int N, A, B;
    if (scanf("%d %d %d", &N, &A, &B) != 3) return 1;

    int matrix[MAX_ISLANDS][MAX_ISLANDS];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) return 1;
        }
    }

    int result = find_min_cost(matrix, N, A, B);
    printf("%d\n", result);

    return 0;
}