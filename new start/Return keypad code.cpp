#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int keypad(int num, string output[], string arr[])
{
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }
    int temp;
    temp = num % 10;
    num = num / 10;

    string smallOutput[500];
    int smallCount = keypad(num, output, arr);
    string k = arr[temp];

    int temp2;
    for(int i = 0; i < k.length(); i++)
    {
        for(int j = 0; j < smallCount; j++)
        {
            output[temp2] = smallOutput[j] + k[i];
            temp2++;
        }
    }
    return temp2;
}

int keypad(int num, string output[])
{
    string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return (num, output, arr);

}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}