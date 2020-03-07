#include<bits/stdc++.h>
using namespace std;

struct Trie { 
    string key; 
    int cnt; 
    unordered_map<char, Trie*> map; 
}; 
  
/* Function to return a new Trie node */
Trie* getNewTrieNode() 
{ 
    Trie* node = new Trie; 
    node->cnt = 0; 
    return node; 
} 
  
/* function to insert a string */
void insert(Trie*& root, string& str) 
{ 
    // start from root node 
    Trie* temp = root; 
  
    for (int i = 0; i < str.length(); i++) { 
  
        char x = str[i]; 
  
        /*a new node if path doesn't exists*/
        if (temp->map.find(x) == temp->map.end()) 
            temp->map[x] = getNewTrieNode(); 
  
        // go to next node 
        temp = temp->map[x]; 
    } 
  
    // store key and its count in leaf nodes 
    temp->key = str; 
    temp->cnt += 1; 
} 
  
/* function for preorder traversal */
bool preorder(Trie* temp, int& maxcnt, string& key) 
{ 
    if (temp == NULL) 
        return false; 
  
    for (auto it : temp->map) { 
  
        /*leaf node will have non-zero count*/
        if (maxcnt < it.second->cnt) { 
            key = it.second->key; 
            maxcnt = it.second->cnt; 
        } 
  
        // recurse for current node children 
        preorder(it.second, maxcnt, key); 
    } 
} 
  
void mostFrequentWord2(string arr[], int n) 
{ 
    // Insert all words in a Trie 
    Trie* root = getNewTrieNode(); 
    for (int i = 0; i < n; i++) 
        insert(root, arr[i]); 
  
    // Do preorder traversal to find the 
    // most frequent word 
    string key; 
    int cnt = 0; 
    preorder(root, cnt, key); 
  
    cout << key << endl; 
}

int main(){
    string str1;
    getline(cin, str1);
    string str[str1.length() + 100]; int count = 0; string ans = "";
    int n = str1.length();
    for(int i = 0; i < n; i++){
        if(str1[i] == 32){
            cout << "ans: " << ans << endl;
            str[count] = ans;
            count++; ans = "";
        }
        else{
            ans = ans + str1[i];
        }
    }
    str[count] = ans;
    cout << str[count] << endl;
    mostFrequentWord2(str, n);
} 
