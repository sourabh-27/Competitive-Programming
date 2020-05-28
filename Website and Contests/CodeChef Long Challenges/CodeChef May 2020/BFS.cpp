#include<bits/stdc++.h>
using namespace std;





void printBFS(int **edges, int n, int sv,bool * visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex << " ";
        for( int i=0;i<n;i++){
            if( i== currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1){
                if(visited[i]==false){
                    pendingVertices.push(i);
                    visited[i]=true;
                }
            }
            
        }
    }
    delete[] visited;
}

void BFS(int **edges,int n){
    bool * visited =new bool[n];
    memset(visited, false, sizeof(visited));
    for(int j = 0; j < n; j++){
                cout << visited[j] << " ";
                cout << endl;
            }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout << "i: " << i << endl;
            printBFS(edges,n,i,visited);
            for(int j = 0; j < n; j++){
                cout << visited[j] << " ";
                cout << endl;
            }
        }
                        
    }
    delete[] visited;
}



int main() {
    int n, e;
    cin >> n >> e;
int **edges=new int*[n];
    for( int i=0;i<n;i++){
        edges[i]=new int[n];
        for( int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
 for( int i=0;i<e;i++){
     int first,second;
     cin>>first>>second;
     edges[first][second]=1;
     edges[second][first]=1;     
 }
    BFS(edges,n);

  return 0;
}
