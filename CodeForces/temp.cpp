 	#include<bits/stdc++.h>
    using namespace std;
	 	#include<bits/stdc++.h>
    using namespace std;
	void PairSum(int *input, int n) {	 
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
     	unordered_map <int,int> m1;
        for(int i=0;i<n;i++)
        {
            m1[input[i]]++;
		}
        unordered_map <int,int> :: iterator it=m1.begin();
        while(it!=m1.end())
        {
            // cout << "first: " << it->first << " second: " << it->second << endl;
     	int left=it->second;
     	int right=m1[-(it->first)];
            // cout << "left: " << left << " right: " << right << endl;
     	int total=left*right;
     	while(total>0)
     	{
     	cout<<min(it->first,-it->first)<<" "<<max(it->first,-it->first)<<endl;
     	total--;
     	}   
     	m1[it->first]=0;
     	m1[-it->first]=0;
     	it++;
     	}
 	}



int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

