#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void buildtree(int * arr, int * tree, int start, int end, int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildtree(arr, tree, start, mid, 2*treeNode);
    buildtree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}

void updateTree(int * arr, int * tree, int start, int end, int treeNode, int index, int value)
{
    if(start == end)
    {
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end) / 2;
    if(index > mid)
    {
        updateTree(arr, tree, mid + 1, end, 2*treeNode + 1, index, value);
    }
    else
    {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);   
    }

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);  
}

int minInTree(int * tree, int start, int end, int treeNode, int left, int right, int &mini)
{
    if(start > right || end < left)
    {
        return mini;
    }

    if(start >= left && end <= right)
    {
        mini = min(mini, tree[treeNode]);
        return mini;
    }

    int mid = (start + end) / 2;
    int ans = minInTree(tree, start, mid, 2*treeNode, left, right, mini);
    int ans2 = minInTree(tree, mid + 1, end, 2*treeNode + 1, left, right, mini);
    mini = min(ans, ans2);
    return mini;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int * tree = new int[4 * n];

    buildtree(arr, tree, 0, n - 1, 1);

    for(int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    while(q--)
    {
        char s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        if(s == 'q')
        {
            int mini = INT_MAX;
            cout << minInTree(tree, 0, n - 1, 1, x - 1, y - 1, mini) << endl;
            mini = INT_MAX;
        }
        else
        {
            updateTree(arr, tree, 0, n - 1, 1, x - 1, y);
                for(int i = 1; i < 2 * n; i++)
                {
                    cout << tree[i] << " ";
                }
                cout << endl;
        }
    }

    return 0;
}