class BigReal{
private:
    string BigNumber,integer,fraction;
    long long intSize,fractionSize ;
    char sign;
    bool firstZero;
    bool positive;
public:

    BigReal();
    BigReal(string real);
    friend void print_num(BigReal p);
    bool operator==(BigReal oo2);


    int operator<(BigReal oo2 );


    void add(BigReal& other);


    void Subtraction(const string& number) ;
    string subtract(const BigReal& other)const;
    string add(const string& num1, const string& num2)const ;
    string subtractNum(const string& num1, const string& num2) const;
    string addOne(const string& num) const ;

    void printf();
};
