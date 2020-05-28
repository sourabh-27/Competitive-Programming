#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int number(int num){
    string s = to_string(num);
    if(s.length() == 1){
      return 0;
    }
    string s1 = s.substr(1);
    // cout << "stoi: " <<  stoi(s1) << endl;
    return stoi(s1);
}

int first(int num){   
    
     string s = to_string(num);
    //  cout  << "check: " << s << endl;
    char  s2 =s[0];
    // cout << "s2: " << s2 << endl;
    int tmp=s2-'0';
    // cout << "tem" << tmp << endl;
    return tmp;
    
}

void printKeypad(int num, string output = ""){
    
    // cout << "num: " << num << endl;
    if(num == 0){
        
        cout<<output<<endl;
        return;
    }
    
    int key = first(num);
    // cout << "key: " << key << endl;
    int boo = number(num);
    // cout << "boo: " << boo << endl;
    
    if(key == 2){
        
        printKeypad(boo, output+"a");
        printKeypad(boo, output+"b");
        printKeypad(boo, output+"c");       
        
    }
    else if(key == 3){
        
        printKeypad(boo, output+'d');
        printKeypad(boo, output+ 'e');
        printKeypad(boo, output+'f');       
        
    }
      // else if(key == 4){
        
//         printKeypad(boo, output+"g");
//         printKeypad(boo, output+"h");
//         printKeypad(boo, output+"i");
        
//     }else if(key == 5){
        
//         printKeypad(boo, output+"j");
//         printKeypad(boo, output+"k");
//         printKeypad(boo, output+"l");
        
//     }else if(key == 6){
        
//         printKeypad(boo, output+'m');
//         printKeypad(boo, output+'n');
//         printKeypad(boo, output+'o');
       
//     }else if(key == 7){
        
//         printKeypad(boo, output+'p');
//         printKeypad(boo, output+'q');
//         printKeypad(boo, output+'r');
//         printKeypad(boo, output+'s');
        
//     }else if(key == 8){
        
//         printKeypad(boo, output+'t');
//         printKeypad(boo, output+'u');
//         printKeypad(boo, output+'v');
        
//     }else if(key == 9){
        
//         printKeypad(boo, output+'w');
//         printKeypad(boo, output+'x');
//         printKeypad(boo, output+'y');
//         printKeypad(boo, output+'z');
        
//     }    

}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
