class BigReal {
private:
    string BigNumber,integer,fraction;
    long long intSize,fractionSize ;
    char sign;
    bool firstZero;
public:
    BigReal();
    BigReal(string real);

    BigReal& operator= (BigReal& other);
    BigReal(const BigReal &other);

    bool operator==(BigReal oo2);
    bool operator<(BigReal oo2 );
    bool operator>(BigReal oo2 );

    void add(BigReal& other);
    string subtract(BigReal& other);

     int Size();
    friend void print_num(BigReal p);

};


