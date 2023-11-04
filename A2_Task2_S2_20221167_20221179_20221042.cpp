// CS213-2023-s2-20221167-20221179-20221042-A2-part1.cpp

// FCAI - OOP Programming - 2023 - Assignment 2
// Program Name: CS213-2023-s2-20221167-20221179-20221042-A2-part1.cpp
// Last Modification Date : 5/11/2023
// Author1 and ID : Menna Essam                      (20221167)
// Author2 and ID : Nada Adel Ahmed Nagy             (20221179)
// Author3 and ID : Touka Atef El-Sayed Abu-ElAzm    (20221042)
// Teaching Assistant:


# include <bits/stdc++.h>
using namespace std;
#include "A2_Task2_S2.h"

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
        oo.addition(oo2);
    }
    else if(enter=='s'){
        string difference = oo.subtract(oo2);
        cout << "Difference: " << difference << endl;

    }

}


