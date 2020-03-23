#include "castar.hpp"
#include "field.hpp"

#ifndef TEST
#include "pybind11/pybind11.h"
#include "pybind11/stl_bind.h"
#include "pybind11/stl.h"
namespace py = pybind11;
#else
#include "test.hpp"
#endif

using namespace std;


// BINDINGS

#ifndef TEST

PYBIND11_MODULE(castar, m) {
    py::class_<Coordinates>(m, "Coordinates")
    .def_readwrite("x", &Coordinates::x)
    .def_readwrite("y", &Coordinates::y)
    .def(py::init<const int, const int>(), py::arg("x"), py::arg("y"))
    .def("__repr__",
        [](const Coordinates &crd) {
            return "x:" + to_string(crd.x) + "|y:" + to_string(crd.y);
        }
    );
    py::class_<Size>(m, "Size")
    .def_readwrite("width", &Size::width)
    .def_readwrite("height", &Size::height)
    .def(py::init<const int, const int>(), py::arg("width"), py::arg("height"))
    .def("__repr__",
        [](const Size &i) {
            return "Width:" + to_string(i.width) + "|Height:" + to_string(i.height);
        }
    );
    py::class_<Rectangle>(m, "Rectangle")
    .def_readwrite("pos", &Rectangle::pos)
    .def_readwrite("dim", &Rectangle::dim)
    .def(py::init<const Coordinates, const Size>(), py::arg("Coordinates"), py::arg("Size"))
    .def("__repr__",
        [](const Rectangle &rec) {
            return "Pos:" + to_string(rec.pos.x) + "|" + to_string(rec.pos.y) + 
            " - Size:" + to_string(rec.dim.width) + "|" + to_string(rec.dim.height);
        }
    );
    py::class_<Field>(m, "Field", "Class representing the field where pathfinding will be computed\n Used to store obstacles")
    .def(py::init<>())
    .def(py::init<const unsigned int>(), py::arg("robot_diameter_mm"))
    .def(py::init<const unsigned int, const unsigned int, const unsigned int>(), py::arg("width_mm"), py::arg("height_mm"), py::arg("robot_diameter_mm"))
    .def("add_obstacle", &Field::add_obsctacle, py::arg("Rectangle"),"Add an obstacle to the field")
    .def("delete_obstacle", &Field::delete_obstacle, py::arg("Coordinates"), "Delete the first obstacle added at the given position")
    .def("get_list_of_obstacle", &Field::get_list_of_obstacle, "Return the list of obstacle")
    .def("__repr__",
        [](Field &fd) {
            return  "Size:" + to_string(fd.get_dimensions().width) + "|" + to_string(fd.get_dimensions().height)
            + " - Nb obstacle: " + to_string(fd.get_number_of_obstacle());
        }
    );

    py::class_<Castar>(m, "Castar", "Class where the A* algorithme and extra tools are implemented")
    .def(py::init<>())
    .def("find_path", [](Castar &cas, Coordinates start, Coordinates end, Field field) {
        std::vector<Coordinates> final_path;
        int return_code = cas.find_path(start,end,field,&final_path); 
        return std::make_tuple(return_code, final_path); 
        }, py::arg("start_coordinates"), py::arg("end_coordinates"), py::arg("field"), "Find the shortest path between two points given a field"
    )
    .def("simplify_path", [](Castar &cas, std::vector<Coordinates> path) {
        std::vector<Coordinates> final_path;
        int return_code = cas.simplify_path(path,&final_path); 
        return std::make_tuple(return_code, final_path); 
        } , py::arg("path"), "Return only the points where there is a change in direction"
    )
    .def("find_path_simplified", [](Castar &cas, Coordinates start, Coordinates end, Field field) {
        std::vector<Coordinates> final_path;
        int return_code = cas.find_path_simplified(start,end,field,&final_path); 
        return std::make_tuple(return_code, final_path); 
        }, py::arg("start_coordinates"), py::arg("end_coordinates"), py::arg("field"), "Combinaison of find_path and simplify_path"
    );


    m.doc() = "Library implementing the A* pathfinding algorithme"; // optional module docstring
}
#else

int main(int argc, char const *argv[])
{
    test();
    return 0;
}

#endif


