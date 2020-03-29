cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

add_executable(beer-game
    main.cpp
    beergameserver.h
    gameserver.cpp
    playerinterfaceserver.cpp
    playerinterface.h
    playerinterface.cpp
    playerinterface.h
    playerinterface.ui
    beergamewindow.cpp
    beergamewindow.h
    beergamewindow.ui
    instructorwindow.cpp
    instructorwindow.h
    instructorwindow.ui
    instructor.h
    instructor.cpp
    player.h
    player.cpp
    game.h
    game.cpp
    playerevent.h
    shipment.h
    shipment.cpp
    order.h
    order.cpp
    ../resources/resources.qrc
)

target_link_libraries(beer-game PRIVATE Qt5::Widgets Qt5::Network)
