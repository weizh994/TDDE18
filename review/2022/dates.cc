#include <vector>
#include <iostream>

/*

Expected output:

1970-01-01
Thursday 1/1/1970
2000-12-24
Christmas Eve 12/24/2000
2020-02-19
Thursday 2/19/2020

*/

class Date
{
protected:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d) : year{y}, month{m}, day{d} {}
    virtual ~Date() = default;
    virtual std::string to_string() = 0; // should i use const, and how?
};

class YMD_Date : public Date
{
public:
    YMD_Date(int y, int m, int d) : Date{y, m, d} {}
    ~YMD_Date() override {}
    std::string to_string() override
    {
        std::string m{std::to_string(month)};
        std::string d{std::to_string(day)};
        if (m.length() < 2)
            m = "0" + m;
        if (d.length() < 2)
            d = "0" + d;
        return std::to_string(year) + "-" + m + "-" + d;
    }
};

class MDY_Date : public Date

{
private:
    std::string week;

public:
    MDY_Date(std::string dd,int y, int m, int d) : Date{y, m, d},week{dd} {}
    ~MDY_Date() override {}
    std::string to_string() override
    {
        return week+" "+std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }
};

int main()
{
    std::vector<Date *> dates = {
        new YMD_Date{1970, 1, 1},
        new MDY_Date{"Thursday", 1970, 1, 1},
        new YMD_Date{2020, 2, 19},
        new MDY_Date{"Thursday", 2020, 2, 19}};

    for (auto date : dates)
    {
        std::cout << date->to_string() << std::endl;
    }
    for (auto date : dates)
    {
        delete date;
    }
}
