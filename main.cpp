#include <list>
#include <iostream>
#include <cmath>

void backPropigate(std::list<double>::iterator it, std::list<double>& list, double bigram, double bias, double slope);

int main() {
    //list with 5 nodes
    std::list<double> list;
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    backPropigate(list.end(),list, 1,1,1);

    for(auto it:list){
        std::cout << it << " ";
    }

    std::cout << "\n";

    return 0;
};

void backPropigate(std::list<double>::iterator it, std::list<double>& list, double bigram, double bias, double slope) {
    if (it != list.begin() && it != list.end()) {
        *it = slope = *(std::next(it)) * std::pow(10,-bigram);
        backPropigate(std::prev(it), list, bigram, slope, slope);
    } else if (it == list.end()) {
        it = std::prev(it);
        *it = slope = std::pow(10,-bigram);
        backPropigate(std::prev(it), list, bigram, slope, slope);
    } else {
        *it = abs(std::tanh(bigram)-bias);
    }
}
