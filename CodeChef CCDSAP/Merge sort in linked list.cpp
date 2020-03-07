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

void printList(Node * head){
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

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

Node *merge(Node * head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else if(head1->data <= head2->data){
        Node * temp = head1->next;
        head1->next = NULL;
        Node * head = merge(temp, head2);
        head1->next = head; 
        return head1;
    }
    else{
        Node * temp = head2->next;
        head2->next = NULL;
        Node * head = merge(head1, temp);
        head2->next = head; 
        return head2;
    }
}

 
int main()
{
    fast;
    fast;
    Node * head = NULL;
    Node *new_node = newnode(5);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        append(&head, k);
    }

    Node * head2 = NULL;
    Node *new_node2 = newnode(5);
    ll m;
    cin >> m;
    for(ll i = 0; i < m; i++){
        ll k; cin >> k;
        append(&head2, k);
    }

    printList(head); cout << endl;
    Node *newhead = merge(head, head2);
    printList(newhead);

    return 0;
}