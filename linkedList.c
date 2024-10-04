#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

void addNode(int elt)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elt;
    temp->next = NULL;
    if (HEAD == NULL)
    {
        HEAD = temp;
        return;
    }
    struct node *ptr = HEAD;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insertion(int elt, int index)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elt;
    if (index == 0)
    {
        temp->next = HEAD;
        HEAD = temp;
        return;
    }
    struct node *ptr = HEAD;
    while (--index && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (index != 0)
    {
        printf("Out of bounds insertion\n");
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void deletion(int index)
{
    if (HEAD == NULL)
    {
        printf("LL Underflow\n");
        return;
    }
    if (index == 0)
    {
        struct node *temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
    }
    struct node *ptr = HEAD;
    struct node *prevPtr = NULL;
    index++;
    while (--index && ptr->next != NULL)
    {
        prevPtr = ptr;
        ptr = ptr->next;
    }
    if (index)
    {
        printf("Out of bounds deletion\n");
        return;
    }
    else if (prevPtr == NULL)
    {
        HEAD = NULL;
        free(ptr);
        return;
    }
    prevPtr->next = ptr->next;
    free(ptr);
}

void show()
{
    struct node *ptr = HEAD;
    if (HEAD == NULL)
    {
        printf("List doesn't exist\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    while (1)
    {

        printf("\n1) Append Node\n2) Insert Node\n3) Delete Node\n4) Show List\n5) Exit\nSelect using numbers: ");
        int resp = 0;
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
        {
            int a = 0;
            scanf("%d", &a);
            addNode(a);
        }
        break;
        case 2:
        {
            int a = 0, index = 0;
            scanf("%d %d", &a, &index);
            insertion(a, index);
        }
        break;
        case 3:
        {
            int a = 0;
            scanf("%d", &a);
            deletion(a);
        }
        break;
        case 4:
            show();
            break;
        case 5:
            free(HEAD);
            return 0;
        default:
            printf("\nInvalid Option");
            break;
        }
    }
}