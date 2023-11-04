class BigReal{
private:
    string BigNumber,integer,fraction;
    long long intSize,fractionSize ;
    char sign;
    bool firstZero;
public:

    BigReal();
    BigReal(string real);

    bool operator==(BigReal oo2);


    int operator<(BigReal oo2 );

    void printf();
    void add(BigReal& other);


};
class  Subtraction {
private:
    string integerPart;
    string fractionPart;
    bool positive;

public:
    Subtraction(const string& number) ;
    string subtract(const  Subtraction& other)const;
    string add(const string& num1, const string& num2)const ;
    string subtractNum(const string& num1, const string& num2) const;
    string addOne(const string& num) const ;
};
