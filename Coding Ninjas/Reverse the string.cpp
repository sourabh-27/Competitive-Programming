#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    string str;
    getline(cin, str);
    cout << "str: " << str << endl;
    string temp = "";
    cout << "str.length(): " << str.length() << endl;
    for(ll i = str.length() - 1; i >= 0; i--){
        cout << "str[i]: " << str[i] << endl;
        if(i == 32){
            cout << temp << " ";
            temp = "";
        }
        else{
            temp = temp + str[i];
            cout << "temp: " << temp << endl;
        }
    }
    reverse(temp.begin(), temp.end());
    cout << temp;

    return 0;
}