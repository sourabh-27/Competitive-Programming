#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n; int i = 0; int temp = n;
    int k; int arr[n];
    while(temp--)
    {
        cin >> k;
        int first = k % 10;
        k = k / 10;
        int second = k % 10;
        k = k / 10;
        int third = k;
        int maxi = max(first, max(second, third));
        int mini = min(first, min(second, third));
        int bit_score = maxi * 11  + mini * 7;
        bit_score %= 100;
        arr[i] = bit_score;
        i++;
    }

    int count = 0; int arr2[11] = {0};
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int check = arr[i] / 10;
            int check2 = arr[j] / 10;
            if(check == check2 && i % 2 == j % 2 && arr2[check] < 2)
            {
                arr2[check]++;
                count++;
            }
        }
    }

    cout << count;

    return 0;
}