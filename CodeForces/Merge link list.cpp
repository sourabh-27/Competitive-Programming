#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

class node{
    public:
        int data;
        node *next;
        node(int d){
            data = d;
            next = NULL;
        }
};

void merge(int *arr, int m, int *arr2, int n, node *&head, node *&head2){
    int i = 0, j = 0;
    while(i < m && j < n){
        // cout << "i: " << i << " j: " << j << endl;
        if(arr[i] < arr2[j]){
            // cout << "YO" << endl;
            node *temp = new node(arr[i]);
            if(head == NULL){
                head = temp;
                head2 = temp;
                continue;
            }
            head->next = temp;
            head = head->next;
            i++; 
        }
        else{
            node * temp = new node(arr[j]);
            head->next = temp;
            head = head->next;
            j++;
        }
        // cout << "i2: " << i << " j2: " << j << endl;
        cout << head->data << " ";
    }
    while(i < m){
        node * temp = new node(arr[i]);
        head->next = temp;
        head = head->next;
        cout << head->data << " ";
        i++;
    }
    while(j < n){
        node * temp = new node(arr2[j]);
        head->next = temp;
        head = head->next;
        cout << head->data << " ";
        j++;
    }
    // cout << "head: " << head->data << endl;
}
 
int main()
{
    fast;
    ll m, n;
    cin >> m >> n;
    int arr[m + 1], arr2[n + 1];
    for(ll i = 0; i < m; i++){
        cin >> arr[i];
    }
    for(ll j = 0; j < n; j++){
        cin >> arr2[j];
    }

    node * head = NULL;
    node * head2 = NULL;
    merge(arr, m, arr2, n, head, head2);
    cout << "head2: " << head->data << endl;
    while(head2 != NULL){
        cout << head2->data << " ";
        head2 = head2->next;
    }


    return 0;
}