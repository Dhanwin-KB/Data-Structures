#include <stdio.h>
#include <stdlib.h>

struct Node {
    float expense;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(float expense) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->expense = expense;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, float expense) {
    if (root == NULL)
        return createNode(expense);

    if (expense < root->expense)
        root->left = insert(root->left, expense);
    else if (expense > root->expense)
        root->right = insert(root->right, expense);

    return root;
}

struct Node* search(struct Node* root, float expense) {
    if (root == NULL || root->expense == expense)
        return root;

    if (expense < root->expense)
        return search(root->left, expense);

    return search(root->right, expense);
}

int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%.2f ", root->expense);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%.2f ", root->expense);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%.2f ", root->expense);
    }
}

void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    float expense;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an expense\n");
        printf("2. Search for an expense\n");
        printf("3. Calculate BST height\n");
        printf("4. In-order traversal\n");
        printf("5. Pre-order traversal\n");
        printf("6. Post-order traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense amount: ");
                scanf("%f", &expense);
                root = insert(root, expense);
                break;
            case 2:
                printf("Enter expense to search: ");
                scanf("%f", &expense);
                if (search(root, expense))
                    printf("Expense found in the BST.\n");
                else
                    printf("Expense not found in the BST.\n");
                break;
            case 3:
                printf("BST height: %d\n", height(root));
                break;
            case 4:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                freeBST(root);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
