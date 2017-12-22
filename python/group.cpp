#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

#include <group_description.hpp>

PYBIND11_MODULE(group, m) {
    // tell python about the cell_kind enum type
    pybind11::enum_<cell_kind>(m, "cell_kind")
        .value("cable", cell_kind::cable)
        .value("lif",   cell_kind::lif);

    // tell python about cell_description
    pybind11::class_<group_description> group_description(m, "group_description");
    group_description.def(pybind11::init<cell_kind, std::vector<int>>())
                     .def_readonly("gids", &group_description::gids)
                     .def_readonly("kind", &group_description::kind);
}

