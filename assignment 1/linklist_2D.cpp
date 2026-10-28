#include <bits/stdc++.h>
using namespace std;

struct linknode_2d
{
    int data;
    linknode_2d* right;
    linknode_2d* down;
    linknode_2d(int val)
    {
        data = val;
        right = NULL;
        down = NULL;
    }
};

struct mat2list
{
    linknode_2d* head;
    linknode_2d* currentrow;
    linknode_2d* startrow;
    linknode_2d* prevrow;
    int row;
    int col;
    int count;
    mat2list(int r, int c)
    {
        head = NULL; // it will never change after giving it a node
        currentrow = NULL;
        startrow = NULL;
        prevrow = NULL;
        row = r;
        col = c;
        count = 0;
    }
};
void insertval(mat2list*& matrix, int val)
{
    if(matrix->head == NULL)
    {
        matrix->head = new linknode_2d(val);
        matrix->startrow = matrix->head;
        matrix->currentrow= matrix->startrow;
        matrix->count++;
        return;
    }
    if(matrix->count==matrix->col)
    {
        matrix->count= 0 ;
        matrix->prevrow = matrix->startrow;
        if(matrix->startrow->down==NULL)
        {
            matrix->startrow->down = new linknode_2d(val);
            matrix->startrow = matrix->startrow->down;
        }
        matrix->currentrow = matrix->startrow;
        matrix->count++;
        return;
    }

    if(matrix->prevrow == NULL)
    {
        linknode_2d *curr=matrix->currentrow;
        linknode_2d *newnode = new linknode_2d(val);
        curr->right = newnode;
        matrix->currentrow=matrix->currentrow->right;
        matrix->count++;
    }
    else
    {
        // linknode_2d *curr=matrix->currentrow;
        // linknode_2d *newnode = new linknode_2d(val);
        // curr->right = newnode;
        // matrix->currentrow=matrix->currentrow->right;
        // matrix->prevrow=matrix->prevrow->right;
        // matrix->currentrow->down = matrix->prevrow;
        // matrix->count++;
        
        linknode_2d *curr = matrix->currentrow;
        linknode_2d *newnode = new linknode_2d(val);

        curr->right = newnode;
        matrix->currentrow = matrix->currentrow->right;

        // Connect ABOVE node → current node
        matrix->prevrow = matrix->prevrow->right;
        matrix->prevrow->down = matrix->currentrow;

        matrix->count++;
    }
}

void display(mat2list* matrix)
{
    linknode_2d* rowptr = matrix->head;

    while(rowptr != NULL)
    {
        linknode_2d* colptr = rowptr;

        while(colptr != NULL)
        {
            cout << colptr->data << " ";
            colptr = colptr->right;
        }

        cout << endl;
        rowptr = rowptr->down;
    }
}

void checkDown(mat2list* matrix)
{
    linknode_2d* rowptr = matrix->head;

    while(rowptr != NULL)
    {
        linknode_2d* curr = rowptr;

        while(curr != NULL)
        {
            cout << "Node: " << curr->data;

            if(curr->down != NULL)
            {
                cout << " down: " << curr->down->data;
            }
            else
            {
                cout << " down: NULL";
            }

            cout << endl;

            curr = curr->right;
        }

        rowptr = rowptr->down;
    }
}

int main()
{
    int row , col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    mat2list* matrix = new mat2list(row, col);
    for(int i=0;i<row;i++)
    {
        cout<<"Enter the values for row "<<i+1<<"\n";
        for(int j=0;j<col;j++)
        {
            cout<<"Enter the value for column "<<j+1<<": ";
            int val;
            cin>>val;
            insertval(matrix,val);
        }
    }
    display(matrix);
    checkDown(matrix);
}

