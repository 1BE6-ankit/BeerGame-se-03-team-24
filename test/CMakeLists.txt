# Making sure that the version of cmake we are using is correct
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Including the main build directory
include_directories(${CMAKE_SOURCE_DIR/src})

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find the QtTest library
find_package(Qt5 COMPONENTS Widgets Network CONFIG REQUIRED)

# Populate two CMake variables with the sources
set(test_SRCS
    test.cpp)

set(project_SRCS 
    ../src/factory.cpp
    ../src/game.cpp
    ../src/instructor.cpp
    ../src/order.cpp
    ../src/player.cpp
    ../src/mainwindow.ui)

add_executable(beergame-tests ${test_SRCS} ${project_SRCS})

#set_target_properties(beergame-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_link_libraries(beergame-tests Qt5::Widgets Qt5::Network ${GTEST_LIBRARIES} pthread)