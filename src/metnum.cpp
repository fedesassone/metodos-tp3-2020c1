#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/eigen.h>
#include "linear_regression.h"

namespace py=pybind11;

// el primer argumento es el nombre...
PYBIND11_MODULE(metnum, m) {
      py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<int>())
        .def("fit", &LinearRegression::fit)
        .def("predict", &LinearRegression::predict);

  /*  py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<int>())
        .def("fit", [](LinearRegression self, Matrix X, Matrix Y){
            py::scoped_ostream_redirect stream(std::cout, py::module::import("sys").attr("stdout"));
            return self.fit(X, Y);
        }).def("predict", [](LinearRegression self, Matrix X) {
            py::scoped_ostream_redirect stream(std::cout, py::module::import("sys").attr("stdout"));
            return self.predict(X);
        });*/
}
