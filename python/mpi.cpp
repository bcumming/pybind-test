#include <pybind11/pybind11.h>

#include <mpi.h>

void test_mpi_status() {
    int flag;
    auto status = MPI_Initialized(&flag);

    if (flag) std::cout << "MPI has been initialized" << std::endl;
    else      std::cout << "MPI has not been initialized" << std::endl;
}

PYBIND11_MODULE(mympi, m) {
    m.def("test_mpi_status", &test_mpi_status, "Prints a message about MPI has been initialized.");
}

