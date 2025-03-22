cmake_minimum_required(VERSION 3.21)
project(game_2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        game_2048
        src/main.cpp
        src/game.cpp
        src/board.cpp
        src/render.cpp)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

target_link_libraries(game_2048 sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)