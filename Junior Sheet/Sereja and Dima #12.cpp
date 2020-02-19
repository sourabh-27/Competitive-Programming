#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int flag = 0; int i = 0;
    int s = 0; int d = 0;
    while(n - i != 0)
    {
        if(flag == 0)
        {
            flag = 1;
            if(arr[n - 1] > arr[i])
            {
                s += arr[n - 1];
                n--;
            }
            else
            {
                s += arr[i];
                i++;
             }
            //  cout << s << " " << n << endl;    
        }
        else
        {
            flag = 0;
            if(arr[n - 1] > arr[i])
            {
                d += arr[n - 1];
                n--;
            }
            else
            {
                d += arr[i];
                i++;
            }  
            // cout << d << " " << n << endl;   
        }
    }

    cout << s << " " << d << endl;

    return 0;
}