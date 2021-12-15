//
// Created by Yunus A. on 14.12.21.
//

#ifndef AUF8_ARRAYLIST_H
#define AUF8_ARRAYLIST_H

#include <ostream>
#include <cstring>
#include <cstdio>
#include <iostream>


namespace hfu{
    template<typename T = int > class ArrayList {
    private:
        std::vector<T> rounds;
        int size{};

        std::vector<T> checkRounds( std::vector<T> rounds) {
            if (rounds.empty())
                throw std::invalid_argument("Array is empty!");
            return copyRounds(rounds);
        }

        std::vector<T> copyRounds(std::vector<T> rounds){
            std::vector<T> copy;
            std::copy(rounds.begin(),rounds.end(),std::back_inserter(copy));
            return copy;
        }


        int checkSize(int size) {
            if(size >= 0)
                return size;
            else
                throw std::invalid_argument("Array size is incorrect");
        }

    public:
        ArrayList():ArrayList(nullptr,0) {}

        ArrayList( std::vector<T> rounds, int size) : rounds(checkRounds(rounds)), size(checkSize(size)) {}

        ~ArrayList(){
            std::cout << "Destroyed rounds" << std::endl;
        }


        int getSize() const {
            return size;
        }

        void add(const T points) {
            rounds.push_back(points);

        }

        bool operator==(const ArrayList &other) const {
            if (this->getSize() == other.getSize()) {
                for (int i = 0; i < other.getSize(); i++) {
                    if (this->rounds[i] != other.rounds[i])
                        return false;
                }
                return true;
            }
            return false;
        }

        bool operator!=(const ArrayList &other) const {
            return !(other == *this);
        }

        friend std::ostream &operator<<(std::ostream& out, const ArrayList &other){
            out <<"size: " << other.getSize()  << " scores: ";
            for (int i = 0; i < other.getSize(); ++i) {
                out << " " << other.rounds[i];
            }
            return out;
        }

        T& operator[](int position) {
            return rounds.at(position);
        }

        ArrayList& operator=(const ArrayList &other){
            *this = copyRounds(other);
        }
    };
}



#endif //AUF8_ARRAYLIST_H
