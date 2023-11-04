#include <bits/stdc++.h>
using namespace std;
#include "oopA2T2.h"
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

bool BigReal::operator<(BigReal oo2) {
    if(sign==oo2.sign&&sign=='+'){
        if(integer<oo2.integer||fraction<oo2.fraction){
            return true;
        }
        else{
            return false;
        }
    }

    else if(sign==oo2.sign&&sign=='-'){
        if(integer>oo2.integer||fraction>oo2.fraction){
            return true;
        }
        else{
            return false;
        }
    }
    else if(sign=='-'&&oo2.sign=='+'){
        return true;
    }
    else if(sign=='+'&&oo2.sign=='-'){
        return false;
    }

}

bool BigReal::operator>(BigReal oo2) {
    if(sign==oo2.sign&&sign=='+'){
        if(integer>oo2.integer||fraction>oo2.fraction){
            return true;
        }
        else{
            return false;
        }
    }

    else if(sign==oo2.sign&&sign=='-'){
        if(integer<oo2.integer||fraction<oo2.fraction){
            return true;
        }
        else{
            return false;
        }
    }
    else if(sign=='-'&&oo2.sign=='+'){
        return false;
    }
    else if(sign=='+'&&oo2.sign=='-'){
        return true;
    }
}
//---------------------------------------------------------------------
void BigReal::add(BigReal& other){
    string result = "";
    char result_sign;
    int carry = 0;
    if(sign == '+' && other.sign == '+'){
        result_sign = '+';
    }
    else if(sign == '-' && other.sign == '-'){
        result_sign = '-';
    }
    else{
        // Subtraction
    }

    // Firstly we need to make the number of digits equal in both a and b
    // padding with zero's
    if(fraction.size() != other.fraction.size()){
        if(fraction.size() > other.fraction.size()){
            int dif = fraction.size() - other.fraction.size();
            while(dif--){
                other.fraction = other.fraction +  "0";
            }
        }
        else{
            int dif = other.fraction.size() - fraction.size();
            while(dif--){
                fraction = fraction + "0";
            }
        }
    }

    // Adding the fraction , integer parts
    // Adding the fraction part
    int fractionSize_a = fraction.size();
    int fractionSize_b = other.fraction.size();
    int i = fractionSize_a - 1;
    int j = fractionSize_b - 1;

    int sum;
    while (i >= 0 || j >= 0) {
        sum = carry;
        if (i >= 0)
            sum += (fraction[i] - '0');
        if (j >= 0)
            sum += (other.fraction[j] - '0');
        carry = sum / 10;
        sum %= 10;
        result = to_string(sum) + result;
        i--; j--;
    }
    int decimalPosition;
    decimalPosition = result.size();

    // Adding the integer part
    int integerSize_a = integer.size();
    int integerSize_b = other.integer.size();
    i = integerSize_a - 1;
    j = integerSize_b - 1;
    while (i >= 0 || j >= 0) {
        sum = carry;
        if (i >= 0)
            sum += (integer[i] - '0');
        if (j >= 0)
            sum += (other.integer[j] - '0');
        carry = sum / 10;
        sum %= 10; // It gives the current digit of result
        result = to_string(sum) + result;
        i--; j--;
    }

    if (carry > 0) {
        result = to_string(carry) + result;
    }


    // Printing result of adding
    cout << "Result: ";
    cout << result_sign;
    if(firstZero){
        for(int i = 1; i < (result.size()-decimalPosition); i++){
            cout << result[i];
        }
        cout << ".";
        for(int i = (result.size() - decimalPosition); i < result.size() ; i++){
            cout << result[i];
        }
    }
    else{
        for(int i = 0; i < (result.size()-decimalPosition); i++){
            cout << result[i];
        }
        cout << ".";
        for(int i = (result.size() - decimalPosition); i < result.size() ; i++){
            cout << result[i];
        }
    }

}
//-----------------------------------------------------------------------------------
/*void BigReal::Subtraction(const string& number) {
    // Extract sign, integer part, and fraction part from the input string
    if (number[0] == '-') {
        positive = false;
        integer = number.substr(1);      //Start  from the index 1 to the end of the string
    } else {
        positive = true;
        integer = number;
    }

    size_t decimalPos = integer.find('.');
    if (decimalPos != string::npos) {     //decimalPos is not equal to the greatest value of size_t
        fraction = integer.substr(decimalPos + 1);
        integer = integer.substr(0, decimalPos);
    } else {
        fraction = "";
    }
}
*/
string  BigReal:: subtract(const  BigReal& other) const{

    /*if (other[0] == '-') {
        positive = false;
    }else{
        positive = true;
    }*/
    int positive=0;
    if(sign=='+')
        positive = 0;
    else
        positive = 1;

    // Pad the fraction parts with zeros to ensure equal length
    string paddedFrac1 = fraction;
    string paddedFrac2 = other.fraction;
    while (paddedFrac1.length() < paddedFrac2.length())
        paddedFrac1 += '0';
    while (paddedFrac2.length() < paddedFrac1.length())
        paddedFrac2 += '0';

    // Compute the 9's complement of the fraction part of the second number
    string complementedFrac2;
    for (char c : paddedFrac2)
        complementedFrac2 += '9' - (c - '0');

    // Add 1 to the 9's complement of the fraction part to get the final complement
    string finalComplement = addOne(complementedFrac2);

    // Subtract the fraction parts using the complement method
    string fractionResult = add(paddedFrac1, finalComplement);
    size_t nonZeroPos = fractionResult.find_first_not_of('0');
    if (nonZeroPos != string::npos)
        fractionResult = fractionResult.substr(nonZeroPos);
    else
        fractionResult = "";


    if (!fractionResult.empty()&&fractionResult[0]=='1')
        fractionResult = fractionResult.substr( 1);

    // Subtract the integer parts
    string integerResult = subtractNum(integer, other.integer);

    // Remove leading zeros from the integer result
    size_t nonZeroPos2 = integerResult.find_first_not_of('0');
    if (nonZeroPos2 != string::npos)
        integerResult = integerResult.substr(nonZeroPos2);
    else
        integerResult = "0";



    // Combine the integer and fraction parts to get the final result
    string result = integerResult;
    if (!fractionResult.empty())
        result += '.' + fractionResult;

    // Add the sign if necessary
    if (positive=0)
        result = '-' + result;

    return result;
}


string  BigReal:: add(const string& num1, const string& num2) const {
    string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;    //if was no carry it will be a decimal num so carry =0
        sum %= 10;
        result = to_string(sum) + result;
        i--;
        j--;
    }

    return result;
}

string BigReal::subtractNum(const string& num1, const string& num2) const {
    string result;
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = to_string(diff) + result;
        i--;
        j--;
    }

    return result;
}

string BigReal::addOne(const string& num) const {
    string result = num;                   // 20 -13 --->   20 + 86(9's complement)= 106 ---> add 1 and remove the last one
    int i = num.length() - 1;              //=07
    int carry = 1;
    while (i >= 0 && carry > 0) {
        int digit = num[i] - '0';
        int sum = digit + carry;
        carry = sum / 10;
        sum %= 10;
        result[i] = sum + '0';
        i--;
    }

    if (carry > 0)             //if still was a carry
        result = '1' + result;

    return result;
}



void BigReal::printf() {
    cout << BigNumber << "-->";
    cout << integer << " " << fraction << " ";
    cout << "\n";
}
