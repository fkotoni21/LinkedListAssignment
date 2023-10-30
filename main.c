#include <stdio.h>
#include <stdlib.h>
//structure declaration and definition
typedef struct Node
{
    int ID;
    struct Node* Next;
} Node;
typedef Node* NodePTR;
//global variables
NodePTR Curr=NULL;
NodePTR Prev=NULL;
NodePTR New=NULL;
int NodePos;
int NodeCount;
//function prototypes
void InsertAtStart(NodePTR* First);
void InsertAtEnd(NodePTR* First);
void InsertSorted(NodePTR* First);
void InsertAtAnyPos(NodePTR* First);
void DeleteAtStart(NodePTR* First);
void DeleteAtEnd(NodePTR* First);
void DeleteNodeWithGivenID(NodePTR* First);
void DeleteAtAnyPos(NodePTR* First);
void DisplayList(NodePTR First);
int GetSizeOfList(NodePTR First);
//main function
int main()
{
    NodePTR First=NULL;
    int OperationVal;
    while(1)
    {
        system("cls");
        puts("List Of Operations:\n");
        puts("1. Insert First ID");
        puts("2. Insert Last ID");
        puts("3. Insert ID then Sort");
        puts("4. Insert ID at Any Position");
        puts("5. Delete First ID");
        puts("6. Delete Last ID");
        puts("7. Delete Specific ID");
        puts("8. Delete ID at a Specific Position");
        puts("9. Display Current IDs");
        puts("10. Total Amount of IDs");
        puts("11. Close Program\n");
        printf("Enter an integer corresponding to the list of operations: ");
        if(scanf("%d",&OperationVal)<=0)
        {
            puts("Wrong operation value.");
            exit(0);
        }
        else
        {
            switch(OperationVal)
            {
                case 1:
                InsertAtStart(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 2:
                InsertAtEnd(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 3:
                InsertSorted(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 4:
                InsertAtAnyPos(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 5:
                DeleteAtStart(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 6:
                DeleteAtEnd(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 7:
                DeleteNodeWithGivenID(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 8:
                DeleteAtAnyPos(&First);
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 9:
                printf("Current IDs: ");
                DisplayList(First);
                system("pause");
                break;

                case 10:
                printf("Total Amount of IDs: ",GetSizeOfList(First));
                system("pause");
                break;

                case 11:
                return 0;
            }
        }
    }
    return 0;
}
void InsertAtStart(NodePTR *First)
{
    New=(NodePTR)malloc(sizeof(Node));
    printf("Enter ID to be inserted: ");
    scanf("%d",&New->ID);
    New->Next=NULL;
    ///case 0: linked list is empty
    if (*First==NULL)
        *First=New;
    ///case 1: linked list is occupied
    else
    {
        New->Next=*First;
        *First=New;
    }
}
void InsertAtEnd(NodePTR *First)
{
    New=(NodePTR)malloc(sizeof(Node));
    printf("Enter ID to be inserted: ");
    scanf("%d",&New->ID);
    New->Next=NULL;
    ///case 0: linked list is empty
    if (*First==NULL)
        *First=New;
    ///case 1: linked list is occupied
    else
    {
        Curr=*First;
        while (Curr->Next!=NULL)
        {
            Curr=Curr->Next;
        }
        Curr->Next=New;
    }
}
void InsertSorted(NodePTR* First)
{
    New=(NodePTR)malloc(sizeof(Node));
    printf("Enter ID to be inserted: ");
    scanf("%d",&New->ID);
    New->Next=NULL;
    Curr=*First;
    ///case 0: linked list is empty
    if (*First==NULL)
    {
        *First=New;
        return;
    }
    ///case 1: new node is inserted at the beginning
    if (Curr->ID >= New->ID)
    {
        New->Next=Curr;
        *First=New;
    }
    else
    {
        while ((Curr!=NULL) && (Curr->ID < New->ID))
        {
            Prev=Curr;
            Curr=Curr->Next;
        }
        ///case 2: new node is inserted at the end
        if (Curr==NULL)
            Prev->Next=New;
        ///case 3: new node is somewhere in the middle
        else
        {
            Prev->Next=New;
            New->Next=Curr;
        }
    }
}
void InsertAtAnyPos(NodePTR* First)
{
    New=(NodePTR)malloc(sizeof(Node));
    printf("Enter position where ID will be inserted: ");
    scanf("%d",&NodePos);

    ///case 0: position is invalid (smaller than zero or greater than size)
    if (NodePos<1 || NodePos>GetSizeOfList(*First)+1)
        puts("Position is invalid!");
    ///case 1: position is set to 1
    else if (NodePos==1)
        *First=New;
    }
    ///case 2: position is valid
    else
    {
        Curr=*First;
        for (NodeCount=1; NodeCount<NodePos-1; NodeCount++)
            Curr=Curr->Next;

    New=(NodePTR)malloc(sizeof(Node));
    printf("Enter ID to be inserted: ");
    scanf("%d",&New->ID);
    New->Next=NULL;

    New->Next=Curr->Next;
    Curr->Next=New;
    }
}
void DeleteAtStart(NodePTR* First)
{
    Curr=*First;
    ///case 0: linked list is empty
    if (Curr==NULL)
        return;
    ///case 1: linked list is occupied (1st node is present)
    *First=Curr->Next;
    free(Curr);
}
void DeleteAtEnd(NodePTR* First)
{
    ///case 0: linked list only has one node
    if (*First!=NULL && (*First)->Next==NULL)
        *First=NULL;
    ///case 1: linked list is empty
    else if (*First==NULL)
        return;
    ///case 2: last node is present
    else
    {
        Prev=*First;
        while (Prev->Next->Next!=NULL)
        {
            Prev=Prev->Next;
        }
        Curr=Prev->Next;
        Prev->Next=NULL;
        free(Curr);
    }
}
void DeleteNodeWithGivenID(NodePTR* First)
{
    int IDToBeDel;
    printf("Enter ID to be deleted: ");
    scanf("%d",&IDToBeDel);

    Curr=*First;
    ///case 0: linked list is empty
    if (*First==NULL)
        return;
    ///case 1: first node will be deleted
    if (Curr->ID==IDToBeDel)
    {
        *First=Curr->Next;
        free(Curr);
    }
    else
    {
        while ((Curr!=NULL) && (Curr->ID!=IDToBeDel))
        {
            Prev=Curr;
            Curr=Curr->Next;
        }
        ///case 2: node not found
        if (Curr==NULL)
            printf("ID %d not found!",IDToBeDel);
        ///case 3: any other node found
        else if (Curr->ID==IDToBeDel)
        {
            Prev->Next=Curr->Next;
            free(Curr);
        }
    }
}
void DeleteAtAnyPos(NodePTR *First)
{
    printf("Enter position where ID will be deleted: ");
    scanf("%d",&NodePos);
    ///case 0: position is invalid (smaller than zero or greater than size)
    if (NodePos<1 || NodePos>GetSizeOfList(*First)+1)
        puts("Position is invalid!");
    ///case 1: position is set to 1 (first node will be deleted)
    else if (NodePos==1)
    {
        *First=(*First)->Next;
        Prev->Next=NULL;
        free(Prev);
    }
    ///case 2: position is valid
    else
    {
        for (NodeCount=1; NodeCount<NodePos-1; NodeCount++)
            Prev=Prev->Next;
        Curr=Prev->Next;
        Prev->Next=Prev->Next->Next;
        Curr->Next=NULL;
        free(Curr);
    }

}
void DisplayList(NodePTR First)
{
    Curr=First;
    ///case 0: linked list is occupied
    if (First!=NULL)
    {
        while (Curr!=NULL)
        {
            printf("%d ",Curr->ID);
            Curr=Curr->Next;
        }
        puts("");
    }
    ///case 1: linked list is empty
    else
        puts("List is empty!");
}
int GetSizeOfList(NodePTR First)
{
    int TotalOfNodes=0;
    Curr=First;
    if (First!=NULL)
    {
        while (Curr!=NULL)
        {
            Curr=Curr->Next;
            TotalOfNodes++;
        }
        return TotalOfNodes;
    }
    else
        return 0;
}
