#include <stdio.h>
#include <stdlib.h>

// ----------- Node Structure -----------
struct Node {
    int data;
    struct Node *left, *right;
};

// ----------- Create Node -----------
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ----------- Insert -----------
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// ----------- Search -----------
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ----------- Find Minimum -----------
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ----------- Delete Node -----------
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ----------- Traversals -----------
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// ----------- Find Max -----------
struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// ----------- Height -----------
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// ----------- Main Menu -----------
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Find Min\n");
        printf("8. Find Max\n");
        printf("9. Height\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Found!\n");
                else
                    printf("Not Found!\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                if (root)
                    printf("Min: %d\n", findMin(root)->data);
                break;

            case 8:
                if (root)
                    printf("Max: %d\n", findMax(root)->data);
                break;

            case 9:
                printf("Height: %d\n", height(root));
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}