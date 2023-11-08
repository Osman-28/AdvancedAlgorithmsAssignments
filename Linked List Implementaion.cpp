#include<iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;
};

void createNewNode(Node **p, int rowIndex, int colIndex, int x)
{
    Node *temp = *p;
    Node *r;
    
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = rowIndex;
        temp->col = colIndex;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
            
        r = new Node();
        r->row = rowIndex;
        r->col = colIndex;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

void printList(Node *start)
{
    Node *ptr = start;
    cout << "row_position:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";

    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;
    
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{ 
    int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
                               { 0 , 0 , 5 , 7 , 0 },
                               { 0 , 0 , 0 , 0 , 0 },
                               { 0 , 2 , 6 , 0 , 0 } };
    
    Node *first = NULL;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
                createNewNode(&first, i, j, sparseMatrix[i][j]);
        }
    }
    printList(first);

    return 0;
}
