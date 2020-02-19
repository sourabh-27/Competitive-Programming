#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int answer = 0;
    while(a <= b)
    {
        a = a * 3;
        b = b * 2;
        answer++;
    }

    cout << answer << endl;

    return 0;
}