#include<bits/stdc++.h>
#include <inttypes.h>
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;

ull power10(ull x, ull y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power10(x, y / 2) * power10(x, y / 2); 
    else
        return x * power10(x, y / 2) * power10(x, y / 2); 
} 
 
int main()
{
    ull t;
    scanf("%llu", &t);
    while(t--)
    {
        ull n, a;
        scanf("%llu", &n);
        scanf("%llu", &a);
        ull end = power10(10, n);
        ull s = end * 2 + a;
        printf("%llu\n", s);
        fflush(stdout);
        s = s - a;
        ull b;
        scanf("%llu", &b);
        s = s - b;
        ull c;
        c = s - end;
        printf("%llu\n", c);
        fflush(stdout);
        s = s - c;
        ull d;
        scanf("%llu", &d);
        s = s - d;
        printf("%llu\n", s);
        fflush(stdout);


        ull last;
        scanf("%llu", &last);
        if(last == -1)
        {
            return 0;
        }
    }

    return 0;
}