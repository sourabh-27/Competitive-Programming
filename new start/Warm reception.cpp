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
    vector<int> arr, dep, answer;
    int k;

    for(int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }

    for(int i = 0; i < n; i++)
    {
        cin >> k;
        dep.push_back(k);
    }
    k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((dep[i] >= arr[j]) && (dep[i] <= dep[j]))
            {
                k++;
            }
        }
        answer.push_back(k);
        k = 0;
    }
    cout << *max_element(answer.begin(), answer.end()) << endl;

    return 0;
}