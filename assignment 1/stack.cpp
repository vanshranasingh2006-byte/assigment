#include <iostream>
using namespace std;
//Stack
typedef struct
{
    int size;
    int *arr;// store the pointer of the array we can use new int[n]
    int top = -1;
} Stack;

bool isempty(Stack);


void push(Stack &s , int val)
{
    if(s.top >= s.size-1) // did > size will look into it
    {
        cout << "stack overflow\n";
        return;
    }

    s.top++;
    s.arr[s.top]=val;
}

void pop(Stack &s)
{
    if(isempty(s))
    {
        cout << "\nStack underflow\n";
        return;
    }
    cout << s.arr[s.top]<<" ";
    s.top--;
}

bool isempty(Stack s)
{
    if(s.top == -1 || s.top < 0)
    {
        return true;
    }
    return false;
}

int main ()
{
    Stack s;
    cout << "Enter the size :";
    cin >> s.size;
    s.arr = new int[s.size];// can perfrom indexing in it or just use *(arr + i) as same as this arr[i]

    cout<<"Enter the inputs ";
    int inputs;
    int val;
    cin >> inputs;

    for(int i=0; i<inputs;i++)
    {
        cout << "Enter "<< i<<" :";
        cin >> val;
        push(s,val);
    }

    for(int i=0; i< inputs;i++)
    {
        pop(s);
    }
}
