#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

// void findAns(string s, string ans, ll len, ll index, ll already){
//     if(index == len){
//         cout << ans << endl;
//         return;
//     }
//     string previous = ans;
//     for(ll i = 0; i < len; i++){
//         if(i == already){
//             continue;
//         }
//         findAns(s, ans + s[i], len, index + 1, i);
//         ans = previous;
//     }
// }

// void swap(char a, char b, string s){

// }

void backTrack(string &s, ll index){
    if(index == s.length() - 1){
        cout << s << endl;
        return;
    }

    for(ll j = index; j < s.length(); j++){
        swap(s[index], s[j]); //right rotate
        backTrack(s, index + 1);
        swap(s[index], s[j]); //left rotate
    }
}
 
int main()
{
    fast;
    string s;
    cin >> s;
    ll len = s.length();
    // findAns(s, "", len, 0, -1);
    backTrack(s, 0);

    return 0;
}