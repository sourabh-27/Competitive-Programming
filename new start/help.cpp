#include<bits/stdc++.h>
using namespace std;
void print(bool** edges,int n,int sv){//DFS-depth first search it goes in one direction until the chain ends
	queue<int> pendingVertices;
	bool* visited=new bool[n];
	for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

	pendingVertices.push(sv);
	visited[sv]=true;
	while(!pendingVertices.empty()){
		int currentIndex=pendingVertices.front();
		pendingVertices.pop();
		cout<<currentIndex<<" ";
        visited[currentIndex] = true;
		for(int i=0;i<n;i++){
            if(i==currentIndex)
                continue;
			if(edges[currentIndex][i]&& !visited[i]){
				pendingVertices.push(i);
				visited[i]=true;
			}
		}
	}
}	
int main(){
	int n,e;
	cin>>n>>e;
	bool** edges = new bool*[n];
	
	for(int i=0;i<n;i++){
		edges[i]=new bool[n];
			for(int j=0;j<n;j++){
				edges[i][j]=false;
			}
		}
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=edges[s][f]=true;
	}
	print(edges,n,0);
}