#
# /src/CMakeLists.txt --
#

cmake_minimum_required(VERSION 3.1.0)

include_directories(${PROJECT_BINARY_DIR}/src)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Populate a CMake variable with the sources
set(BeerGame_SRCS
    mainwindow.ui
    instructor_ui.ui
    player_ui.ui
    instructor_ui.cpp
    player_ui.cpp
    mainwindow.cpp
    main.cpp
    game.cpp
    player.cpp
    instructor.cpp
    order.cpp
    factory.cpp
)

# Tell CMake to create the helloworld executable
add_executable(beergame ${BeerGame_SRCS})

# Use the Widgets module from Qt 5
target_link_libraries(beergame Qt5::Widgets)