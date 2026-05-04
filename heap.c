#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (for max heap)
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Insert into heap
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow!\n");
        return;
    }

    heap[size] = value;
    int i = size;
    size++;

    // Heapify upwards
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Inserted: %d\n", value);
}

// Peek max element
void peek() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Max element: %d\n", heap[0]);
}

// Extract max
void extractMax() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Extracted Max: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapify(0);
}

// Delete element at index
void delete(int index) {
    if (index >= size) {
        printf("Invalid index!\n");
        return;
    }

    // Replace with last element
    heap[index] = heap[size - 1];
    size--;

    heapify(index);

    printf("Deleted element at index %d\n", index);
}

// Display heap
void display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main menu
int main() {
    int choice, value, index;

    while (1) {
        printf("\n--- HEAP OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete (by index)\n");
        printf("3. Peek Max\n");
        printf("4. Extract Max\n");
        printf("5. Display Heap\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delete(index);
                break;

            case 3:
                peek();
                break;

            case 4:
                extractMax();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}