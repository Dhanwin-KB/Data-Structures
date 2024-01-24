#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ExpenseNode
{
    int expenseID;
    char expenseCategory[50];
    double expenseAmount;
    struct ExpenseNode *left;
    struct ExpenseNode *right;
};

struct ExpenseNode *createExpenseNode(int expenseID, const char *expenseCategory, double expenseAmount)
{
    struct ExpenseNode *newNode = (struct ExpenseNode *)malloc(sizeof(struct ExpenseNode));
    newNode->expenseID = expenseID;
    strcpy(newNode->expenseCategory, expenseCategory);
    newNode->expenseAmount = expenseAmount;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct ExpenseNode *insertExpense(struct ExpenseNode *root, int expenseID, const char *expenseCategory, double expenseAmount)
{
    if (root == NULL)
    {
        return createExpenseNode(expenseID, expenseCategory, expenseAmount);
    }

    if (expenseID < root->expenseID)
    {
        root->left = insertExpense(root->left, expenseID, expenseCategory, expenseAmount);
    }
    else if (expenseID > root->expenseID)
    {
        root->right = insertExpense(root->right, expenseID, expenseCategory, expenseAmount);
    }

    return root;
}

void inorderExpenseTraversal(struct ExpenseNode *root)
{
    if (root != NULL)
    {
        inorderExpenseTraversal(root->left);
        printf("Expense ID: %d, Category: %s, Amount: $%.2f\n", root->expenseID, root->expenseCategory, root->expenseAmount);
        inorderExpenseTraversal(root->right);
    }
}

double calculateTotalExpenses(struct ExpenseNode *root)
{
    if (root == NULL)
    {
        return 0.0;
    }

    return root->expenseAmount + calculateTotalExpenses(root->left) + calculateTotalExpenses(root->right);
}

struct ExpenseNode *deleteExpense(struct ExpenseNode *root, int expenseID)
{
    if (root == NULL)
    {
        return root;
    }

    if (expenseID < root->expenseID)
    {
        root->left = deleteExpense(root->left, expenseID);
    }
    else if (expenseID > root->expenseID)
    {
        root->right = deleteExpense(root->right, expenseID);
    }
    else
    {
        if (root->left == NULL)
        {
            struct ExpenseNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct ExpenseNode *temp = root->left;
            free(root);
            return temp;
        }

        struct ExpenseNode *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->expenseID = temp->expenseID;
        strcpy(root->expenseCategory, temp->expenseCategory);
        root->expenseAmount = temp->expenseAmount;

        root->right = deleteExpense(root->right, temp->expenseID);
    }

    return root;
}

struct ExpenseNode *searchExpense(struct ExpenseNode *root, int expenseID)
{
    if (root == NULL || root->expenseID == expenseID)
    {
        return root;
    }

    if (expenseID < root->expenseID)
    {
        return searchExpense(root->left, expenseID);
    }

    return searchExpense(root->right, expenseID);
}

void freeExpenseSystem(struct ExpenseNode *root)
{
    if (root != NULL)
    {
        freeExpenseSystem(root->left);
        freeExpenseSystem(root->right);
        free(root);
    }
}

int displayMenu()
{
    int choice;
    printf("\nPersonal Finance Tracking System Menu:\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Search Expense\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    struct ExpenseNode *expenseSystemRoot = NULL;

    int choice;
    do
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
        {
            int numExpenses;
            printf("Enter the number of expenses to add: ");
            scanf("%d", &numExpenses);

            for (int i = 0; i < numExpenses; ++i)
            {
                int expenseID;
                char expenseCategory[50];
                double expenseAmount;
                printf("Enter Expense ID for expense %d: ", i + 1);
                scanf("%d", &expenseID);
                printf("Enter Expense Category for expense %d: ", i + 1);
                scanf("%s", expenseCategory);
                printf("Enter Expense Amount for expense %d: $", i + 1);
                scanf("%lf", &expenseAmount);
                expenseSystemRoot = insertExpense(expenseSystemRoot, expenseID, expenseCategory, expenseAmount);
            }
            break;
        }
        case 2:
            printf("Expense Traversal:\n");
            inorderExpenseTraversal(expenseSystemRoot);
            printf("\n");
            break;

        case 3:
            printf("Total Expenses: $%.2f\n", calculateTotalExpenses(expenseSystemRoot));
            break;

        case 4:
        {
            int expenseToDelete;
            printf("Enter Expense ID to delete: ");
            scanf("%d", &expenseToDelete);

            struct ExpenseNode *expenseBeforeDelete = searchExpense(expenseSystemRoot, expenseToDelete);

            if (expenseBeforeDelete != NULL)
            {
                expenseSystemRoot = deleteExpense(expenseSystemRoot, expenseToDelete);
                printf("Expense ID %d deleted successfully.\n", expenseToDelete);
            }
            else
            {
                printf("Expense ID %d not found! Deletion failed.\n", expenseToDelete);
            }
            break;
        }

        case 5:
        {
            int expenseToSearch;
            printf("Enter Expense ID to search: ");
            scanf("%d", &expenseToSearch);
            struct ExpenseNode *foundExpense = searchExpense(expenseSystemRoot, expenseToSearch);
            if (foundExpense != NULL)
            {
                printf("Expense ID %d found: Category: %s, Amount: $%.2f\n", expenseToSearch, foundExpense->expenseCategory, foundExpense->expenseAmount);
            }
            else
            {
                printf("Expense ID %d not found!\n", expenseToSearch);
            }
            break;
        }

        case 6:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    freeExpenseSystem(expenseSystemRoot);

    return 0;
}
