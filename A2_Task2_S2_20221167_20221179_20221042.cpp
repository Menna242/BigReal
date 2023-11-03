#include <bits/stdc++.h>
using namespace std;
#include "A2_Task2.h"
//#include "Task2.cpp"

int main(){
    cout<<"Enter the BigNumber:";
    string s;
    getline(cin,s);
    BigReal o1;
    BigReal oo(s);
    oo.printf();

    string ss;
    getline(cin,ss);
    BigReal oo2(ss);
    oo2.printf();

   oo.operator==(oo2);





}
