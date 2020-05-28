#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t>0)
	{
		int i,co=0,n,k,flag=0,l;
		cin>>n>>k;
		int x=k;
		int arr[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			arr[i]--;

			if(arr[i]==i)
			co++;
 
		}
		cout << "co: " << co << endl;
 
		if((n-co)<=2 && co!=n)
		{
			cout<<-1<<"\n";
			t--;
			continue;
		}
		vector<int> v[k];
		int p=0;
		co=0;
		i=0;
		int p1,p2,p3,v1,v2,v3;
		while(i<n)
		{
			while(arr[i]==i && i<n)
			{
			   i++;
			 //  continue;
			}
 
			if(i==n)
			break;
 
 
				p1=-1;p2=-1;p3=-1;
				p1 = i;
				v1 = arr[i];
				p2 = v1;
				v2 = arr[p2];
				if(arr[p2]==i)
				{
					for(int q=v1-1;q>0;q--)
					{
						if(arr[q]==q || q==i)
						continue;
						else
						{
							p3 = q;
							break;
						}
					}
 
					if(p3==-1)
					{
						for(int q=v1+1;q<n;q++)
						{
							if(arr[q]==q || q==i)
							continue;
							else
							{
								p3 = q;
								break;
							}
						}
					}
 
				}
				else
				p3 = v2;
 
				if(p3==-1)
				{
					flag=1;
					break;
				}
 
				v3 = arr[p3];
 
				arr[p1] = v3;
				arr[p2] = v1;
				arr[p3] = v2;
				k--;
 
				// for(l=0;l<n;l++)
				// cout<<arr[l]<<" ";
				// cout<<endl;
 
				v[p].push_back(p1+1);
				v[p].push_back(p2+1);
				v[p].push_back(p3+1);
				p++;
 
				if(k<=0)
				{
					flag=1;
					break;
				}
 
 
		}
 
 
		if(k==0)
		{
		    for(l=0;l<n;l++)
    		if(arr[l]!=l)
    		{
    		    flag=1;
    		    break;
    		}
 
    		if(l==n)
    		flag=0;
		}
 
		if(flag==1)
		{
			cout<<-1<<"\n";
		}
		else
		{
			cout<<(x-k)<<"\n";
			for(i=0;i<p;i++)
			{
				cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
			}
		}
		t--;
	}
 
 
	// your code goes here
	return 0;
}