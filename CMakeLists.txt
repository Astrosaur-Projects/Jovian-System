cmake_minimum_required(VERSION 3.27)

project("Jovian-System"
	VERSION 0.0.1
	DESCRIPTION "A C++ CLI tool for calculating the positions of Jupiter's moons"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(CLI11 CONFIG REQUIRED)

add_subdirectory(src)