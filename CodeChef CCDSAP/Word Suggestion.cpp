#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long int ll; //shortcut to use long long int

struct values{
    string name; //to store the name
    ll same_Word_Count; //to store the number of letters that are actually similar
    ll size_Difference; //to store the size difference in input and given string 
    ll frequency; //to store the given frequency
};

bool sortingCompare(values a, values b) //compare function to sort the array
{
    if(a.same_Word_Count > b.same_Word_Count)
    {
        return true;
    }
    else if(a.same_Word_Count < b.same_Word_Count)
    {
        return false;
    }
    else
    {
        if(a.frequency > b.frequency)
        {
            return true;
        }
        else if(a.frequency < b.frequency)
        {
            return false;
        }
        else
        {
            if(a.size_Difference <= b.size_Difference)
            {
                return true;
            }
            else
            {
                return false; 
            }
        }
    }
}

vector<pair<string, ll>> readRecord()
{
    fstream fin;
    fin.open("input.csv", ios::in); //to input the csv file
    string current_Row = "", temp = "";
    vector<pair<string, ll>> vec; //creating a container to store all the element of a particual row in a string and pushing in a vector
    while (fin >> temp)
    {
        getline(fin, current_Row); //fetching the row
        current_Row = temp + current_Row;
        string newstring = "";
        pair<string, ll> pair1; //making pair for name and frequency
        for(ll i = 0; i < current_Row.length(); i++)
        {
            if(i == current_Row.length() - 1)
            {
                newstring = newstring + current_Row[i];
                ll k = stoll(newstring);
                pair1.second = k;
                newstring = "";
                vec.push_back(pair1);
            }
            else if(current_Row[i] == 44)
            {
                pair1.first = newstring;
                newstring = "";
            }
            else if(current_Row[i] == 32 || current_Row[i] == 39)
            {
                continue;
            }
            else
            {
                newstring = newstring + current_Row[i]; //creating and adding every element of string to newstring
            }
        }
    }
     return vec; //returning the vector 
}

int main()
{
    fast;
    vector<pair<string, ll>> read_Name_And_Frequency = readRecord(); //to read the CSV file
    string input_String;
    cin >> input_String; //getting the input from the user
    ll input_Length = input_String.length(); //length of input string 
    struct values arr[read_Name_And_Frequency.size() + 2];

    for(ll i = 0; i < read_Name_And_Frequency.size(); i++)
    {
        arr[i].name = read_Name_And_Frequency[i].first;
        arr[i].frequency = read_Name_And_Frequency[i].second;
        ll count_Similar_Words = 0;
        for(ll j = 0; j < arr[i].name.length(); j++) //to count no. of similar words
        {
            if(input_String[j] == arr[i].name[j] || input_String[j] - arr[i].name[j] == 32)
            {
                count_Similar_Words++;
            }
        }
        arr[i].same_Word_Count = count_Similar_Words;
        arr[i].size_Difference = abs(arr[i].name.length() - input_Length);
    }

    sort(arr, arr + input_Length, sortingCompare);
    for(ll i = 0; i < 5; i++)
    {
        cout << arr[i].name;
        if(i == 5)
        {
            break;
        }
        cout << ", ";
    }
    return 0;
}
