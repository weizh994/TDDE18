#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>

class Date
{
public:
    Date(int year, int month, int date)
        : year{year}, month{month}, date{date}
    { }

    virtual ~Date() = default;
    virtual std::string to_string() const = 0;
    
protected:

    int const year;
    int const month;
    int const date;
};

class YMD_Date : public Date
{
public:

    using Date::Date;

    std::string to_string() const override
    {
        std::ostringstream oss{};
        oss << std::setfill('0')
            << year  << '-' << std::setw(2)
            << month << '-' << std::setw(2)
            << date;
        return oss.str();
    }
};

class MDY_Date : public Date
{
public:

    MDY_Date(std::string const& day, int year, int month, int date)
        : Date{year, month, date}, day{day}
    { }

    std::string to_string() const override
    {
        std::ostringstream oss{};
        oss << day   << ' ' << month << '/'
            << date  << '/' << year;
        return oss.str();
    }

private:

    std::string const day{};
    
};

/*

Expected output:

1970-01-01
Thursday 1/1/1970
2000-12-24
Christmas Eve 12/24/2000
2020-02-19
Thursday 2/19/2020

*/
int main()
{
    std::vector<Date*> dates = {
        new YMD_Date{1970, 1, 1},
        new MDY_Date{"Thursday", 1970, 1, 1},
        new YMD_Date{2000, 12, 24},
        new MDY_Date{"Christmas Eve", 2000, 12, 24},
        new YMD_Date{2020, 2, 19},
        new MDY_Date{"Thursday", 2020, 2, 19}
    };

    for (Date* date : dates)
    {
        std::cout << date->to_string() << std::endl;
        delete date;
    }
}
