#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    char s;
    cin >> s;
    if(s >= 'a' && s <= 'z')
    {
        cout << "L" << endl;
    }
    else if(s >= 'A' && s <= 'Z')
    {
        cout << "U" << endl;
    }
    else
    {
        cout << "I" << endl;
    }
    

    return 0;
}