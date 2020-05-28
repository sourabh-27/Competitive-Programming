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
    Node * down;
};

Node *newnode(int nodedata){
    Node *temp = new Node;
    temp->data = nodedata;
    temp->next = NULL;
    temp->down = NULL;
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
    new_node->down = NULL; 
  
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