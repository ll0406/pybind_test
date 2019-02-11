#include <pybind11/pybind11.h>
#include "math.cpp"
#include "print.cpp"
#include "array.cpp"

void init_math(py::module &);
void init_print(py::module &);
int add(int i, int j) {
  return i + j;
}

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
    std::string name;
};

namespace py = pybind11;


PYBIND11_MODULE(first_bind, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("add", &add, "A function which adds two numbers");
  m.def("add2", &add, py::arg("i"), py::arg("j")); //kwarg arguments defined as i and j

  //defined as attributes of model
  // Exporting variables
  m.attr("the_answer") = 42;
  py::object world = py::cast("World");
  m.attr("what") = world;

  // Class
  py::class_<Pet>(m, "Pet")
      .def(py::init<const std::string &>())
      .def("setName", &Pet::setName)
      .def("getName", &Pet::getName);

  // Define in other file
  init_math(m);

  // Call functions from python files
  init_print(m);

  // Get values returned by Python

  // Connect to numpy
  init_array(m);
}
