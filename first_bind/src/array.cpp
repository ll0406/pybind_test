#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <vector>
namespace py = pybind11;

void get_buf_info(py::array_t<double> input1) {
  py::buffer_info buf1 = input1.request();
  py::print("Buffer ndim");
  py::print(buf1.ndim);
  py::print("Buffer size");
  py::print(buf1.size);
  py::print("Buffer shape");
  py::print(buf1.shape[0]);
  py::print(buf1.shape[1]);
}

py::array_t<double> cast_vector_to_np_array(std::vector<double> &v) {
  auto result = py::array_t<double>(v.size());
  py::buffer_info buf = result.request();

  double *ptr1 = (double *) buf.ptr;
  for (size_t idx = 0; idx < v.size(); idx++)
    ptr1[idx] = v[idx];

  return result;
}

std::vector<double> get_naive_thresh_result() {
  // Init vector or array
  std::vector<double> frame = {10,15,20, 50,100,150, 255, 254, 253};
  py::array_t<double> np_frame = cast_vector_to_np_array(frame);

  // Call naive thresh
  py::object py_src = py::module::import("py_src");
  py::object naive_thresh = py_src.attr("naive_thresh");
  py::array_t<double> np_thresh = naive_thresh(np_frame);

  // Store to vector
  auto r = np_thresh.unchecked<1>(); // Enable direct access to array
  std::vector<double> thresh;
  for (size_t i = 0; i < r.shape(0); i++)
    thresh.push_back(r[i]);

  return thresh;
}


void init_array(py::module &m) {
  m.def("simple_array", []() {
      py::array_t<double> a;
      return a;
  });
  //m.def("simple_init_arr", &init_arr, "Init np array with simple c++ array");
  m.def("simple_init_arr", []() {
    std::vector<double> frame = { 1, 1, 1 };
    return cast_vector_to_np_array(frame);
  });

  m.def("simple_thresh", []() {
    std::vector<double> thresh = get_naive_thresh_result();
    // <pybind11/stl.h> enables auto conversion of vector to list
    return thresh;
  });

  //Utility to print buff info for a numpy array
  m.def("buff_info", &get_buf_info, "Utility function to get buff info");

  //Try call python functin with numpy args
  m.def("try_naive", &get_naive_thresh_result, "Try call python func with np arg");
}
