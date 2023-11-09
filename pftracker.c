// Domain was Personal Finance Tracker. Used 2D arrays to categorize expenses by type (food, leisure, travel).
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
struct user
{
    char name[50];
    int expenses[3][12];
    int m1avg,m2avg,m3avg,m4avg,m5avg,m6avg,m7avg,m8avg,m9avg,m10avg,m11avg,m12avg;
}user[5];
void insert(int ucount)
{
    for(int k=0;k<ucount;k++)
    {
        fflush(stdin);
        printf("\nEnter the name of User %d : ",k+1);
        gets(user[k].name);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<12;j++)
            {
                if(i==0)
                {
                    printf("Enter the food expense for the month %d : ",j+1);
                    scanf("%d",&user[k].expenses[i][j]);
                }
                else if(i==1)
                {
                    printf("Enter the leisure expense for the month %d : ",j+1);
                    scanf("%d",&user[k].expenses[i][j]);
                }
                else if(i==2)
                {
                    printf("Enter the travel expense for the month %d : ",j+1);
                    scanf("%d",&user[k].expenses[i][j]);
                }
            }
        }
    }
}
void delete(int* ucount)
{
    fflush(stdin);
    if(*ucount == 0) 
    {
        printf("No users to delete.\n");
        return;
    }
    char name[50];
    printf("Enter the name of the user to delete:");
    scanf("%s", name);
    int i;
    for(i=0; i<*ucount; i++) 
    {
        if(strcmp(user[i].name, name) == 0) 
        {
            break;
        }
    }
    if(i == *ucount) 
    {
        printf("User not found.\n");
        return;
    }
    for(int j=i; j<*ucount-1; j++) 
    {
        user[j] = user[j+1];
    }
    (*ucount)--;
}
void search(int k)
{
    fflush(stdin);
    int iloc = -1, jloc = -1, item;
    printf("Enter the item you would want to find :");
    scanf("%d", &item);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (user[k].expenses[i][j] == item)
            {
                iloc = i;
                jloc = j;
                break;
            }
        }
    }
    if (iloc != -1 && jloc != -1)
    {
        printf("The item is found at row %d, column %d\n", iloc, jloc);
    }
    else
    {
        printf("The item is not found\n");
    }
}
void display(int ucount)
{
    for(int k=0;k<ucount;k++)
    {
        printf("\n%s (USER %d) Expense List :\n",user[k].name,k);
        printf("\n\t\tMonth I\t\tMonth II\tMonth III\tMonth IV\tMonth V\tMonth VI\t\tMonth VII\tMonth VIII\tMonth IX\tMonth X\tMonth XI\tMonth XII");
        for(int i=0;i<3;i++)
        {
            if(i==0)
            {
                printf("\nFOOD\t");
            }
            else if(i==1)
            {
                printf("\nLEISURE\t");
            }
            else if(i==2)
            {
                printf("\nTRAVEL\t");
            }
            for(int j=0;j<12;j++)
            {
                printf("\t%d\t",user[k].expenses[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void monthlyAverage(int k)
{
    user[k].m1avg=(user[k].expenses[0][0]+user[k].expenses[1][0]+user[k].expenses[2][0])/3;
    user[k].m2avg=(user[k].expenses[0][1]+user[k].expenses[1][1]+user[k].expenses[2][1])/3;
    user[k].m3avg=(user[k].expenses[0][2]+user[k].expenses[1][2]+user[k].expenses[2][2])/3;
    user[k].m4avg=(user[k].expenses[0][3]+user[k].expenses[1][3]+user[k].expenses[2][3])/3;
    user[k].m5avg=(user[k].expenses[0][4]+user[k].expenses[1][4]+user[k].expenses[2][4])/3;
    user[k].m6avg=(user[k].expenses[0][5]+user[k].expenses[1][5]+user[k].expenses[2][5])/3;
    user[k].m7avg=(user[k].expenses[0][6]+user[k].expenses[1][6]+user[k].expenses[2][6])/3;
    user[k].m8avg=(user[k].expenses[0][7]+user[k].expenses[1][7]+user[k].expenses[2][7])/3;
    user[k].m9avg=(user[k].expenses[0][8]+user[k].expenses[1][8]+user[k].expenses[2][8])/3;
    user[k].m10avg=(user[k].expenses[0][9]+user[k].expenses[1][9]+user[k].expenses[2][9])/3;
    user[k].m11avg=(user[k].expenses[0][10]+user[k].expenses[1][10]+user[k].expenses[2][10])/3;
    user[k].m12avg=(user[k].expenses[0][11]+user[k].expenses[1][11]+user[k].expenses[2][11])/3;
    printf("\nMonth I Expense Average : %d",user[k].m1avg);
    printf("\nMonth II Expense Average : %d",user[k].m2avg);
    printf("\nMonth III Expense Average : %d",user[k].m3avg);
    printf("\nMonth IV Expense Average : %d",user[k].m4avg);
    printf("\nMonth V Expense Average : %d",user[k].m5avg);
    printf("\nMonth VI Expense Average : %d",user[k].m6avg);
    printf("\nMonth VII Expense Average : %d",user[k].m7avg);
    printf("\nMonth VIII Expense Average : %d",user[k].m8avg);
    printf("\nMonth IX Expense Average : %d",user[k].m9avg);
    printf("\nMonth X Expense Average : %d",user[k].m10avg);
    printf("\nMonth XI Expense Average : %d",user[k].m11avg);
    printf("\nMonth XII Expense Average : %d",user[k].m12avg);
}
void csum(int ucount)
{
    int csum = 0;
    printf("\nThe Cumulative Sum of Expenses of all Users :");
    printf("\n\t\tMonth I\t\tMonth II\tMonth III\tMonth IV\tMonth V\tMonth VI\t\tMonth VII\tMonth VIII\tMonth IX\tMonth X\tMonth XI\tMonth XII");
    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
            printf("\nFOOD\t");
        }
        else if(i==1)
        {
            printf("\nLEISURE\t");
        }
        else if(i==2)
        {
            printf("\nTRAVEL\t");
        }
        for(int j=0;j<12;j++)
        {
            for(int k=0;k<ucount;k++)
            {
                csum+=user[k].expenses[i][j];
            }
            printf("\t%d\t",csum);
            csum=0;
        }
        printf("\n");
    }
}
void cdifference(int ucount)
{
    int diff = 0;
    printf("\nThe Difference of Expenses of all Users :");
    printf("\n\t\tMonth I\t\tMonth II\tMonth III\tMonth IV\tMonth V\tMonth VI\t\tMonth VII\tMonth VIII\tMonth IX\tMonth X\tMonth XI\tMonth XII");
    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
            printf("\nFOOD\t");
        }
        else if(i==1)
        {
            printf("\nLEISURE\t");
        }
        else if(i==2)
        {
            printf("\nTRAVEL\t");
        }
        for(int j=0;j<12;j++)
        {
            for(int k=0;k<ucount;k++)
            {
                diff-=user[k].expenses[i][j];
            }
            printf("\t%d\t",diff);
            diff = 0;
        }
        printf("\n");
    }
}
void main()
{
    int ucount,id,choice;
    int menu=1;
    printf("######### PERSONAL FINANCE TRACKER #########\n");
    printf("\n");
    printf("Enter the Number of Users : ");
    scanf("%d",&ucount);
    while(menu!=0)
    {
        printf("1. Insert user\n");
        printf("2. Delete user\n");
        printf("3. Search user\n");
        printf("4. Cumulative Sum\n");
        printf("5. Cumulative Difference\n");
        printf("6. Monthly Average of User\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                fflush(stdin);
                insert(ucount);
                break;
            case 2:
                fflush(stdin);
                delete(&ucount);
                break;
            case 3:
                fflush(stdin);
                printf("\nEnter the User ID of the user that you wish to search :");
                scanf("%d",&id);
                search(id);
                break;
            case 4:
                fflush(stdin);
                csum(ucount);
                break;
            case 5:
                fflush(stdin);
                cdifference(ucount);
                break;
            case 6:
                fflush(stdin);
                printf("\nEnter the User ID of the user that you wish to find the montly average :");
                scanf("%d",&id);
                monthlyAverage(id);
                break;
            case 7:
                fflush(stdin);
                display(ucount);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        fflush(stdin);
        printf("\nEnter any number to continue. Enter 0 to Exit the Program : ");
        scanf("%d",&menu);
    }
}