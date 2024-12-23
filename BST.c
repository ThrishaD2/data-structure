#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int key;
    struct Node* left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert node into BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into BST: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST\n", value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
\\\\\\\output\\\\\\
1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert into BST: 10
10 inserted into the BST

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert into BST: 20
20 inserted into the BST

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert into BST: 30
30 inserted into the BST

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert into BST: 40
40 inserted into the BST

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 2
Inorder Traversal: 10 20 30 40

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 3
Preorder Traversal: 10 20 30 40

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 4
Postorder Traversal: 40 30 20 10

1. Insert node into BST
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 5

Process returned 0 (0x0)   execution time : 21.329 s
Press any key to continue.
