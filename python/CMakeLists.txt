pybind11_add_module(group group.cpp)
pybind11_add_module(inheritance inheritance.cpp)
pybind11_add_module(ref ref.cpp)

pybind11_add_module(sequence sequence.cpp)
target_link_libraries(sequence LINK_PUBLIC example)

pybind11_add_module(mympi mpi.cpp)
target_link_libraries(mympi LINK_PUBLIC MPI::MPI_CXX)
