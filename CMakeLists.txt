cmake_minimum_required(VERSION 3.0)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(SnakeGame main.cpp Output/ConsoleOutput.cpp Output/ConsoleOutput.h SnakeGame.cpp SnakeGame.h Utilities/SingleDimensionArraysUtils.cpp Utilities/SingleDimensionArraysUtils.h Utilities/Vector2.h Utilities/Vector2.cpp Input/UserInput.cpp Input/UserInput.h Input/IInputActions.h Input/ReversedSnakeGameInputActions.cpp Input/ReversedSnakeGameInputActions.h)
