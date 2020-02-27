#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test_cases ;
	cin >> test_cases;

	for(int i=0;i<test_cases;i++)
	{
		string str;
		cin >> str;
		int length = str.size();
		map<char,vector<int>> m;
		for(int j=0;j<length;j++)
		{
			m[str[j]].push_back(j);
		}

        int totalSize = sizeof(m); int cou = 0;
        for ( std::map<char, vector<int>>::iterator i = m.begin() ; i != m.end() ; i++ )
                cou++;
        totalSize += cou * sizeof(char);
        totalSize += cou * sizeof(vector<int>);
        cout << "totalSize: " << totalSize << endl;

	 	map<char,vector<int>> :: iterator it;
	 	int odd = 0;
	 	for(it=m.begin();it!=m.end();it++)
	 	{
	 		if((it->second).size()%2 != 0)
	 		{
	 			odd++;
	 		}
	 	}


	 	if(odd > 1)
	 	cout<<"-1";
		else
		{
			int res[length];
			int k = length-1;
			int start = 0;
			int end = length-1;
			while(k>=0)
			{
				for(it=m.begin();it!=m.end();it++)
				{
					int frequency = it->second.size();
					if( (frequency%2 != 0))
					{
						res[length/2] = it->second[(it->second).size()/2];
						k--;
					}
					while(frequency > 1)
					{
						if((start <= end ) && (start<length) && (end >= 0))
						{
							res[start] =  (it->second)[0];
							(it->second).erase((it->second).begin());
							res[end] =  (it->second)[(it->second).size()-1];
							(it->second).pop_back();
							start++;
							end--;
							k -= 2;
							frequency -= 2;
						}
					}
				}
			}
			for(int j=0;j<length;j++)
			  cout<<res[j]+1<<" ";

			//delete str;
		}
		cout<<endl;


	 }

	return 0;
}