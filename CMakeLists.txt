cmake_minimum_required(VERSION 3.10)
project(ParallelImageProcessing)

set(CMAKE_CXX_STANDARD 17)

# OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})



add_executable(ParallelImageProcessing main.cpp)
target_link_libraries(ParallelImageProcessing ${OpenCV_LIBS})
