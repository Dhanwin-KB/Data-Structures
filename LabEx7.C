#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char *decision;
    struct Node *yes;
    struct Node *no;
} Node;

Node *createNode(char *decision)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->decision = decision;
    newNode->yes = NULL;
    newNode->no = NULL;
    return newNode;
}

Node *insertLevelOrder(char *decisions[], int i, int n)
{
    if (i < n)
    {
        Node *temp = createNode(decisions[i]);

        temp->yes = insertLevelOrder(decisions, 2 * i + 1, n);
        temp->no = insertLevelOrder(decisions, 2 * i + 2, n);

        return temp;
    }
    return NULL;
}

void printTree(Node *node, int depth)
{
    if (node == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");
    printf("|-- %s\n", node->decision);

    printTree(node->yes, depth + 1);
    printTree(node->no, depth + 1);
}

void preOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        printf("%s ", node->decision);
        preOrderTraversal(node->yes);
        preOrderTraversal(node->no);
    }
}

void inOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->yes);
        printf("%s ", node->decision);
        inOrderTraversal(node->no);
    }
}

void postOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        postOrderTraversal(node->yes);
        postOrderTraversal(node->no);
        printf("%s ", node->decision);
    }
}

int main()
{
    int choice, n;
    char **decisions;

    printf("Enter the number of decisions: ");
    scanf("%d", &n);

    decisions = (char **)malloc(n * sizeof(char *));
    printf("Enter the decisions (each decision separated by a space):\n");
    for (int i = 0; i < n; i++)
    {
        decisions[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s", decisions[i]);
    }

    Node *root = NULL;

    printf("\nSelect Tree Creation Order:\n");
    printf("1. Level Order\n");
    printf("2. Depth Order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        root = insertLevelOrder(decisions, 0, n);
    }
    else if (choice == 2)
    {
        root = insertLevelOrder(decisions, 0, n);
    }
    else
    {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    printf("\nTree Structure:\n");
    printTree(root, 0);

    printf("\nTree Traversals:\n");
    printf("1. Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n2. In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n3. Post-order Traversal: ");
    postOrderTraversal(root);

    for (int i = 0; i < n; i++)
        free(decisions[i]);
    free(decisions);

    return 0;
}
