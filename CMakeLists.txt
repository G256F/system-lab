cmake_minimum_required(VERSION 3.23)

project(MyApp VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyApp)
add_executable(day_260923 src/day_260923.cpp)
add_executable(day_260924_1 src/day_260924_1.cpp)
add_executable(day_260924_2 src/day_260924_2.cpp)
add_executable(day_260924_3 src/day_260924_3.cpp)
add_executable(day_260925 src/day_260925.cpp)
add_executable(day_260928_1 src/day_260928_1.cpp)
add_executable(day_260928_2 src/day_260928_2.cpp)
add_executable(day_260928_3 src/day_260928_3.cpp)
add_executable(day_260928_4 src/day_260928_4.cpp)
add_executable(day_260929 src/day_260929.cpp)
add_executable(day_260930 src/day_260930.cpp)


target_sources(MyApp 
	PRIVATE
           src/main.cpp
)


target_include_directories(MyApp PUBLIC ${PROJECT_SOURCE_DIR}/include)


