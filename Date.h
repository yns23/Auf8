//
// Created by Yunus A. on 14.12.21.
//

#ifndef AUF8_DATE_H
#define AUF8_DATE_H

namespace hfu{
    class Date {
    private:
        int theYear, theMonth, theDay;

        static int checkDate(int year, int month, int day);
        static bool checkLeap(int y);
        static bool checkYear(int y);


    public:
        Date();
        Date(int theYear, int theMonth, int theDay);
        int getYear() const;
        int getMonth() const;
        int getDay() const;


    };
}



#endif //AUF8_DATE_H
