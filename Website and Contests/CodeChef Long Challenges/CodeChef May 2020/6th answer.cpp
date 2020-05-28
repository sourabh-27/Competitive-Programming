#include <iostream>
#include <string>
// #include <math.h>
using namespace std;
 
int relu(int a)
{
	if (a<0) return 0;
	return a;
}
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		string A, B;
		cin >> A;
		cin >> B;
		int N;
		cin >> N;
		string arr[N];
		int b[N];
		for (int i = 0; i < N; i++) cin >> arr[i] >> b[i];
		int Al = A.length();
		int Bl = B.length();
		int beautyA[Al] = {0};
		for (int i = 0; i < Al; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int len = arr[j].length();
				if (i+len<=Al && A.substr(i,len)==arr[j]) 
				{
					beautyA[i+len-1] += b[j];
				}
			}
		}
		int beautyB[Bl] = {0};
		for (int i = 0; i < Bl; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int len = arr[j].length();
				if (i+len<=Bl && B.substr(i,len)==arr[j]) 
				{
					beautyB[i] += b[j];
				}
			}
		}
		// for (int i = 0; i < Bl; i++) cout << beautyB[i] << " ";
		string C;
		int maxPleasure = 0;
		int pleasureB = 0;
		int pleasureA = 0;
		// for (int i = 0; i < Al; i++) pleasureB += beautyA[i];
		for (int i = 0; i < Bl; i++) pleasureB += beautyB[i];
		for (int i = 0; i < Al; i++) 
		{
			pleasureA += beautyA[i];
			int pleasure = pleasureB + pleasureA;
		 	for (int j = 0; j < Bl; j++)
		 	{
		 		C = A.substr(0,i+1) + B.substr(j,Bl-j);
		 		int Cl = i+1+Bl-j;
				if (j != 0) pleasure -= beautyB[j-1];
				int chipku = 0;
				for (int k = 0; k < N; k++)
				{
					int len = arr[k].length();
					for (int pos = relu(i-len+2); pos<=i && pos+len<=Cl; pos++)
					{
						// if (C.substr(pos,len)==arr[k]) chipku += b[k];
						bool f = 1;
						int n = 0;
						for (int m = pos; f && m <len+pos; m++, n++)
						{
							if (arr[k][n] != C[m]) f = 0;
						}
						if (f) chipku += b[k];
						//cout << i << " " << C.substr(pos,len) << endl;
					}
				}
				if (pleasure+chipku > maxPleasure) maxPleasure = pleasure+chipku;
		 	}
		 }
		 cout << maxPleasure << endl;
	}
	return 0;
}