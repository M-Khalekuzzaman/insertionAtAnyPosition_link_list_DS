#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;

    //Constructor declare
    Node(int data)
    {
        this -> data = data;
        this -> Next = NULL;
    }
};
//function declare part
void printLinkList();
void insertionAtHead();
void insertionAtTail();
void insertionAtPosition();

void insertionAtHead(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *save_previous_node = head;
    newNode->Next = save_previous_node;
    head = newNode;
}
void insertionAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL){

        temp = temp->Next;
    }
    temp->Next = newNode;
}
void insertionAtPosition(Node* &head,int value,int pos)
{
    Node *newNode = new Node(value);
    if(pos == 1){
        Node *save_node = head;
        newNode->Next = save_node;
        head = newNode;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1;i<pos;i++){
       temp = temp->Next;
    }
    Node *save = temp->Next;
    temp->Next = newNode;
    newNode->Next = save;
}


void printLinkList(Node* &head)
{
    Node *currentNode = head;
    while(currentNode != NULL)
    {
        cout<<currentNode->data;
        if(currentNode->Next != NULL) cout<<" -> ";
        currentNode = currentNode->Next;
    }
    cout<<endl;
}
int main()
{
    Node *head = NULL;
    cout<<"Choice 1 : Insertion at Head"<<endl;
    cout<<"Choice 2 : Insertion at Tail"<<endl;
    cout<<"Choice 3 : Insertion at any Position"<<endl;
    cout<<"Choice 0 : Exit"<<endl<<endl;
    int value,pos,choice = 2;
    while(choice != 0)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter your value : ";
                cin>>value;
                insertionAtHead(head,value);
                break;
            case 2:
                cout<<"Enter your value : ";
                cin>>value;
                insertionAtTail(head,value);
                break;
            case 3:
                cout<<"Enter your value & pos : ";
                cin>>value>>pos;
                insertionAtPosition(head,value,pos);
                break;
            default:
                break;
        }
        cout<<"Next Choice : ";
        cin>>choice;
    }


    printLinkList(head);

    return 0;
}

