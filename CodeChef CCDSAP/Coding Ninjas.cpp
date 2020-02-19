#include <bits/stdc++.h> 
using namespace std; 
  
// Returns count of minimum squares that sum to n 
int getMinSquares(unsigned int n) 
{ 
    // base cases 
    // if n is perfect square then Minimum squares required is 1 (144 = 12^2) 
    if(n < 0)
    {
        return 0;
    }
    if (n <= 3 && n >= 0) 
        return n; 
  
    // getMinSquares rest of the table using recursive 
    // formula 
    // int res = n; // Maximum squares required is n (1*1 + 1*1 + ..) 
  
    // // Go through all smaller numbers 
    // // to recursively find minimum 
    // for (int x = 1; x <= n; x++) { 
    //     int temp = x * x; 
    //     if (temp > n) 
    //         break; 
    //     else
    //         res = min(res, 1 + getMinSquares(n - temp)); 
    // } 
    // return res; 
    int ans = (int)(pow(n, 0.5));
    cout << "ans : " << ans << endl;
    cout << "n - (ans * ans): " << n - (ans * ans) << endl;
    return 1 + getMinSquares(n - (ans * ans));
} 

int getMinSquares2(unsigned int n) 
{ 
    // base cases 
    // if n is perfect square then Minimum squares required is 1 (144 = 12^2) 
    if (sqrt(n) - floor(sqrt(n)) == 0) 
        return 1; 
    if (n <= 3) 
        return n; 
  
    // getMinSquares rest of the table using recursive 
    // formula 
    int res = n; // Maximum squares required is n (1*1 + 1*1 + ..) 
  
    // Go through all smaller numbers 
    // to recursively find minimum 
    for (int x = 1; x <= n; x++) { 
        int temp = x * x; 
        if (temp > n) 
            break; 
        else
            res = min(res, 1 + getMinSquares(n - temp)); 
    } 
    return res; 
} 
  
// Driver program 
int main() 
{ 
    // for(int k = 12; k <= 12; k++)
    // {
    // if(getMinSquares(k) != getMinSquares2(k))
    // {
    //     // cout << k << endl;
    //     cout << getMinSquares(k) << endl;
    //     // cout << getMinSquares2(k) << endl;
    //     break;
    // }
    // }
    cout << getMinSquares(12) << endl;
    return 0; 
} 