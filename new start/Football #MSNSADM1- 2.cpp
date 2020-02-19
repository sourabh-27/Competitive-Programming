#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int goals[n], fouls[n];
        for(int i = 0; i < n; i++)
        {
            cin >> goals[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> fouls[i];
        }
        int points[n]; int k;
        for(int i = 0; i < n; i++)
        {
            k = goals[i] * 20 - fouls[i] * 10;
            if(k < 0)
            {
                k = 0;
            }
            points[i] = k;
        }
        int max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(points[i] > max)
            {
                max = points[i];
            }
        }
        cout << max << endl;
    }

    return 0;
}