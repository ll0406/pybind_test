#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_math(py::module &m) {
    m.def("sub", [](int a, int b) { return a - b; });
}
