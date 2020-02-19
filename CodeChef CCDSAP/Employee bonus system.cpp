#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

vector<ll> vec[1000];
struct team{
    string teamId;
    string name;
    string description;
};

struct employee{
    string empId;
    string name2;
    string designation;
    ll rating;
    string managerId;
};

void bfs(int u, vector<ll> g[]) 
{ 
    queue<int> q; 

    bool * v = new bool[10000];
    memset(v, false, sizeof(v));
  
    q.push(u); 
    v[u] = true; 
    ll father = u;
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
  
        cout << "E" << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
            } 
        } 
    } 
}
 
int main()
{
    cout << "To enter the program please press 100" << endl;
    ll t;
    cin >> t;
    while(t == 100 && t != 4)
    {
        cout << "Hey welcome to the program" << endl;
        cout << "Add a team : Please press 1" << endl;
        cout << "Add an employee : Please press 2" << endl;
        cout << "View all employees: Please press 3" << endl;
        cout << "To exit the program type 4" << endl;
        ll option; 
        cin >> option;
        struct team arr[100];
        struct employee arr2[100];
        ll i = 0;
        ll j = 0;
        if(option == 1)
        {
            string x, y, z;
            getline(cin, x);
            getline(cin, y);
            getline(cin, z);
            arr[i].teamId = x;
            arr[i].name = y;
            arr[i].description = z;
            i++;
        }
        else if(option == 2)
        {
            string a, b, c, d;
            ll e;
            getline(cin, a);
            getline(cin, b);
            getline(cin, c);
            cin >> e;
            getline(cin, d);
            arr2[j].empId = a; arr2[j].name2 = b; arr2[j].designation = c;
            arr2[j].rating = e; arr2[j].managerId = e;
            j++;
            string str = d.substr(1, d.length() - 1);
            string work = a.substr(1, a.length() - 1);
            ll workConver = stoll(work);
            ll convert = stoll(str);
            // cout << "The value of the convert is : " << convert << endl;
            vec[convert].push_back(workConver);
        }
        else if(option == 3)
        {
            bfs(1, vec);
        }
        else if(option == 4)
        {
            cout << "Exiting the program, Thankyou" << endl;
            t = 4;
        }
    }
    
    return 0;
}