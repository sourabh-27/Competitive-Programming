#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Box 
{ 
  int h, w, d;
}; 
  
int min (int x, int y) 
{ return (x < y)? x : y; } 
  
int max (int x, int y) 
{ return (x > y)? x : y; } 
int compare (const void *a, const void * b) 
{ 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
} 
int maxStackHeight( Box arr[], int n ) 
{ 
   Box rot[3*n]; 
   int index = 0; 
   for (int i = 0; i < n; i++) 
   { 
      rot[index].h = arr[i].h; 
      rot[index].d = max(arr[i].d, arr[i].w); 
      rot[index].w = min(arr[i].d, arr[i].w); 
      index++; 
  
      rot[index].h = arr[i].w; 
      rot[index].d = max(arr[i].h, arr[i].d); 
      rot[index].w = min(arr[i].h, arr[i].d); 
      index++; 
  
      rot[index].h = arr[i].d; 
      rot[index].d = max(arr[i].h, arr[i].w); 
      rot[index].w = min(arr[i].h, arr[i].w); 
      index++; 
   } 

   n = 3*n; 
   qsort (rot, n, sizeof(rot[0]), compare); 
   int msh[n]; 
   for (int i = 0; i < n; i++ ) 
      msh[i] = rot[i].h; 
  
   for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( rot[i].w < rot[j].w && 
              rot[i].d < rot[j].d && 
              msh[i] < msh[j] + rot[i].h 
            ) 
         { 
              msh[i] = msh[j] + rot[i].h; 
         } 
  
  
   int max = -1; 
   for ( int i = 0; i < n; i++ ) 
      if ( max < msh[i] ) 
         max = msh[i]; 
  
   return max; 
} 
  
int main() 
{ 
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        Box arr[n];
        for(ll i = 0; i < n; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            arr[i].h = x;
            arr[i].w = y;
            arr[i].d = z;
        }
        printf("%d\n", maxStackHeight (arr, n) ); 
    }

  
  return 0; 
} 