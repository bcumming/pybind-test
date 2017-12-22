#include <pybind11/pybind11.h>

#include <sequence.hpp>
#include <print.hpp>

#include <cstdint>

class py_sequence: public sequence {
public:
    using sequence::sequence;

    // Trampoline (need one for each virtual function)
    void pop() override {
        PYBIND11_OVERLOAD_PURE(
            void,        // Return type
            sequence,    // Parent class
            pop          // Name of function in C++ (must match Python name)
        );
    }

    float front() const override {
        PYBIND11_OVERLOAD_PURE(
            float,       // Return type
            sequence,    // Parent class
            front        // Name of function in C++ (must match Python name)
        );
    }
};

PYBIND11_MODULE(sequence, m) {
    pybind11::class_<sequence, py_sequence> sequence(m, "sequence");
    sequence.def(pybind11::init<>())
            .def("pop",   &sequence::pop)
            .def("front", &sequence::front);

    pybind11::class_<regular_sequence>(m, "regular_sequence", sequence)
        .def(pybind11::init<float, float>());

    m.def("print", &print, "print all entries in a sequence up to a set limit");
    m.def("make_regular_sequence", &make_regular_sequence, "construct a regular sequence");
    m.def("popper", &popper, "pop a sequence n times");
}
