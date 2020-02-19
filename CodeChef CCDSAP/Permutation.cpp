#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long int ll; //shortcut to use long long int   1

void find_All_Permutation(vector<string> Records_Row_Wise, string str, ll currIndex, string &ans)
{
    if(currIndex == Records_Row_Wise.size())
    {
        ans = ans + str + ", "; //storing this permutation
        return;
    }

    string previous_String = str; //storing the string so that when recursion return it can be called on that particular index
    for(ll i = 0; i < Records_Row_Wise[currIndex].size(); i++)
    {
        str = str + Records_Row_Wise[currIndex][i]; //adding the first element of a particular index
        find_All_Permutation(Records_Row_Wise, str, currIndex + 1, ans); //recurstion to get all the permutation
        str = previous_String; //as the string was changed so changing it to previous before again calling recurstion
    }
}

vector<string> readRecord()
{
    fstream fin;
    fin.open("input.csv", ios::in); //to input the csv file
    string current_Row, temp = "";
    vector<string> vec; //creating a container to store all the element of a particual row in a string and pushing in a vector
    while (fin >> temp)
    {
        getline(fin, current_Row); //fetching the row
        current_Row = temp + current_Row;
        string newstring = "";
        for(ll i = 0; i < current_Row.length(); i++)
        {
            if(current_Row[i] == 32 || current_Row[i] == 39 || current_Row[i] == 44)
            {
                continue;
            }
            else
            {
                newstring = newstring + current_Row[i]; //creating and adding every element of string to newstring
            }
        }
        vec.push_back(newstring); //inserting every row in the vector
    }
    return vec; //returning the string
}

int main()
{
    fast;
    vector<string> Records_Row_Wise = readRecord(); //to read the csv file
    string ans = ""; //final answer will be stored here
    find_All_Permutation(Records_Row_Wise,"", 0, ans); //to find all the permutations possible
    for(ll i = 0; i < ans.length() - 2; i++)
    {
        cout << ans[i];
    }
    return 0;
}

/*Here we simply need to print all the permutations possible.
So we first take the input in a vector of strings. Now we call the function to find the permutation
The function permuatation simply adds one character of the string and then calls the function recursively to generate
all the other strings that are possible. The base case is when there are no more characters to add from a row, we simply return.
Also we maintain a previous String so when the recursive function return we can call the function for other indexs removing the 
previous index. */