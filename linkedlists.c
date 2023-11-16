#include <stdio.h>
#include <stdlib.h>
struct Expense 
{
    int expenseId;
    float amount;
    struct Expense *next;
    struct Expense *prev; 
};
struct Expense* SLLhead = NULL;      
struct Expense* DLLhead = NULL;      
struct Expense* CLLhead = NULL;    
struct Expense* DCLLhead = NULL; 
void SLLinsertatbeginning(int id, float amt)  
{  
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));  
    if (newNode == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        newNode->expenseId = id;
        newNode->amount = amt;   
        newNode->next = SLLhead;
        SLLhead = newNode;  
        printf("\nNode inserted\n");  
    }     
}
void SLLinsertatposition(int id, float amt, int position) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;
    if (position == 1 || SLLhead == NULL) 
    {
        newNode->next = SLLhead;
        SLLhead = newNode;
    } 
    else 
    {
        struct Expense *temp = SLLhead;
        for (int i = 1; i < position - 1 && temp != NULL; i++) 
        {
            temp = temp->next;
        }
        if (temp == NULL) 
        {
            printf("\nPosition out of bounds\n");
            free(newNode); 
        }
        else 
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    printf("\nNode inserted\n");
}
void SLLinsertatend(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;
    newNode->next = NULL;
    if (SLLhead == NULL) 
    {
        SLLhead = newNode;
    } 
    else 
    {
        struct Expense *temp = SLLhead;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nNode inserted\n");
}
void SLLdeleteatbeginning() 
{
    if (SLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct Expense *temp = SLLhead;
    SLLhead = SLLhead->next;
    free(temp);
    printf("\nNode deleted from the beginning\n");
}
void SLLdeleteatposition(int position) 
{
    if (SLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    if (position == 1) 
    {
        struct Expense *temp = SLLhead;
        SLLhead = SLLhead->next;
        free(temp);
        printf("\nNode deleted from position %d\n", position);
    } 
    else 
    {
        struct Expense *temp = SLLhead;
        int currentPosition = 1;
        while (temp != NULL && currentPosition < position - 1) 
        {
            temp = temp->next;
            currentPosition++;
        }
        if (temp == NULL || temp->next == NULL) 
        {
            printf("\nPosition out of bounds\n");
        } 
        else 
        {
            struct Expense *deleteNode = temp->next;
            temp->next = temp->next->next;
            free(deleteNode);
            printf("\nNode deleted from position %d\n", position);
        }
    }
}
void SLLdeleteatend() 
{
    if (SLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    if (SLLhead->next == NULL) 
    {
        free(SLLhead);
        SLLhead = NULL;
    } 
    else 
    {
        struct Expense *temp = SLLhead;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("\nNode deleted from the end\n");
}
struct Expense* SLLsearch(int searchKey) 
{
    struct Expense *temp = SLLhead;
    while (temp != NULL) 
    {
        if (temp->expenseId == searchKey) 
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void SLLupdate(int newId, float newAmt, int position) 
{
    if (SLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }

    struct Expense *temp = SLLhead;
    int currentPosition = 1;

    while (temp != NULL && currentPosition < position) 
    {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) 
    {
        printf("\nPosition out of bounds\n");
    } 
    else 
    {
        temp->expenseId = newId;
        temp->amount = newAmt;
        printf("\nNode updated at position %d\n", position);
    }
}
void SLLsort() 
{
    struct Expense *currentNode, *nextNode;
    int tempId;
    float tempAmt;
    if (SLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    for (currentNode = SLLhead; currentNode != NULL; currentNode = currentNode->next) 
    {
        for (nextNode = currentNode->next; nextNode != NULL; nextNode = nextNode->next) 
        {
            if (currentNode->expenseId > nextNode->expenseId) 
            {
                tempId = currentNode->expenseId;
                currentNode->expenseId = nextNode->expenseId;
                nextNode->expenseId = tempId;

                tempAmt = currentNode->amount;
                currentNode->amount = nextNode->amount;
                nextNode->amount = tempAmt;
            }
        }
    }
    printf("\nList sorted in ascending order by expense ID\n");
}
void SLLdisplay() 
{
    if (SLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    struct Expense *temp = SLLhead;
    printf("Singly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d (%.2f) -> ", temp->expenseId, temp->amount);
        temp = temp->next;
    }
    printf("NULL\n");
}
void DLLinsertatbeginning(int id, float amt)  
{  
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));  
    if (newNode == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        newNode->expenseId = id;
        newNode->amount = amt;   
        newNode->next = DLLhead;
        newNode->prev = NULL;
        if (DLLhead != NULL) {
            DLLhead->prev = newNode;
        }
        DLLhead = newNode;  
        printf("\nNode inserted\n");  
    }     
}
void DLLinsertatposition(int id, float amt, int position) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;

    if (position == 1 || DLLhead == NULL) 
    {
        newNode->next = DLLhead;
        newNode->prev = NULL;
        if (DLLhead != NULL) {
            DLLhead->prev = newNode;
        }
        DLLhead = newNode;
    } 
    else 
    {
        struct Expense *temp = DLLhead;
        for (int i = 1; i < position - 1 && temp != NULL; i++) 
        {
            temp = temp->next;
        }
        if (temp == NULL) 
        {
            printf("\nPosition out of bounds\n");
            free(newNode); 
        }
        else 
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
    printf("\nNode inserted\n");
}
void DLLinsertatend(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;
    newNode->next = NULL;

    if (DLLhead == NULL) 
    {
        newNode->prev = NULL;
        DLLhead = newNode;
    } 
    else 
    {
        struct Expense *temp = DLLhead;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nNode inserted\n");
}
void DLLdeleteatbeginning() 
{
    if (DLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct Expense *temp = DLLhead;
    DLLhead = DLLhead->next;
    if (DLLhead != NULL) {
        DLLhead->prev = NULL;
    }
    free(temp);
    printf("\nNode deleted from the beginning\n");
}
void DLLdeleteatposition(int position) 
{
    if (DLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    if (position == 1) 
    {
        struct Expense *temp = DLLhead;
        DLLhead = DLLhead->next;
        if (DLLhead != NULL) {
            DLLhead->prev = NULL;
        }
        free(temp);
        printf("\nNode deleted from position %d\n", position);
    } 
    else 
    {
        struct Expense *temp = DLLhead;
        int currentPosition = 1;
        while (temp != NULL && currentPosition < position - 1) 
        {
            temp = temp->next;
            currentPosition++;
        }
        if (temp == NULL || temp->next == NULL) 
        {
            printf("\nPosition out of bounds\n");
        } 
        else 
        {
            struct Expense *deleteNode = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL) {
                temp->next->prev = temp;
            }
            free(deleteNode);
            printf("\nNode deleted from position %d\n", position);
        }
    }
}
void DLLdeleteatend() 
{
    if (DLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    if (DLLhead->next == NULL) 
    {
        free(DLLhead);
        DLLhead = NULL;
    } 
    else 
    {
        struct Expense *temp = DLLhead;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("\nNode deleted from the end\n");
}
struct Expense* DLLsearch(int searchKey) 
{
    struct Expense *temp = DLLhead;
    while (temp != NULL) 
    {
        if (temp->expenseId == searchKey) 
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void DLLupdate(int newId, float newAmt, int position) 
{
    if (DLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }

    struct Expense *temp = DLLhead;
    int currentPosition = 1;

    while (temp != NULL && currentPosition < position) 
    {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) 
    {
        printf("\nPosition out of bounds\n");
    } 
    else 
    {
        temp->expenseId = newId;
        temp->amount = newAmt;
        printf("\nNode updated at position %d\n", position);
    }
}
void DLLsort() 
{
    struct Expense *currentNode, *nextNode;
    int tempId;
    float tempAmt;
    if (DLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    for (currentNode = DLLhead; currentNode != NULL; currentNode = currentNode->next) 
    {
        for (nextNode = currentNode->next; nextNode != NULL; nextNode = nextNode->next) 
        {
            if (currentNode->expenseId > nextNode->expenseId) 
            {
                tempId = currentNode->expenseId;
                currentNode->expenseId = nextNode->expenseId;
                nextNode->expenseId = tempId;

                tempAmt = currentNode->amount;
                currentNode->amount = nextNode->amount;
                nextNode->amount = tempAmt;
            }
        }
    }
    printf("\nList sorted in ascending order by expense ID\n");
}
void DLLdisplay() 
{
    if (DLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    struct Expense *temp = DLLhead;
    printf("Doubly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d (%.2f) <-> ", temp->expenseId, temp->amount);
        temp = temp->next;
    }
    printf("NULL\n");
}
void CLLinsertatbeginning(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
    } 
    else 
    {
        newNode->expenseId = id;
        newNode->amount = amt;
        if (CLLhead == NULL) 
        {
            newNode->next = newNode;
        } 
        else 
        {
            struct Expense *last = CLLhead;
            while (last->next != CLLhead) 
            {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = CLLhead;
        }
        CLLhead = newNode;
        printf("\nNode inserted\n");
    }
}
void CLLinsertatposition(int id, float amt, int position) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;
    if (position == 1 || CLLhead == NULL) 
    {
        CLLinsertatbeginning(id, amt);
        return;
    }
    struct Expense *temp = CLLhead;
    for (int i = 1; i < position - 1 && temp->next != CLLhead; i++) 
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\nNode inserted\n");
}
void CLLinsertatend(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
        return;
    }
    newNode->expenseId = id;
    newNode->amount = amt;
    if (CLLhead == NULL) 
    {
        newNode->next = newNode;
        CLLhead = newNode;
    } 
    else 
    {
        struct Expense *last = CLLhead;
        while (last->next != CLLhead) 
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = CLLhead;
    }
    printf("\nNode inserted\n");
}
void CLLdeleteatbeginning() 
{
    if (CLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct Expense *temp = CLLhead;
    if (temp->next == temp) 
    {
        free(temp);
        CLLhead = NULL;
    } 
    else 
    {
        while (temp->next != CLLhead) 
        {
            temp = temp->next;
        }
        temp->next = CLLhead->next;
        free(CLLhead);
        CLLhead = temp->next;
    }
    printf("\nNode deleted from the beginning\n");
}
void CLLdeleteatposition(int position) 
{
    if (CLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct Expense *temp = CLLhead;
    if (position == 1) 
    {
        CLLdeleteatbeginning();
        return;
    }
    for (int i = 1; i < position - 1 && temp->next != CLLhead; i++) 
    {
        temp = temp->next;
    }
    if (temp->next == CLLhead) 
    {
        printf("\nPosition out of bounds\n");
    } 
    else 
    {
        struct Expense *deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
        printf("\nNode deleted from position %d\n", position);
    }
}
void CLLdeleteatend() 
{
    if (CLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct Expense *temp = CLLhead;
    if (temp->next == temp) 
    {
        free(temp);
        CLLhead = NULL;
    } 
    else 
    {
        struct Expense *prev = NULL;
        while (temp->next != CLLhead) 
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = CLLhead;
        free(temp);
    }
    printf("\nNode deleted from the end\n");
}
struct Expense* CLLsearch(int searchKey) 
{
    struct Expense *temp = CLLhead;
    if (temp == NULL) 
    {
        return NULL;
    }
    do 
    {
        if (temp->expenseId == searchKey) 
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != CLLhead);
    return NULL;
}
void CLLupdate(int newId, float newAmt, int position) 
{
    if (CLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    struct Expense *temp = CLLhead;
    int currentPosition = 1;
    do 
    {
        if (currentPosition == position) 
        {
            temp->expenseId = newId;
            temp->amount = newAmt;
            printf("\nNode updated at position %d\n", position);
            return;
        }
        temp = temp->next;
        currentPosition++;
    } while (temp != CLLhead);
    printf("\nPosition out of bounds\n");
}
void CLLsort() 
{
    struct Expense *currentNode, *nextNode;
    int tempId;
    float tempAmt;
    if (CLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    struct Expense *last = CLLhead;
    do 
    {
        for (currentNode = CLLhead; currentNode->next != last; currentNode = currentNode->next) 
        {
            nextNode = currentNode->next;
            if (currentNode->expenseId > nextNode->expenseId) 
            {
                tempId = currentNode->expenseId;
                currentNode->expenseId = nextNode->expenseId;
                nextNode->expenseId = tempId;

                tempAmt = currentNode->amount;
                currentNode->amount = nextNode->amount;
                nextNode->amount = tempAmt;
            }
        }
        last = currentNode;
    } while (last->next != CLLhead);
    printf("\nList sorted in ascending order by expense ID\n");
}
void CLLdisplay() 
{
    if (CLLhead == NULL) 
    {
        printf("\nList is empty\n");
        return;
    }
    struct Expense *temp = CLLhead;
    do 
    {
        printf("%d (%.2f) -> ", temp->expenseId, temp->amount);
        temp = temp->next;
    } while (temp != CLLhead);
    printf("Head\n");
}
void DCLLinsertatbeginning(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
    } 
    else 
    {
        newNode->expenseId = id;
        newNode->amount = amt;
        if (DCLLhead == NULL) 
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            DCLLhead = newNode;
        } 
        else 
        {
            struct Expense *lastNode = DCLLhead->prev;
            newNode->next = DCLLhead;
            newNode->prev = lastNode;
            DCLLhead->prev = newNode;
            lastNode->next = newNode;
            DCLLhead = newNode;
        }
        printf("\nNode inserted\n");
    }
}
void DCLLinsertatposition(int id, float amt, int position) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
    } 
    else 
    {
        newNode->expenseId = id;
        newNode->amount = amt;

        if (position == 1 || DCLLhead == NULL) 
        {
            DCLLinsertatbeginning(id, amt);
        } 
        else 
        {
            struct Expense *temp = DCLLhead;
            for (int i = 1; i < position - 1 && temp->next != DCLLhead; i++) 
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            printf("\nNode inserted\n");
        }
    }
}
void DCLLinsertatend(int id, float amt) 
{
    struct Expense *newNode = (struct Expense *)malloc(sizeof(struct Expense));
    if (newNode == NULL) 
    {
        printf("\nOVERFLOW\n");
    } 
    else 
    {
        newNode->expenseId = id;
        newNode->amount = amt;
        if (DCLLhead == NULL) 
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            DCLLhead = newNode;
        } 
        else 
        {
            struct Expense *lastNode = DCLLhead->prev;
            newNode->next = DCLLhead;
            newNode->prev = lastNode;
            DCLLhead->prev = newNode;
            lastNode->next = newNode;
        }
        printf("\nNode inserted\n");
    }
}
void DCLLdeleteatbeginning() 
{
    if (DCLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
    } 
    else 
    {
        struct Expense *temp = DCLLhead;
        if (DCLLhead->next == DCLLhead) 
        {
            DCLLhead = NULL;
        } 
        else 
        {
            DCLLhead = DCLLhead->next;
            DCLLhead->prev = temp->prev;
            temp->prev->next = DCLLhead;
        }
        free(temp);
        printf("\nNode deleted from the beginning\n");
    }
}
void DCLLdeleteatposition(int position) 
{
    if (DCLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
    } 
    else 
    {
        if (position == 1) 
        {
            DCLLdeleteatbeginning();
        } 
        else 
        {
            struct Expense *temp = DCLLhead;
            for (int i = 1; i < position - 1 && temp->next != DCLLhead; i++) 
            {
                temp = temp->next;
            }
            if (temp->next == DCLLhead) 
            {
                printf("\nPosition out of bounds\n");
            } 
            else 
            {
                struct Expense *deleteNode = temp->next;
                temp->next = deleteNode->next;
                deleteNode->next->prev = temp;
                free(deleteNode);
                printf("\nNode deleted from position %d\n", position);
            }
        }
    }
}
void DCLLdeleteatend() 
{
    if (DCLLhead == NULL) 
    {
        printf("\nUNDERFLOW\n");
    } 
    else 
    {
        struct Expense *lastNode = DCLLhead->prev;
        if (DCLLhead->next == DCLLhead) 
        {
            free(DCLLhead);
            DCLLhead = NULL;
        } 
        else 
        {
            lastNode->prev->next = DCLLhead;
            DCLLhead->prev = lastNode->prev;
            free(lastNode);
        }
        printf("\nNode deleted from the end\n");
    }
}
struct Expense *DCLLsearch(int searchKey) 
{
    struct Expense *temp = DCLLhead;
    while (temp != NULL && temp->next != DCLLhead) 
    {
        if (temp->expenseId == searchKey) 
        {
            return temp;
        }
        temp = temp->next;
    }
    if (temp->expenseId == searchKey) 
    {
        return temp;
    }
    return NULL;
}
void DCLLupdateatbeginning(int newId, float newAmt) 
{
    if (DCLLhead == NULL) 
    {
        printf("\nList is empty\n");
    } 
    else 
    {
        DCLLhead->expenseId = newId;
        DCLLhead->amount = newAmt;
        printf("\nNode updated at the beginning\n");
    }
}
void DCLLupdate(int newId, float newAmt, int position) 
{
    if (DCLLhead == NULL) 
    {
        printf("\nList is empty\n");
    } 
    else 
    {
        if (position == 1) 
        {
            DCLLupdateatbeginning(newId, newAmt);
        } 
        else 
        {
            struct Expense *temp = DCLLhead;
            for (int i = 1; i < position && temp->next != DCLLhead; i++) 
            {
                temp = temp->next;
            }
            if (temp->next == DCLLhead) 
            {
                printf("\nPosition out of bounds\n");
            } 
            else 
            {
                temp->expenseId = newId;
                temp->amount = newAmt;
                printf("\nNode updated at position %d\n", position);
            }
        }
    }
}
void DCLLsort() 
{
    struct Expense *currentNode, *nextNode;
    int tempId;
    float tempAmt;
    int swapped;
    if (DCLLhead == NULL) 
    {
        printf("\nList is empty\n");
    } 
    else 
    {
        struct Expense *start = DCLLhead;
        do 
        {
            int swapped = 0;
            currentNode = start;
            do 
            {
                nextNode = currentNode->next;
                if (currentNode->expenseId > nextNode->expenseId) 
                {
                    tempId = currentNode->expenseId;
                    currentNode->expenseId = nextNode->expenseId;
                    nextNode->expenseId = tempId;

                    tempAmt = currentNode->amount;
                    currentNode->amount = nextNode->amount;
                    nextNode->amount = tempAmt;

                    swapped = 1;
                }
                currentNode = currentNode->next;
            } while (currentNode != start);
            start = currentNode;
        } while (swapped);
        printf("\nList sorted in ascending order by expense ID\n");
    }
}
void DCLLdisplay() 
{
    if (DCLLhead == NULL) 
    {
        printf("\nList is empty\n");
    } 
    else 
    {
        struct Expense *temp = DCLLhead;
        do 
        {
            printf("%d (%.2f) <-> ", temp->expenseId, temp->amount);
            temp = temp->next;
        } while (temp != DCLLhead);
        printf("\n");
    }
}
void main()  
{  
    int mainChoice, subChoice, id, position;
    float amt, newAmt;
    struct Expense *searchResult;
    do {
        printf("\n******** Main Menu ********");
        printf("\n1. Singly Linked List");
        printf("\n2. Doubly Linked List");
        printf("\n3. Circular Linked List");
        printf("\n4. Double Circular Linked List");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice) 
        {
            case 1:
                do 
                {
                    printf("\n******** Singly Linked List Menu ********");
                    printf("\n1. Insert at Beginning");
                    printf("\n2. Insert at Position");
                    printf("\n3. Insert at End");
                    printf("\n4. Delete at Beginning");
                    printf("\n5. Delete at Position");
                    printf("\n6. Delete at End");
                    printf("\n7. Search");
                    printf("\n8. Update at Position");
                    printf("\n9. Sort");
                    printf("\n10. Display");
                    printf("\n0. Go Back");
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) 
                    {
                        case 1:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            SLLinsertatbeginning(id, amt);
                            break;
                        case 2:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            SLLinsertatposition(id, amt, position);
                            break;
                        case 3:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            SLLinsertatend(id, amt);
                            break;
                        case 4:
                            SLLdeleteatbeginning();
                            break;
                        case 5:
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            SLLdeleteatposition(position);
                            break;
                        case 6:
                            SLLdeleteatend();
                            break;
                        case 7:
                            printf("Enter Expense ID to search: ");
                            scanf("%d", &id);
                            searchResult = SLLsearch(id);
                            if (searchResult != NULL) {
                                printf("Node found: %d (%.2f)\n", searchResult->expenseId, searchResult->amount);
                            } else {
                                printf("Node not found\n");
                            }
                            break;
                        case 8:
                            printf("Enter New Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter New Amount: ");
                            scanf("%f", &newAmt);
                            printf("Enter Position to Update: ");
                            scanf("%d", &position);
                            SLLupdate(id, newAmt, position);
                            break;
                        case 9:
                            SLLsort();
                            break;
                        case 10:
                            SLLdisplay();
                            break;
                        case 0:
                            printf("Going back to the main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 2:
                do 
                {
                    printf("\n******** Doubly Linked List Menu ********");
                    printf("\n1. Insert at Beginning");
                    printf("\n2. Insert at Position");
                    printf("\n3. Insert at End");
                    printf("\n4. Delete at Beginning");
                    printf("\n5. Delete at Position");
                    printf("\n6. Delete at End");
                    printf("\n7. Search");
                    printf("\n8. Update at Position");
                    printf("\n9. Sort");
                    printf("\n10. Display");
                    printf("\n0. Go Back");
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) 
                    {
                        case 1:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            DLLinsertatbeginning(id, amt);
                            break;
                        case 2:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            DLLinsertatposition(id, amt, position);
                            break;
                        case 3:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            DLLinsertatend(id, amt);
                            break;
                        case 4:
                            DLLdeleteatbeginning();
                            break;
                        case 5:
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            DLLdeleteatposition(position);
                            break;
                        case 6:
                            DLLdeleteatend();
                            break;
                        case 7:
                            printf("Enter Expense ID to search: ");
                            scanf("%d", &id);
                            searchResult = DLLsearch(id);
                            if (searchResult != NULL) {
                                printf("Node found: %d (%.2f)\n", searchResult->expenseId, searchResult->amount);
                            } else {
                                printf("Node not found\n");
                            }
                            break;
                        case 8:
                            printf("Enter New Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter New Amount: ");
                            scanf("%f", &newAmt);
                            printf("Enter Position to Update: ");
                            scanf("%d", &position);
                            DLLupdate(id, newAmt, position);
                            break;
                        case 9:
                            DLLsort();
                            break;
                        case 10:
                            DLLdisplay();
                            break;
                        case 0:
                            printf("Going back to the main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 3:
                do 
                {
                    printf("\n******** Circular Linked List Menu ********");
                    printf("\n1. Insert at Beginning");
                    printf("\n2. Insert at Position");
                    printf("\n3. Insert at End");
                    printf("\n4. Delete at Beginning");
                    printf("\n5. Delete at Position");
                    printf("\n6. Delete at End");
                    printf("\n7. Search");
                    printf("\n8. Update at Position");
                    printf("\n9. Sort");
                    printf("\n10. Display");
                    printf("\n0. Go Back");
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) 
                    {
                        case 1:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            CLLinsertatbeginning(id, amt);
                            break;
                        case 2:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            CLLinsertatposition(id, amt, position);
                            break;
                        case 3:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            CLLinsertatend(id, amt);
                            break;
                        case 4:
                            CLLdeleteatbeginning();
                            break;
                        case 5:
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            CLLdeleteatposition(position);
                            break;
                        case 6:
                            CLLdeleteatend();
                            break;
                        case 7:
                            printf("Enter Expense ID to search: ");
                            scanf("%d", &id);
                            searchResult = CLLsearch(id);
                            if (searchResult != NULL) {
                                printf("Node found: %d (%.2f)\n", searchResult->expenseId, searchResult->amount);
                            } else {
                                printf("Node not found\n");
                            }
                            break;
                        case 8:
                            printf("Enter New Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter New Amount: ");
                            scanf("%f", &newAmt);
                            printf("Enter Position to Update: ");
                            scanf("%d", &position);
                            CLLupdate(id, newAmt, position);
                            break;
                        case 9:
                            CLLsort();
                            break;
                        case 10:
                            CLLdisplay();
                            break;
                        case 0:
                            printf("Going back to the main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 4:
                do 
                {
                    printf("\n******** Doubly Circular Linked List Menu ********");
                    printf("\n1. Insert at Beginning");
                    printf("\n2. Insert at Position");
                    printf("\n3. Insert at End");
                    printf("\n4. Delete at Beginning");
                    printf("\n5. Delete at Position");
                    printf("\n6. Delete at End");
                    printf("\n7. Search");
                    printf("\n8. Update at Position");
                    printf("\n9. Sort");
                    printf("\n10. Display");
                    printf("\n0. Go Back");
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) 
                    {
                        case 1:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            DCLLinsertatbeginning(id, amt);
                            break;
                        case 2:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            DCLLinsertatposition(id, amt, position);
                            break;
                        case 3:
                            printf("Enter Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter Amount: ");
                            scanf("%f", &amt);
                            DCLLinsertatend(id, amt);
                            break;
                        case 4:
                            DCLLdeleteatbeginning();
                            break;
                        case 5:
                            printf("Enter Position: ");
                            scanf("%d", &position);
                            DCLLdeleteatposition(position);
                            break;
                        case 6:
                            DCLLdeleteatend();
                            break;
                        case 7:
                            printf("Enter Expense ID to search: ");
                            scanf("%d", &id);
                            searchResult = DCLLsearch(id);
                            if (searchResult != NULL) {
                                printf("Node found: %d (%.2f)\n", searchResult->expenseId, searchResult->amount);
                            } else {
                                printf("Node not found\n");
                            }
                            break;
                        case 8:
                            printf("Enter New Expense ID: ");
                            scanf("%d", &id);
                            printf("Enter New Amount: ");
                            scanf("%f", &newAmt);
                            printf("Enter Position to Update: ");
                            scanf("%d", &position);
                            DCLLupdate(id, newAmt, position);
                            break;
                        case 9:
                            DCLLsort();
                            break;
                        case 10:
                            DCLLdisplay();
                            break;
                        case 0:
                            printf("Going back to the main menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (mainChoice != 0);
}