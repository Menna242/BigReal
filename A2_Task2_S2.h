class BigReal{
private:
    string BigNumber,integer,fraction;
   int intSize,fractionSize ;
    char sign;
public:

    BigReal(){
        integer='0';
        fraction='0';
    }

    BigReal(string real){
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
//----------------------------------------------------------------------------------
    BigReal Size1(BigReal number2){
        BigReal result;
        if(intSize!=number2.intSize){
            if(number2.intSize<intSize){
                for (int i = 0; i < intSize-number2.intSize; ++i) {
                    number2.integer="0"+number2.integer;
                   result.integer =number2.integer;
                }

            }
            else if(number2.intSize>intSize){
                for (int i = 0; i < number2.intSize-intSize; ++i) {
                    integer="0"+integer;
                }
            }

        }

        if(fractionSize!=number2.fractionSize){
            if(fractionSize>number2.fractionSize){
                for (int i = 0; i < fractionSize-number2.fractionSize; ++i) {
                    number2.fraction=number2.fraction+"0";
                    result.fraction=number2.fraction;
                }
            }
            else if (fractionSize<number2.fractionSize){
                for (int i = 0; i < number2.fractionSize-fractionSize; ++i) {
                   fraction =fraction+"0";
                }
            }
        }


        return result;
    }

    bool operator==(BigReal oo2){
        Size1(oo2);
        if(intSize==oo2.intSize&&fractionSize==oo2.fractionSize){
            if(integer==oo2.integer){
                if(fraction==oo2.fraction){
                    cout<<"the integer in ob1==the integer ob2 &&the fraction in ob1==the fraction ob2";
                    return 1;
                }
                else{
                    cout<<"the integer in ob1==the integer ob2 &&the fraction in ob1!=the fraction ob2";
                    return 0;
                }
            }
            else{
                cout<<"the integer in ob1!=the integer ob2 ";

                return 0;
            }
        }

    }
//
//
//    BigReal operator<(BigReal ){
//
//
//
//
//
//
//
//    }
//
//
//
//
//

    void printf(){
        cout<<BigNumber<<"-->";
        cout<<integer<<" "<<fraction<<" ";
        cout<<"\n";
    }


};
