#include <iostream>

#include <print.hpp>
#include <sequence.hpp>

void print(sequence* s, float lim) {
    std::cout << "==== printing sequence\n";
    while(s->front()<lim) {
        std::cout << "  pop: " << s->front() << "\n";
        s->pop();
    }
}

void print_first_n(sequence* s, unsigned n) {
    std::cout << "==== printing sequence\n";
    auto i = n;
    while(n--) {
        std::cout << "  pop: " << s->front() << "\n";
        s->pop();
    }
}
