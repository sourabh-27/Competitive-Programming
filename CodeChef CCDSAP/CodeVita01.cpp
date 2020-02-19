#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    char ** arr = new char*[n + 1];
    for(ll i = 0; i <= n; i++)
    {
        arr[i] = new char[n + 1];
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];

        }
    }

    ll clockWise = 0, anticlockWise = 0;
    ll finalCW = 0; ll finalACW = 0;
    ll times = n / 2;
    ll row = 0, col = 0;
    ll flag = 0;
    ll row2 = n - 1, col2 = n - 1;
    for(ll i = 0; i < times; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(arr[row][j] == 'X')
            {
                // cout << "I am anticlockWise1 " << endl;
                anticlockWise -= j - i;
                flag = 1;
                break;
                // row += 1; col += 1;
            }
            else if(arr[j][col] == 'X')
            {
                // cout << "I am clockWise1" << endl;
                clockWise += j - i;
                flag = 2;
                vector<ll> vec;
                for(ll x = 0; x < n; x++)
                {
                    vec.push_back(arr[x][i]);
                }
                ll distance = j;
                for(ll x = 0; x < distance + 1; x++)
                {
                    arr[x][i] = arr[x + distance][i];
                }
                for(ll x = distance + 1, y = 1; x < n; x++, y++)
                {
                    arr[x][i] = arr[n - 1 - i][y];
                }
                for(ll x = 1; x < distance + 1; x++)
                {
                    arr[n - i - 1][x] = arr[n - i - 1][x + distance]; 
                }
                for(ll x = distance + 1, y = n - 2; x < n; x++, y--)
                {
                    arr[n - i - 1][x] = arr[y][n - i - 1];
                }
                for(ll x = 1; x < distance + 1; x++)
                {
                    arr[n - x][n - i - 1] = arr[n - x - distance][n - i - 1];
                }
                for(ll x = distance + 1, y = distance; x < n; x++, y++)
                {
                    arr[n - x][n - i - 1] = arr[i][y];
                }
                break;
                // row += 1; col += 1;
            }
            else if(arr[row2][j] == 'X')
            {
                // cout << "I am clockWIse2 " << endl;
                clockWise += n - (i * 2) + j - (i + 1);
                flag = 3;


                
                break;
            }
            else if(arr[j][col2] == 'X')
            {
                // cout << "I am anticlockWise2 " << endl;
                anticlockWise -= n - (i * 2) + j - (i + 1);
                break;
            }
        };
        // cout << "clockWise : " << clockWise << " " << "anticlockWise: " << anticlockWise << endl;
        finalCW += clockWise; finalACW += anticlockWise;
        clockWise = 0; anticlockWise = 0;
        row += 1; col += 1;
        row2 -= 1; col2 -= 1;
    }
    cout << "clockWise : " << finalCW << " " << "anticlockWise: " << finalACW << endl;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}