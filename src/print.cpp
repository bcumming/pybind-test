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
