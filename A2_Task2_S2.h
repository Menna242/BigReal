//#include <bits/stdc++.h>
//using namespace std;
class BigReal{
private:
    string BigNumber,integer,fraction;
    char sign;
public:

    BigReal(){
        integer='0';
        fraction='0';
    }

    BigReal(string real){
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
            BigNumber="0.0";
        }


    }
    void printf(){
        cout<<integer<<" "<<fraction;
//        cout<<BigNumber;
    }


};