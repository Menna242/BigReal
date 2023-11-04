# include <bits/stdc++.h>
using namespace std;
#include "oopA2T2.h"

int main()
{
    cout<<"Enter the BigNumber:";
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
    cout<<"if you want to compare the integers enter c:\n"
        <<"if you want to add the integers enter d:\n"
        <<"if you want to subtract the integers enter s:\n";
    cin>>enter;
    if(enter=='c'){
        if(oo.operator==(oo2)==1) {
            cout<<"the integer in ob1==the integer ob2 &&the fraction in ob1==the fraction ob2";
        }
        else if(oo.operator<(oo2)==1){
            cout<<"The big number 1 < the big number 2";
        }
        else if (oo.operator>(oo2)==1){
            cout<<"The big number 1 > the big number 2";
        }
    }
    else if (enter=='d'){
        oo.add(oo2);
    }
    else if(enter=='s'){
        string difference = oo.subtract(oo2);
        cout << "Difference: " << difference << endl;

    }



}
