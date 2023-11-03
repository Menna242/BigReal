#include <bits/stdc++.h>
using namespace std;
#include "A2_Task2.h"

BigReal::BigReal() {
    integer='0';
    fraction='0';
    sign='+';
    intSize=0;
    fractionSize=0;
}
BigReal::BigReal(string real) {
    if(real[0]=='+'||real[0]=='-') {
        for (int i = 1; i < real.size(); ++i) {
            if(!isdigit(real[i])&&real[i]!='.'){
                real[i]='0';
            }
            else{
                break;
            }
        }
    }
    if(regex_match(real,regex("[+-]?\\d+"))){
        if(real[0]=='+'){  //+11
            sign='+';
            real[0]='0';
            integer=real;
            fraction="0";
        }

        else if(real[0]=='-'){  //-11.11
            sign='-';
            real[0]='0';
            integer=real;
            fraction="0";
        }

        else{      //11.11
            sign='+';
            integer=real;
            fraction="0";
        }
    }
    else if(regex_match(real,regex("[+-]?\\d*.?\\d+"))){
        if(real[0]=='+'){  //+11.11
            sign='+';
            real[0]='0';
            integer=real.substr(0,real.find('.'));
            fraction=real.substr(integer.size()+1,real.size()-1);
        }

        else if(real[0]=='-'){  //-11.11
            sign='-';
            real[0]='0';
            integer=real.substr(0,real.find('.'));
            fraction=real.substr(integer.size()+1,real.size()-1);


        }
        else{      //11.11
            sign='+';
            if(real[0]=='.'){
                integer="0";
                fraction=real.substr(integer.size(),real.size()-1);

            }
            else{
                integer=real.substr(0,real.find('.'));
                fraction=real.substr(integer.size()+1,real.size()-1);
            }


        }
    }

    else{
        cout<<" the big number is invalid.\n";
        integer="0";
        fraction="0";
    }

    intSize=integer.size(); fractionSize=fraction.size();
    BigNumber=sign+integer+'.'+fraction;
}

bool BigReal::operator==(BigReal oo2) {
    if(intSize!=oo2.intSize||fractionSize!=oo2.fractionSize){
        if(intSize!=oo2.intSize){
            if(oo2.intSize<intSize){
                for (int i = 0; i < intSize-oo2.intSize; ++i) {
                    oo2.integer="0"+oo2.integer;
                }

            }
            else if(oo2.intSize>intSize){
                for (int i = 0; i < oo2.intSize-intSize; ++i) {
                    integer="0"+integer;
                }
            }
            oo2.intSize=intSize;
        }

        if(fractionSize!=oo2.fractionSize){
            if(fractionSize>oo2.fractionSize){
                for (int i = 0; i < fractionSize-oo2.fractionSize; ++i) {
                    oo2.fraction=oo2.fraction+"0";
                }
            }
            else if (fractionSize<oo2.fractionSize) {
                for (int i = 0; i < oo2.fractionSize - fractionSize; ++i) {
                    fraction = fraction + "0";
                }
            }
            oo2.fractionSize=fractionSize;
        }
    }

    if(sign==oo2.sign){
        if(intSize==oo2.intSize&&fractionSize==oo2.fractionSize){
            if(integer==oo2.integer&&fraction==oo2.fraction){
                return true;
            }
            else{
                return false;
            }

        }
    }

    else{
        return false;
    }


}

int BigReal::operator<(BigReal oo2) {
    if(sign==oo2.sign&&sign=='+'){
        if(integer<oo2.integer||fraction<oo2.fraction){
            return 1;
        }
        else{
            return 2;
        }
    }

    else if(sign==oo2.sign&&sign=='-'){
        if(integer<oo2.integer||fraction<oo2.fraction){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(sign=='-'&&oo2.sign=='+'){
        return 1;
    }
    else if(sign=='+'&&oo2.sign=='-'){
        return 2;
    }

}
void BigReal::printf() {
    cout<<BigNumber<<"-->";
    cout<<integer<<" "<<fraction<<" ";
    cout<<"\n";
}