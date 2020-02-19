#include<bits/stdc++.h>
using namespace std;
struct node{
string str;
int num=3;
};

void buildtree(string& s,node* tree,int start,int end,int tn,int *a)
{
if(start==end)
{
tree[tn].str=s[start];
char x=s[start];
if(x=='1')
tree[tn].num=1;
else
tree[tn].num=0;
return;
}
int mid=(start+end)/2;
buildtree(s,tree,start,mid,2*tn,a);
buildtree(s,tree,mid+1,end,2*tn+1,a);

tree[tn].str=tree[2*tn].str+tree[2*tn+1].str;
tree[tn].num=((tree[2*tn].num*a[end-mid])%3 + (tree[2*tn+1].num)%3)%3;

}
void update(string& s,node* tree,int start,int end,int tn,int val,int *a)
{
if(start==end){
char x=s[val];

if(x=='0'){
s[val]='1';
tree[tn].str='1';
tree[tn].num=1;
}
return;
}
int mid=(start+end)/2;
if(val>mid)
update(s,tree,mid+1,end,2*tn+1,val,a);
else
update(s,tree,start,mid,2*tn,val,a);

tree[tn].str=tree[2*tn].str+tree[2*tn+1].str;
tree[tn].num=((tree[2*tn].num*a[end-mid])%3 + (tree[2*tn+1].num)%3)%3;

}
node query(node *tree,int start,int end,int tn,int left,int right,int *a)
{
if(start>right || end < left)
{
node a;
return a;
}
if(start>=left && end<=right)
return tree[tn];
int mid=(start+end)/2;
node ans1=query(tree,start,mid,2*tn,left,right,a);
node ans2=query(tree,mid+1,end,2*tn+1,left,right,a);
node ans3;
ans3.str=ans1.str+ans2.str;
ans3.num=((ans1.num*a[right-end])%3 + (ans2.num)%3)%3;
return ans3;

}
int main() {

int n;
cin>>n;
string s;
cin>>s;
int a[n+1]={0};
a[0]=1;
for(int i=1;i<=n;i++)
{
a[i]=(a[i-1]*2)%3;
}
node *tree=new node[4*n];
buildtree(s,tree,0,n-1,1,a);

int m;
cin>>m;
for(int i=0;i<m;i++)
{
int x;
cin>>x;
if(x==1)
{ int y;
cin>>y;
update(s,tree,0,n-1,1,y,a);

}
else{
int l,r;
cin>>l>>r;
node ans=query(tree,0,n-1,1,l,r,a);
// ans.num=binaryToDecimal(ans.str);
cout<<ans.num<<endl;
//int num=binaryToDecimal(s.substr(l,r-l+1));
//cout<<num<<endl;
}
}
}



// int binaryToDecimal(string n)
// {
// string num = n;
// int dec_value = 0;

// int base = 1;

// int len = num.length();
// for (int i = len - 1; i >= 0; i--) {
// if (num[i] == '1')
// dec_value =dec_value%3 +base%3;
// base = (base * 2)%3;
// }

// return dec_value%3;
// }