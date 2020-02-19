#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int arr[x+1];
    for(int i = 0; i<x+1; i++){
        arr[i] = a[i];
    }
    for(int i = 0; i<x+1; i++){
        a[i] = a[x+i];
    }
    for(int i = x, j = 0; i<n; i++, j++){
        a[x] = arr[j];
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
}