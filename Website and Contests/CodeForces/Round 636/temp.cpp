#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

int returnFirstSetBit(int n){

    ll ans1;
    for(int i=0;i<32;i++){
        cout << "i: " << i << "(1<<i): " << (1<<i) << endl;
        if(((1<<i) & n)==(1<<i)){
            return (i + 1);
        }
    }
    
}

int main() {
	int n;

	cin >> n;
	
    
	cout << returnFirstSetBit(n) << endl;
		
	return 0;
}
