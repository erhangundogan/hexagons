cmake_minimum_required(VERSION 3.1)

project(hexagons)

include_directories(.)

set(HEXAGONS_SOURCE_DIR "src")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(hexagons ${HEXAGONS_SOURCE_DIR}/hexagons.cpp)

target_link_libraries(hexagons PRIVATE ${OpenCV_LIBS})
