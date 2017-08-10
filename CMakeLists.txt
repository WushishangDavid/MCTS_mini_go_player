cmake_minimum_required(VERSION 3.5)
project(go)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Player.cpp HumanPlayer.cpp AIPlayer.cpp
        Game.cpp Node.cpp LP_AIPlayer.cpp RP_AIPlayer.cpp SingleGame.cpp)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

#set(CMAKE_CXX_COMPILER /usr/local/Cellar/gcc/5.3.0/bin/g++-5)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(go ${SOURCE_FILES})