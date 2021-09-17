#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "walrus/carpenter/include/hello.h"

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

template <typename T>
void zero_first(Eigen::Ref<T> arr) {
    // All eigen matrices are column-major
    // if we specified <const T>, we can still pass in numpy arrays (row-major)
    // but in the general case, T needs to be a row-major eigen array, for example:
    // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>
    arr(0, 0) = 0;
}

typedef Eigen::Array<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> MatrixD;


PYBIND11_MODULE(ext, m) {
    m.attr("__name__") = "walrus.ext";
    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("zero_first", &zero_first<MatrixD>);

    py::class_<Hello>(m, "Hello")
    .def(py::init<>())
    .def("greet", &Hello::greet);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
