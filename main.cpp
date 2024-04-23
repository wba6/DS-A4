#include <list>
#include <iostream>

void backPropigate(std::list<double>::iterator it, std::list<double>& list);

int main() {
    //list with 5 nodes
    std::list<double> list;
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    list.emplace_front();
    backPropigate(list.end(),list);

    for(auto it:list){
        std::cout << it << " ";
    }

    std::cout << "\n";

    return 0;
};

void backPropigate(std::list<double>::iterator it, std::list<double>& list) {
    if (it != list.begin() && it != list.end()) {
        *it = *(std::next(it)) * 0.5;
        backPropigate(std::prev(it), list);
    } else if (it == list.end()) {
        it = std::prev(it);
        *it = 0.5;
        backPropigate(std::prev(it), list);
    } else {
        *it = *(std::next(it)) * 0.5;
    }
}
