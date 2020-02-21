#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

// class Node{
//     public:
//     int data;
//     Node* next;
// };

// void sortedInsert(Node ** head, Node * new_node)
// {
//     Node* current;
//     if(*head == NULL || (*head)->data >= (new_node)->data){
//         new_node->next = *head;
//         *head = new_node;
//     }
//     else{
//         current = *head;
//         while(current->next != NULL && current->next->data < new_node->data)
//         {
//             current = current->next;
//         }
//         new_node->next = current->next;
//         current->next = new_node;
//     }
// }

// Node *newnode(int nodeData){
//     Node * new_node = new Node();
//     new_node->data = nodeData;
//     new_node->next = NULL;

//     return new_node;
// }

// void printList(Node * head)
// {
//     Node *temp = head;
//     while(temp->next != NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

class Node{
    public:
    int data;
    Node* next;
};

Node *newnode(int nodeData){
    Node* temp = new Node();
    temp->data = nodeData;
    temp->next = NULL;

    return temp;
}

void sortedInsert(Node ** head, Node* new_node)
{
    Node* current;
    if((*head) == NULL || (*head)->data >= (new_node)->data){
        new_node->next = *head;
        *head = new_node;
    }
    else{
        current = *head;
        while(current->next != NULL && current->next->data < new_node->data){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(Node * head){
    Node *temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}
 
int main()
{
    fast;
    Node * head = NULL;
    Node *new_node = newnode(5);
    sortedInsert(&head, new_node);
    new_node = newnode(10);
    sortedInsert(&head, new_node);  
    new_node = newnode(7);  
    sortedInsert(&head, new_node);  
    new_node = newnode(3);  
    sortedInsert(&head, new_node);  
    new_node = newnode(1);  
    sortedInsert(&head, new_node);  
    new_node = newnode(9);  
    sortedInsert(&head, new_node);  
    cout<<"Created Linked List\n";  
    printList(head); 


    return 0;
}