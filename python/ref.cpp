#include <sstream>
#include <iostream>
#include <pybind11/pybind11.h>

struct atom {
    int x;
    int y;

    std::string str() const {
        std::stringstream s;
        s << "atom(" << x << ", " << y << ")";
        return s.str();
    }

    atom() = default;
};

class context {
    atom atom_;

public:

    std::string str() const {
        return "context: " + atom_.str();
    }

    atom& get_atom(int) {
        return atom_;
    }
};

PYBIND11_MODULE(ref, m) {
    pybind11::class_<atom> atom(m, "atom");
    atom
        .def(pybind11::init<>())
        .def_readwrite("x", &atom::x)
        .def_readwrite("y", &atom::y)
        .def("__str__", &atom::str);

    pybind11::class_<context> context(m, "context");
    context
        .def(pybind11::init<>())
        .def("atom", &context::get_atom, pybind11::return_value_policy::reference)
        .def("__str__", &context::str);
}

