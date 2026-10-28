#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
struct pointer
{
    Node* head=nullptr;
    Node* tail=nullptr;
    int count=0;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}


void insertAtEnd(pointer* point, int data) {
    Node* newNode = CreateNode(data);
    if(point->head == nullptr) {
        point->head = newNode;
        point->tail = newNode;
    } else {
        point->tail->next = newNode;
        newNode->prev = point->tail;
        point->tail = point->tail->next;
    }
    point->count++;
}

//2) delete from end

void deleteFromEnd(pointer* point) {
    if(point->head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = point->tail;
    if(point->head == point->tail) {
        point->head = nullptr;
        point->tail = nullptr;
        delete temp;
    } else {
        Node* oldtail = point->tail;
        point->tail = point->tail->prev;
        point->tail->next = nullptr;
        delete oldtail;
    }
    point->count--;
}

void display(pointer point) {
    Node* temp = point.head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    pointer point;
    for(int i = 0; i < n; i++) {
        int data;
        cout<<"Enter data for node "<<i+1<<": ";
        cin>>data;
        insertAtEnd(&point, data);
    }
    display(point);
    deleteFromEnd(&point);
    display(point);
}