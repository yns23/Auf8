//
// Created by Yunus A. on 14.12.21.
//

#include "Date.h"

#include "date.h"
#include <regex>
#include "Date.h"


hfu::Date::Date() {}
hfu::Date::Date(int theYear, int theMonth, int theDay) :  theYear(checkDate(theYear,theMonth,theDay)),
                                                          theMonth(theMonth), theDay(theDay) {}

bool hfu::Date::checkLeap(int y) {
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;

}



int hfu::Date::checkDate(int year, int month, int day) {
    if (month == 2 && day == 29)
        if (!checkLeap(year))
            throw std::invalid_argument("No Leap Year");
    std::string regYear = "([1,2][0-9]{3})";
    std::string regMonthDay = "((([13578]|10|12)([0-9]|[12][0-9]|3[01]))|(([469]|11)([0-9]|[12][0-9]|30))|(2([0-9]|[12][0-9])))";
    std::string date;
    date = std::to_string(year) + std::to_string(month) + std::to_string(day);

    if (regex_match(date, std::regex(regYear + regMonthDay)))
        return year;

    else
        throw std::invalid_argument("No Date");

}

bool hfu::Date::checkYear(int y) {

    std::string regYear = "([1,2][0-9]{3})";

    if (regex_match(std::to_string(y), std::regex(regYear)))
        return true;

    else
        throw std::invalid_argument("false year type");

}

int hfu::Date::getDay() const {
    return theDay;
}

int hfu::Date::getMonth() const {
    return theMonth;
}

int hfu::Date::getYear() const {
    return theYear;
}