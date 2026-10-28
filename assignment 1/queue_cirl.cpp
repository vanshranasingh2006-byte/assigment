#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int size;
    int *arr;
    int front = -1;
    int rear = -1;
    int count = 0;
} Queue;

void push(Queue &q, int val)
{
    if(q.count == q.size)
    {
        cout << "Queue overflow\n";
        return;
    }
    if(q.front == -1)
    {
        q.front = 0;
    }
    q.rear++;
    q.rear = (q.rear) % q.size;
    q.arr[q.rear] = val;
    q.count++;
}

void pop(Queue &q)
{
    if(q.count == 0) // rear<=front or front =-1
    {
        cout << "Queue underflow\n";
        return;
    }
    cout << q.arr[q.front] << " ";
    q.front = (q.front + 1) % q.size;

    q.count--;
}

void display(Queue q)
{
    if(q.count == 0)
    {
        cout << "Queue is empty\n";
        return;
    }

    int i = q.front;

    for(int j=0; j<q.count; j++)
    {
        cout << q.arr[i] << " ";
        i = (i + 1) % q.size;
    }
    cout << endl;
}

int main()
{
    Queue q;
    q.size = 5;
    q.arr = new int[q.size];
    push(q, 10);
    push(q, 20);    
    push(q, 30);
    push(q, 40);
    push(q, 50);
    push(q, 60); // Queue overflow
    display(q);
    pop(q);
    pop(q);
    cout<<"\n";
    display(q);
    return 0;
}