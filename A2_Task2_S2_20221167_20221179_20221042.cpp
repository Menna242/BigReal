#include <bits/stdc++.h>
using namespace std;
#include "A2_Task2_S2.h"

int main(){
    /*cout<<"Enter the BigNumber:";
    string s;
    getline(cin,s);
    BigReal o1;
    BigReal oo(s);
    oo.printf();

    cout<<"Enter the BigNumber:";
    string ss;
    getline(cin,ss);
    BigReal oo2(ss);
    oo2.printf();

    char enter;
    cout<<"Compare the integers: ";
    cin>>enter;
    if(enter=='c'){
        if(oo.operator==(oo2)==1) {
            cout<<"the integer in ob1==the integer ob2 &&the fraction in ob1==the fraction ob2";
        }
        else if(oo.operator<(oo2)==1){
            cout<<"The big number 1 < the big number 2";
        }
        else if (oo.operator<(oo2)==2){
            cout<<"The big number 1 > the big number 2";
        }
    }
*/
    string s1, s2;
    cout << "Enter the first number:";
    getline(cin,s1);
    cout << endl;
    cout << "Enter the second number:";
    getline(cin , s2);
    BigReal a(s1);
    BigReal b(s2);
    a.add(b);

}


