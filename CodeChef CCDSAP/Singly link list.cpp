#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node
{
    int data;
    node * next;
}*start = NULL;

void creation();
void insertion(node *);
int deletion(node *);
void display

void creation()
{
    node start = new node;
    cout << "Please enter the data-value for first node" << endl;
    cin >> start->data;
    start->next = NULL;
}

void insertion(node *p)
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    node *temp = new node;
    cout << "Enter the data of new value" << endl;
    cin >> temp->data;
    temp->next = NULL;
}

int deletion(node *ptr)
{
    node *ptrP = NULL;
    if(ptr == NULL)
    {
        cout << "List is empty" << endl;
        return 0;
    }
    int val;
    cout << "Enter the data-value to delete" << endl;
    cin >> val;
    while(ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    return 0;
}