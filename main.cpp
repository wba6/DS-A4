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

    for(double i = 0.0; i <= 1; i+=0.1){

        backPropigate(list.end(),list, i,0.5,0.01);

        std::cout << i << " :  ";
        for(auto it:list){
        std::cout << it << " ";
        }
        std::cout << "\n\n";
    }


    std::cout << "\n";

    return 0;
};

void backPropigate(std::list<double>::iterator it, std::list<double>& list, double bigram, double bias, double slope) {
    if (it != list.begin() && it != list.end()) {
        *it = *(std::next(it)) * slope;
        backPropigate(std::prev(it), list, bigram, slope, slope*10);
    } else if (it == list.end()) {
        it = std::prev(it);
        *it = std::abs(std::tanh(bigram)-bias);
        backPropigate(std::prev(it), list, bigram, slope, slope*10);
    } else {
        *it = *(std::next(it)) * slope;
    }
}
