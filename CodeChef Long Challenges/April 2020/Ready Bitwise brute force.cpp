#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i < (b); i++)
#define derep(i,a,b) for(long long i = (a); i>=(b); i--)

ll zero, one, aa, AA;
char applyOp(char a, char b, char op){ 
    // cout << "a: " << a << " b: " << b << " op: " << op << endl;
    if(op == '&'){
        if((a == '0' && b == '1') || (a == '1' && b == '0') || (a == '0' && b == '0') || (a == '0' && b == 'a')  || 
        (a == 'a' && b == '0') || (a == '0' && b == 'A') || (a == 'A' && b == '0')  || (a == 'a' && b == 'A') || (a == 'A' && b == 'a')){
            return '0';
        }
        else if((a == '1' && b == '1')){
            return '1';
        }
        else if((a == '1' && b == 'a') || (a == 'a' && b == '1') || (a == 'a' && b == 'a')){
            return 'a';
        }
        else{
            return 'A';
        }
    }
    else if(op == '|'){
        if((a == '0' && b == '0')){
            return '0';
        }
        else if((a == '0' && b == 'a') || (a == 'a' && b == '0') || (a == 'a' && b == 'a')){
            return 'a';
        }
        else if((a == '0' && b == 'A') || (a == 'A' && b == '0') || (a == 'A' && b == 'A')){
            return 'A';
        }
        else{
            return '1';
        }
    }
    else{
        if((a == '0' && b == '0') || (a == '1' && b == '1') || (a == 'a' && b == 'a') || (a == 'A' && b == 'A')){
            return '0';
        }
        else if((a == '0' && b == '1') || (a == '1' && b == '0') || (a == 'a' && b == 'A') || (a == 'A' && b == 'a')){
            return '1';
        }
        else if((a == 'a' && b == '0') || (a == '0' && b == 'a') || (a == '0' && b == 'A') || (a == 'A' && b == '0')){
            return 'a';
        }
        else if((a == '1' && b == 'a') || (a == 'a' && b == '1') || (a == 'A' && b == '1') || (a == '1' && b == 'A')){
            return 'A';
        }
    }
} 

char findValue(string str){ 
    if(str.length() == 1){
        return str[0];
    }
    else{
        ll opening = 0;
        stack<char> st;
        for(ll i = 0; i < str.length(); i++){
            if(str[i] == ')'){
                char val1, val2, val3;
                val1 = st.top(); st.pop();
                val2 = st.top(); st.pop();
                val3 = st.top(); st.pop();
                st.pop();
                st.push(applyOp(val3, val1, val2));
            }
            else{
                st.push(str[i]);
            }
        }
        char front;
        while(!st.empty()){
            front = st.top();
            st.pop();
            // cout << "top: " << front << endl;
        }
        return front;
    }
}

void solve(char arr[], string s, ll index, ll n, string str, ll &count){

    if(index == n){
        count++;
        // cout<<str<<endl;
        char ans = findValue(str);
        if(ans == '0') zero++;
        else if(ans == '1') one++;
        else if(ans == 'a') aa++;
        else if(ans == 'A') AA++;
        return;
    }
    if(s[index] == '#'){
        for(ll i = 0; i<4; i++){
            solve(arr, s, index + 1, n, str + arr[i], count);
        }
    }
    else{
        solve(arr, s, index + 1, n, str + s[index], count);
    }

}

ll modInverse(ll a, ll modi) 
{ 
    ll y = 0, x = 1; 
	ll mod2 = modi; 
	if(modi == 1) return 0; 

	while(a > 1){ 
		ll quotient = a / modi; 
		ll temp = modi; 
		modi = a % modi;
        a = temp; 
		temp = y; 
		y = x - quotient * y; 
		x = temp; 
	} 
	if(x < 0){
        x += mod2;
    } 
	return x; 
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        zero = one = aa = AA = 0;
        string s;
        cin >> s;
        char arr[4] = {'a', 'A', '1', '0'};
        ll count = 0;
        solve(arr, s, 0, s.size(), "", count);
        // cout << "count: " << count << endl;
        // cout << "zero: " << zero << " one: " << one << " a: " << aa << " A: " << AA << endl;
        ll ans = modInverse(count, 998244353);
        cout << ((ans * zero) % 998244353) << " " << ((ans * one) % 998244353) << " " << ((ans * aa) % 998244353) << " " << ((ans * AA) % 998244353) << endl;
    }
}