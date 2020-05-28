#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

char applyOp(char a, char b, char op){
    
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
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
    }

    return 0;
}