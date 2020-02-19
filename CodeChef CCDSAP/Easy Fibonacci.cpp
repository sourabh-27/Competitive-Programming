#include<bits/stdc++.h>
using namespace std; 

typedef unsigned long long int ll;

int arr[61]={0};
ll nextTwo(ll a){  
    ll start=0;    
    if(a&&!(a&(a-1))) return a; 
    while(a!=0){  
        a>>=1;  
        start++;;  
    }    
    return 1ull<<(start-1);  
}

void arrayGet(){
    arr[1]=0;
    arr[2]=1;
    for(int i=3; i<60; i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%10;
    }
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    arrayGet();
    while(T--){
        ll n;
        cin >> n;
        ll temp = nextTwo(n) % 60;
        cout << arr[temp] << endl;
    }
    return 0;
}