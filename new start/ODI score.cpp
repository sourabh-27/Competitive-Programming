#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    double r1;
    cin >> r1;
    int striker, nonStriker;
    cin >> striker >> nonStriker;
    cin.ignore();
    string str;
    getline(cin, str);
    int len = str.length();
    vector <int> arr;
    arr.push_back(0);
    int total = 0;
    for(int i = 0; i < len; i = i + 2)
    {
        if(str[i] != 'W')
        {
            int value = (int)str[i] - 48;
            total += value;
            arr.push_back(value);
        }
        else
        {
            arr.push_back(-1);
        }
        
    }
    len = (len + 1) / 2;
    double r2;
    cin >> r2;

    int b = len * ((6 / r2) - 1) * (r2 / (r2 - r1));
    int r = (r1 / 6) * b;

    int totalRun = r + total;
    int left = b % 6;
    cout << totalRun << " ";
    int flag = 0;
    for(int i = 1; i < len + 1; i++)
    {
        if(flag == 0)
        {
            striker = striker + arr[i];
            if(arr[i] == 1 || arr[i] == 3)
            {
                flag = 1;
            }
            if(arr[i] == -1)
            {
                striker = 0;
            }
        }
        else
        {
            nonStriker = nonStriker + arr[i];
            if(arr[i] == 1 || arr[i] == 3)
            {
                flag = 0;
            }
            if(arr[i] == -1)
            {
                nonStriker = 0;
            }
        }
        if((i + left) % 6 == 0)
        {
            if(flag == 0) flag = 1;
            else
            {
                flag = 0;
            }
        }
    }
    if(flag == 0)
    {
        cout << striker << " " << nonStriker;
    }
    else
    {
        cout << nonStriker << " " << striker;
    }
    
    return 0;
}