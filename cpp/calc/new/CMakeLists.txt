cmake_minimum_required(VERSION 3.20...3.31)

#export CC=clang
#export CXX=clang++

project(Calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(calc
	src/main.cpp
	src/calculate.cpp
	src/additional_math.cpp
)

target_include_directories(calc PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
