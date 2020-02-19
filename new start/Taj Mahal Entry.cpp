#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    long long time;
    vector<long long> arr2;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] - i <= 0)
        {
            arr2.push_back(0);
        }
        else if((arr[i] - i) % n != 0)
        {
            time = arr[i] - i;
            time = time / n;
            time = time + 1;
            arr2.push_back(time);
        }
        else
        {
            time = arr[i] - i;
            time = time / n;
            arr2.push_back(time);
        }
    }
    long long temp = 0, min = 10000000;
    for(int i = 0; i < n; i++)
    {
       if(arr2[i] < min)
       {
           min = arr2[i];
           temp = i;
       }
    }
    
    cout << temp + 1 << endl;
    
    
	return 0;
}
