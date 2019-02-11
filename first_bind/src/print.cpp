#include <pybind11/pybind11.h>
namespace py = pybind11;

void py_print() {
  py::object py_src = py::module::import("py_src");
  py::object simple_p = py_src.attr("simple_print");
  simple_p();
}

void init_print(py::module &m) {
    m.def("py_print", &py_print, "A simple print from python");
}
