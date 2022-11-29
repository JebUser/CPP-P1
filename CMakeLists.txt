cmake_minimum_required(VERSION 3.19)
project(ProyectoReclutamiento)

include_directories(lib)
include_directories(src)
include_directories(test)

add_subdirectory(lib/googleTest)
add_subdirectory(src)
add_subdirectory(test)

#Esta linea debe ir de ultima para que quede claro cual es la version del c++ y  no se reemplace en pasos anteriores
set(CMAKE_CXX_STANDARD 14)