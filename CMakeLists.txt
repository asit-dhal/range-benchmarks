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
    add_definitions(-DBoostDefined)
    message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(BENCHMARK_REPORT_DIRECTORY ${CMAKE_BINARY_DIR}/reports)

add_custom_target(create_report_dir
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BENCHMARK_REPORT_DIRECTORY}
    COMMENTS "Creating report directory"
)

add_executable(fill fill.cpp)
target_link_libraries(fill
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)
add_custom_command(TARGET fill
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fill "--benchmark_format=json" > ${BENCHMARK_REPORT_DIRECTORY}/fill.json
    COMMENT "Generating report for fill"
)
add_dependencies(fill create_report_dir)

add_executable(generate generate.cpp)
target_link_libraries(generate
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)
add_custom_command(TARGET generate
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/generate "--benchmark_format=json" > ${BENCHMARK_REPORT_DIRECTORY}/generate.json
    COMMENT "Generating report for generate"
)
add_dependencies(generate create_report_dir)

add_executable(iota iota.cpp)
target_link_libraries(iota
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)
add_custom_command(TARGET iota
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/iota "--benchmark_format=json" > ${BENCHMARK_REPORT_DIRECTORY}/iota.json
    COMMENT "Generating report for iota"
)
add_dependencies(iota create_report_dir)

add_executable(minmax minmax.cpp)
target_link_libraries(minmax
    PRIVATE benchmark::benchmark benchmark::benchmark_main
    PRIVATE meta range-v3)
add_custom_command(TARGET minmax
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/minmax "--benchmark_format=json" > ${BENCHMARK_REPORT_DIRECTORY}/minmax.json
    COMMENT "Generating report for minmax"
)
add_dependencies(minmax create_report_dir)

