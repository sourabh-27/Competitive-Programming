#include <bits/stdc++.h>
using namespace std;
#define  mod 1000000007

int numCodes(int* input, int size)
{
    int* output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    
    for(int i = 2; i <= size; i++)
    {
        output[i] = output[i - 1];
        if(input[i - 1] * 10 + input[i] <= 26)
        {
            output[i] += output[i - 2];
        }
    }
    int ans = output[size];
    delete [] output;
    return ans;
}

int main()
{
    string k;
    cin >> k;
    while(k[0] != 0)
    {
        int arr[k.length()];
        for(int i = 0; i < k.length(); i++)
        {
            arr[i] = k[i];
        }

        cout << numCodes(arr, k.length()) << endl;
        cin >> k;
    }
    return 0;
    
}
