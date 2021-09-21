cmake_minimum_required(VERSION 3.0.2)
project(algorithms)

find_package(catkin REQUIRED)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES algorithms
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
# target_link_libraries(<your exe or lib> ${PYTHON_LIBRARIES})

include_directories(
    include
    # /usr/incldue/python3.8/
# ${catkin_INCLUDE_DIRS}
)

add_executable(genetic_algorithm genetic_algorithm/genetic_algorithm.cpp) 
target_link_libraries(genetic_algorithm )
add_executable(GA_TSP genetic_algorithm/GA_TSP.cpp) 
target_link_libraries(GA_TSP ${PYTHON_LIBRARIES})