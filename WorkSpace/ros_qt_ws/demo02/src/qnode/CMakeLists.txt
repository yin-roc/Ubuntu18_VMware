cmake_minimum_required(VERSION 3.0.2)
project(qnode)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES
  src/main.cpp
  src/hello_node.cpp
  src/mainwindow.cpp
)
set(FORMS
  src/mainwindow.ui
)

set(LIBS
    Qt5::Widgets
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES qnode
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
    include/qnode
    ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node ${SOURCES} ${FORMS})

#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(
    ${PROJECT_NAME}_node
    ${catkin_LIBRARIES}
    ${LIBS}
)

