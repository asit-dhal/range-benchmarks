cmake_minimum_required(VERSION 2.8)

project(range-benchmarking)

#add_definitions(-DCMAKE_TOOLCHAIN_FILE=/home/asit/proj/devtools/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(benchmark CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67.0)
if(Boost_FOUND)
    message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(BENCHMARK_REPORT_DIRECTORY ${CMAKE_BINARY_DIR}/reports)

add_executable(fill fill.cpp)
target_link_libraries(fill
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)


add_executable(generate generate.cpp)
target_link_libraries(generate
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)

add_executable(iota iota.cpp)
target_link_libraries(iota
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)


#foreach(binaries ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#    add_custom_command()
#endforeach()
