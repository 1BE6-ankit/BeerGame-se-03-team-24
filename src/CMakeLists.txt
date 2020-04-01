cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

set (CMAKE_BINARY_DIR ../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

SET(COMMON_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/playerinterface.h
    ${CMAKE_SOURCE_DIR}/src/playerinterface.cpp
    ${CMAKE_SOURCE_DIR}/src/playerinterface.h
    ${CMAKE_SOURCE_DIR}/src/playerinterface.ui
    ${CMAKE_SOURCE_DIR}/src/instructorwindow.cpp
    ${CMAKE_SOURCE_DIR}/src/instructorwindow.h
    ${CMAKE_SOURCE_DIR}/src/instructorwindow.ui
    ${CMAKE_SOURCE_DIR}/src/instructor.h
    ${CMAKE_SOURCE_DIR}/src/instructor.cpp
    ${CMAKE_SOURCE_DIR}/src/player.h
    ${CMAKE_SOURCE_DIR}/src/player.cpp
    ${CMAKE_SOURCE_DIR}/src/playerevent.h
    ${CMAKE_SOURCE_DIR}/src/game.h
    ${CMAKE_SOURCE_DIR}/src/game.cpp
    ${CMAKE_SOURCE_DIR}/src/order.h
    ${CMAKE_SOURCE_DIR}/src/order.cpp
    ${CMAKE_SOURCE_DIR}/src/shipment.h
    ${CMAKE_SOURCE_DIR}/src/shipment.cpp
)

add_executable(beergame
    ${COMMON_SOURCE_FILES}
    main.cpp
    beergamewindow.cpp
    beergamewindow.h
    beergamewindow.ui
    ../resources/resources.qrc
)

target_link_libraries(beergame PRIVATE Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)

add_subdirectory(client)
add_subdirectory(server)


