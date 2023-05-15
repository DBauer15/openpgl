#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <memory>
#include <openpgl/openpgl.h>

namespace py = pybind11;

/// Shorthand notation for defining a data structure
#define PGL_PY_STRUCT(Name, ...) \
    py::class_<Name>(m, #Name, ##__VA_ARGS__)

/// Shorthand to make a class or struct wrap in shared_ptr instead of the default unique_ptr
#define PGL_PY_STRUCT_PTR(Name, PointsToName, ...) \
    py::class_<PointsToName, std::shared_ptr<PointsToName>>(m, #Name, ##__VA_ARGS__)

/// Shorthand notation for defining an enum
#define PGL_PY_ENUM(Name, ...) \
    py::enum_<Name>(m, #Name, ##__VA_ARGS__)

/// Shorthand notation for defining enum members
#define def_value(Class, Value, ...) \
    value(#Value, Class::Value, ##__VA_ARGS__)

/// Shorthand to make a struct/class initializer
#define def_init(...) \
    def(py::init< __VA_ARGS__ >())

/// Shorthand notation for defining most kinds of methods
#define def_class_method(Class, Function, ...) \
    def(#Function, &Class::Function, ##__VA_ARGS__)

/// Shorthand notation for defining class/struct fields
#define def_class_field(Class, Field, ...) \
    def_readwrite(#Field, &Class::Field, ##__VA_ARGS__)

#define def_method(Function, ...) \
    m.def(#Function, &Function, ##__VA_ARGS__)

#define def_lambda(Function, Lambda, ...) \
    m.def(#Function, Lambda, ##__VA_ARGS__)