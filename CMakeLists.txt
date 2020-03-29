cmake_minimum_required(VERSION 3.5)

project(beer-game LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network Gui Core REQUIRED)

add_subdirectory(src)
#add_subdirectory(test)
#add_subdirectory(docs)

enable_testing()
add_test(NAME misc COMMAND tests)
