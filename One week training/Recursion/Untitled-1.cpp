#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

class Node{
    public:
        int data;
        Node *next;

        Node(int d){
            data = d;
            next = NULL;
        }
};

// void swap(Node *&ptr1, Node *&ptr2, Node *&head){
//     if(ptr1 == head){
//         Node *temp = ptr2->next;
//         Node *temp2 = ptr1;
//         head = ptr2;
//         ptr2 = temp2;
//         ptr2->next = temp;
//     }
//     else{
//         Node *temp = ptr2->next;
//         cout << "temp: " << temp->data << endl;
//         ptr2->next = ptr1;
//         // ptr1 = ptr2;
//         ptr1->next = temp;
//         cout << "ptr1: " << ptr1->data << " ptr2: " << ptr2->data << endl;
//     }
// }

void bubbleSort(Node* &head, int n){
    Node *i = head;
    Node *j = head;
    while(i != NULL){
        while(j->next != NULL){
            // if(i->data > j->next->data){
            //     cout << "i->data: " << i->data << " j->data: " << j->next->data << endl;
            //     // swap(i, j->next, head);
            //     cout << "i->data2: " << i->data << " j->data2: " << j->next->data << endl;
            // }
            // cout << "i->data: " << i->data << " j->data: " << j->next->data << endl;
            if(i->data > j->next->data){
                cout << "i: " << i->data << " j: " << j->next->data << endl;
                Node * temp = j->next->next;
                cout << "temp: " << temp->data << endl;
                j->next->next = i;
                cout << "j->next->next: " << j->next->next->data << endl;
                i->next = temp;
                cout << "i->next: " << i->next->data << " j2: " << j->next->next->data << endl;
                head = j->next;
            }
            j = j->next;
        }
        i = i->next;
        j = i;
    }
}

void insertAtRear(Node *&head, Node* &tail, int data){
    if(head == NULL){
        head = tail = new Node(data);
    }
    else{
        Node *n = new Node(data);
        n->next = NULL;
        tail->next = n;
        tail = tail->next;
    }
}

void deleteNode(Node *&head, Node*&tail, int index){
    int count = 0;
    Node *temp = head;
    if(head == NULL){
        return;
    }
    while(count != index - 1){
        temp = temp->next;
    }
    Node *temp = head->next->next;
}

void printLinkList(Node* head){
    // Node *temp = head;
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
 
int main()
{
    fast;
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        insertAtRear(head, tail, k);
    }

    bubbleSort(head, n);
    printLinkList(head);

    // while(head != NULL){

    // }
    return 0;
}