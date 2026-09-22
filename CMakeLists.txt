cmake_minimum_required(VERSION 3.10)

project(MyApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX-STANDARD 17)
set(CMAKE_CXX-STANDARD_REQUIRED ON)

add_executable(MyApp
	src/main.cpp
)


target_include_directories(MyApp PUBLIC ${PROJECT_SOURCE_DIR}/include)


