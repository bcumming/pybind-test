
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <memory>
#include <vector>

struct wupple {
    std::string widge;
    int wodge;
};

struct quat {
    int x;
    int y;
};

struct A {
    virtual int generate() = 0;
    virtual ~A() {};
};

struct C {
    virtual pybind11::object generate() = 0;

    virtual ~C() {}
};

struct D: public C {
    using C::C;

    pybind11::object generate() override {
        PYBIND11_OVERLOAD_PURE(pybind11::object, C, generate,);
    }
};

struct B: public A {
    using A::A;
    C* c;

    B(C* c): c(c) {}

    int generate() override {
        pybind11::object x = c->generate();
        std::cout << "----\n";
        std::cout << x.get_type() << std::endl;
        std::cout << pybind11::str(x.get_type()) << std::endl;
        std::cout << "it's a wupple, isn't it? " << pybind11::isinstance<wupple>(x) << std::endl;
        std::cout << "it's an int, isn't it? " << pybind11::isinstance<int>(x) << std::endl;
        std::cout << "it's an quat, or not? " << pybind11::isinstance<quat>(x) << std::endl;
        std::cout << "----\n";
        int result;
        try {
            return x.cast<int>();
        }
        catch (...) {
            std::cout << "error: can't convert" << std::endl;
            return -1;
        }
    };
};

int generate(A* a) {
    return a->generate();
}

std::unique_ptr<A> make(D* d) {
    return std::unique_ptr<A>(new B(d));
}

struct bar {
    int x;
    int y;
};

PYBIND11_MODULE(inheritance, m) {
    m.def("make", make);

    pybind11::class_<wupple> wupple(m, "wupple");
    wupple
        .def(pybind11::init<>())
        .def_readwrite("widge", &wupple::widge)
        .def_readwrite("wodge", &wupple::wodge);

    pybind11::class_<bar> bar(m, "bar");
    bar.def(pybind11::init<>())
       .def_readwrite("x", &bar::x)
       .def_readwrite("y", &bar::y);

    pybind11::class_<A, B> A(m, "A");
    A.def(pybind11::init<>())
     .def("generate", &A::generate);

    pybind11::class_<C, D> C(m, "C");
    C.def(pybind11::init<>())
     .def("generate", &C::generate);

    m.def("generate", &generate);
}

