cmake_minimum_required(VERSION 3.5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# add_executable(tests tests.cpp)
add_executable(tests
    tests.cpp
    ../src/beergamewindow.cpp
    ../src/beergamewindow.h
    ../src/beergamewindow.ui
    ../src/playerwindow.cpp
    ../src/playerwindow.h
    ../src/playerwindow.ui
    ../src/instructorwindow.cpp
    ../src/instructorwindow.h
    ../src/instructorwindow.ui
    ../src/instructor.h
    ../src/instructor.cpp
    ../src/player.h
    ../src/player.cpp
    ../src/game.h
    ../src/game.cpp
    ../src/playerevent.h
    ../src/shipment.h
    ../src/shipment.cpp
    ../src/order.h
    ../src/order.cpp
)

target_link_libraries(tests PRIVATE Qt5::Widgets Qt5::Network ${GTEST_LIBRARIES} pthread)
