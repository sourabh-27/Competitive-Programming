#include<bits/stdc++.h>
using namespace std;
struct node{
  int maxsum;
  int sum;
    int bps;
    int bss;
    node()
    {
        maxsum = sum = bps = bss = -0x3f3f;
    }
};
 void buildtree(long long *arr,node *tree,int treen,int start,int end)
 {
     if(start==end)
     {
         tree[treen].maxsum=arr[start];
         tree[treen].sum=arr[start];
         tree[treen].bps=arr[start];
         tree[treen].bss=arr[start];
         return ;
     }
     else
     {
     int mid=(start+end)/2;
     buildtree(arr,tree,2*treen,start,mid);
     buildtree(arr,tree,2*treen+1,mid+1,end);
     node left=tree[2*treen];
     node right=tree[2*treen+1];
     tree[treen].maxsum=max(left.maxsum, max(right.maxsum, left.bss + right.bps));
     tree[treen].sum=left.sum+right.sum;
     tree[treen].bps=max(left.bps,(left.sum+right.bps));
     tree[treen].bss=max(right.bss,(right.sum+left.bss));
     return;
     }
 }
node quer(long long *arr,node *tree,int start,int end,int treen,int lefti,int righti)
{
    if(start>righti || end<lefti)
    {
        node ans2;   
        return ans2;
    }
    if(start>=lefti && end<=righti)
    {
        return tree[treen];
    }
    int mid=(start+end)/2;
  node left= quer(arr,tree,start,mid,2*treen,lefti,righti);
  node right=quer(arr,tree,mid+1,end,2*treen+1,lefti,righti);
    node ans;     
ans.maxsum=max(left.maxsum, max(right.maxsum, left.bss + right.bps));
    ans.sum=left.sum+right.sum;
     ans.bps=max(left.bps,(left.sum+right.bps));
    ans.bss=max(right.bss,(right.sum+left.bss));
     return ans;
}
int main() {

	// Write your code here;
    int n;
    cin>>n;
    long long arr[n];
    node tree[4*n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildtree(arr,tree,1,0,n-1);
    // for(int i=0; i < 3*n; i++){
    //     cout << tree[i].maxsum << " " << tree[i].bps << " " << tree[i].bss << " " << tree[i].sum << endl;
    // }
    // cout << endl;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x,y;
         node ans=quer(arr,tree,0,n-1,1,x-1,y-1);
        cout<<ans.maxsum<<endl;
    }
}




