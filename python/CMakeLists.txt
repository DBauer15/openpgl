find_package(pybind11 REQUIRED)

pybind11_add_module(openpglpy python.cpp)
target_link_libraries(openpglpy PRIVATE openpgl)
target_include_directories(openpgl PRIVATE openpgl)