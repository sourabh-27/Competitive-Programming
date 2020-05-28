#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll t;
	cin >> t;
    test:
	while(t--){
		string str;
		cin >> str;
		stack<char> st;
		ll count = 0, flag = 0;
		for(ll i = 0; i < str.length(); i++){
			if(str[i] == ')'){
                char top = st.top();
                count = 0;
                st.pop();
                while(top != '('){
                    count++;
                    top = st.top();
                    st.pop();
                }
                if(count < 1){
                    cout << "Duplicate Found" << endl;
                    goto test;
                }
            }
            else{
                st.push(str[i]);
            }
		}
        cout << "No Duplicates Found" << endl;
	}
	return 0;
}