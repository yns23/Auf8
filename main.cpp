#include <iostream>
#include <vector>
#include "Date.h"
#include "ArrayList.h"

    void test_date_list(){
        hfu::Date d1(2021,12, 31);
        hfu::Date d2(2021,12,24);
        hfu::Date d3(2021,12,25);
        std::vector<hfu::Date> dates{d1,d2,d3};
        hfu::ArrayList<hfu::Date> list(dates, 3);
        assert(list[2].getDay()==25);
        hfu::Date d4(2022,1,1);
        list.add(d4);
        assert(list[3].getDay()==1);
    }
    void test(){
        std::cout << "\nTest 2" << std::endl;

        std::vector<int> rounds = {1, 2, 3, 4};
        std::vector<int> rounds2 = {5,6,7,8,9};
        hfu::ArrayList<int> list(rounds,4);
        hfu::ArrayList<int> list2 = list;
        hfu::ArrayList<int> list3(rounds2,5);

        std::cout <<"\nlist = " << list<< std::endl;
        std::cout <<"\nlist2 = " << list2<< std::endl;


        std::cout <<"\nnew list2 = " << list2<< std::endl;
        assert(list2 == list);
        assert(list2 != list3);
        assert(list[2] < list2[3]);
        assert(list[2] <= list2[2]);
        assert(list3[4] > list2[1]);
        assert(list3.getSize()==5);
        list3.add(23);
        assert(list3.getSize()==6);
        assert(list3[5]==23);

}


int main() {

    std::cout << "Aufgabe 8: start" << std::endl;


    test_date_list();
    test();


    std::cout << "Aufgabe 8: end" << std::endl;


    return 0;

}
