cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

set (CMAKE_BINARY_DIR ../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

SET(COMMON_SOURCE_FILES
    playerinterface.h
    playerinterface.cpp
    playerinterface.h
    playerinterface.ui
    instructorwindow.cpp
    instructorwindow.h
    instructorwindow.ui
    instructor.h
    instructor.cpp
    player.h
    player.cpp
    playerevent.h
    game.h
    game.cpp
    order.h
    order.cpp
    shipment.h
    shipment.cpp
)

add_executable(beergame
    ${COMMON_SOURCE_FILES}
    main.cpp
    beergamewindow.cpp
    beergamewindow.h
    beergamewindow.ui
    ../resources/resources.qrc
)

add_executable(server
    ${COMMON_SOURCE_FILES}
    server/beergameservermain.cpp
    server/beergameserver.h
    server/beergameserver.cpp
    server/playerinterfaceserver.cpp
    server/beergameserverwindow.cpp
    server/beergameserverwindow.ui
    server/beergameserverwindow.h
    ../resources/resources.qrc
)

target_link_libraries(beergame PRIVATE Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)
target_link_libraries(server PRIVATE Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)
