#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

// ================= HASH FUNCTION =================
int hash(int key) {
    return key % SIZE;
}

// ================= LINEAR PROBING =================
int linear[SIZE];

void initLinear() {
    for(int i=0;i<SIZE;i++) linear[i]=EMPTY;
}

void insertLinear(int key) {
    int i = hash(key);
    while(linear[i] != EMPTY && linear[i] != DELETED)
        i = (i + 1) % SIZE;
    linear[i] = key;
}

int searchLinear(int key) {
    int i = hash(key), start = i;
    while(linear[i] != EMPTY) {
        if(linear[i] == key) return i;
        i = (i + 1) % SIZE;
        if(i == start) break;
    }
    return -1;
}

void deleteLinear(int key) {
    int pos = searchLinear(key);
    if(pos != -1) linear[pos] = DELETED;
}

void displayLinear() {
    printf("\nLinear Probing:\n");
    for(int i=0;i<SIZE;i++)
        printf("%d: %d\n", i, linear[i]);
}

// ================= QUADRATIC PROBING =================
int quad[SIZE];

void initQuad() {
    for(int i=0;i<SIZE;i++) quad[i]=EMPTY;
}

void insertQuad(int key) {
    int i = hash(key), j=1;
    while(quad[i] != EMPTY && quad[i] != DELETED) {
        i = (hash(key) + j*j) % SIZE;
        j++;
    }
    quad[i] = key;
}

int searchQuad(int key) {
    int i = hash(key), j=1;
    while(quad[i] != EMPTY) {
        if(quad[i] == key) return i;
        i = (hash(key) + j*j) % SIZE;
        j++;
    }
    return -1;
}

void deleteQuad(int key) {
    int pos = searchQuad(key);
    if(pos != -1) quad[pos] = DELETED;
}

void displayQuad() {
    printf("\nQuadratic Probing:\n");
    for(int i=0;i<SIZE;i++)
        printf("%d: %d\n", i, quad[i]);
}

// ================= DOUBLE HASHING =================
int dbl[SIZE];

int hash2(int key) {
    return 7 - (key % 7);
}

void initDouble() {
    for(int i=0;i<SIZE;i++) dbl[i]=EMPTY;
}

void insertDouble(int key) {
    int i = hash(key), step = hash2(key);
    while(dbl[i] != EMPTY && dbl[i] != DELETED)
        i = (i + step) % SIZE;
    dbl[i] = key;
}

int searchDouble(int key) {
    int i = hash(key), step = hash2(key), start=i;
    while(dbl[i] != EMPTY) {
        if(dbl[i] == key) return i;
        i = (i + step) % SIZE;
        if(i == start) break;
    }
    return -1;
}

void deleteDouble(int key) {
    int pos = searchDouble(key);
    if(pos != -1) dbl[pos] = DELETED;
}

void displayDouble() {
    printf("\nDouble Hashing:\n");
    for(int i=0;i<SIZE;i++)
        printf("%d: %d\n", i, dbl[i]);
}

// ================= SEPARATE CHAINING =================
struct node {
    int data;
    struct node* next;
};

struct node* chain[SIZE];

void initChain() {
    for(int i=0;i<SIZE;i++) chain[i]=NULL;
}

void insertChain(int key) {
    int i = hash(key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = chain[i];
    chain[i] = newNode;
}

int searchChain(int key) {
    int i = hash(key);
    struct node* temp = chain[i];
    while(temp) {
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void deleteChain(int key) {
    int i = hash(key);
    struct node *temp = chain[i], *prev=NULL;

    while(temp) {
        if(temp->data == key) {
            if(prev) prev->next = temp->next;
            else chain[i] = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void displayChain() {
    printf("\nSeparate Chaining:\n");
    for(int i=0;i<SIZE;i++) {
        printf("%d: ", i);
        struct node* temp = chain[i];
        while(temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ================= MAIN =================
int main() {
    int keys[] = {23, 43, 13, 27, 88, 59};
    int n = 6;

    initLinear();
    initQuad();
    initDouble();
    initChain();

    for(int i=0;i<n;i++) {
        insertLinear(keys[i]);
        insertQuad(keys[i]);
        insertDouble(keys[i]);
        insertChain(keys[i]);
    }

    displayLinear();
    displayQuad();
    displayDouble();
    displayChain();

    printf("\nSearch 27 (Linear): %d\n", searchLinear(27));
    deleteLinear(27);
    printf("After deletion (Linear):\n");
    displayLinear();

    return 0;
}