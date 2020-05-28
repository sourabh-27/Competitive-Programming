#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

class Node{
    public:
    int data;
    Node * next;
};

Node *newnode(int nodedata){
    Node *temp = new Node;
    temp->data = nodedata;
    temp->next = NULL;
}

void append(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    Node *last = *head_ref;
    new_node->data = new_data;  
    new_node->next = NULL;  
  
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
    while (last->next != NULL)  
        last = last->next;  
    last->next = new_node;  
    return;  
}

// void iterativeReverse(Node * head){
//     Node * previous = NULL;
//     Node * current = head;
//     Node * temp = new Node;
//     while(current->next != NULL){
//         previous = current->next;
//         current->next = previous;
//         previous = current;
//         current = temp;
//     }
//     head = previous;
// }

Node * reverse(Node * head){
    if(head->next == NULL){ //base condition
        return head;
    }

    Node *temp = head->next;
    head->next = NULL;  //dealing with code
    Node *h1 = reverse(temp); //recursive call
    temp->next = head; //link
    return h1; //return
}

void printList(Node * head){
    Node *temp = head;
    while(temp != NULL)
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
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        append(&head, k);
    }
    printList(head); cout << endl;
    Node *newhead = reverse(head);
    printList(newhead);

    return 0;
}