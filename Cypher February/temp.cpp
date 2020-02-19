#include <iostream>
using namespace std;

int main(){
    unsigned int k = 0;
    k = ~k;
    cout << "k: " << k << endl;
    if(k == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}