#include <stdio.h>
#include <limits.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (Insertion)
void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

// Insert
void insert(int key) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }
    heap[size] = key;
    size++;
    heapifyUp(size - 1);
}

// Heapify Down (Deletion)
void heapifyDown(int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < size && heap[l] < heap[smallest])
        smallest = l;

    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Get Min
int getMin() {
    if (size <= 0)
        return INT_MAX;
    return heap[0];
}

// Extract Min
int extractMin() {
    if (size <= 0)
        return INT_MAX;

    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

// Delete element at index
void deleteKey(int i) {
    if (i >= size)
        return;

    heap[i] = INT_MIN;
    heapifyUp(i);
    extractMin();
}

// Build Heap
void buildHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];
    }
    size = n;

    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

// Print Heap
void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main Function (Demo)
int main() {
    insert(10);
    insert(5);
    insert(30);
    insert(2);
    insert(8);

    printf("Heap: ");
    printHeap();

    printf("Minimum: %d\n", getMin());

    printf("Extracted Min: %d\n", extractMin());

    printf("Heap after extraction: ");
    printHeap();

    deleteKey(2);

    printf("Heap after deletion: ");
    printHeap();

    return 0;
}