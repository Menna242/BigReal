// CS213-2023-s2-20221167-20221179-20221042-A2-part1.cpp

// FCAI - OOP Programming - 2023 - Assignment 2
// Program Name: CS213-2023-s2-20221167-20221179-20221042-A2-part1.cpp
// Last Modification Date : 5/11/2023
// Author1 and ID : Menna Essam Salah El-Din Mohamed (20221167)
// Author2 and ID : Nada Adel Ahmed Nagy             (20221179)
// Author3 and ID : Touka Atef El-Sayed Abu-ElAzm    (20221042)
// Teaching Assistant: Eng\ Khaled

# include <bits/stdc++.h>
using namespace std;
#include "The_BigReal.h"

int main()
{
    cout<<"Enter the BigNumber:";
    string s;
    getline(cin,s);  //55555.666825
    BigReal o1;
    BigReal oo(s);
    print_num(oo);

    cout<<"Enter the BigNumber:";
    string ss;
    getline(cin,ss);   //999999.8648
    BigReal oo2(ss);
    print_num(oo2);


    BigReal oo3=oo2;
    cout<<"By operator equal:";
    print_num(oo3);



    BigReal oo4(oo);
    cout<<"By copy constractor:";
    print_num(oo4);



    int enter;
    cout<<"if you want to compare the integers enter 1:\n"
        <<"if you want to compare the integers enter 2:\n"
        <<"if you want to compare the integers enter 3:\n";
    while ( cin>>enter&&enter>=1){

        if(enter==1){
            if(oo.operator==(oo2)==1) {
                cout<<"the integer in ob1==the integer ob2 &&the fraction in ob1==the fraction ob2\n";
            }
            else if(oo.operator<(oo2)==1){
                cout<<"The big number 1 < the big number 2\n";
            }
            else if (oo.operator>(oo2)==1){
                cout<<"The big number 1 > the big number 2\n";
            }
        }
        else if (enter==2){
            oo.add(oo2);
        }
        else if(enter==3){
           oo.subtract(oo2);
        }
        cout<<"if you want to compare the integers enter 1:\n"
            <<"if you want to compare the integers enter 2:\n"
            <<"if you want to compare the integers enter 3:\n";


    }



}
