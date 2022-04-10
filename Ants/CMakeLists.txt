cmake_minimum_required(VERSION 3.23)
project(Ants)

INCLUDE(FindPkgConfig)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH /opt/homebrew/Cellar/sdl2_ttf)


find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_GFX REQUIRED SDL2_gfx)


add_executable(Ants src/Environment.cpp
        src/Environment.h
        src/main.cpp
        src/MathUtils.h
        src/Rectangle.h
        src/Renderer.cpp
        src/Renderer.h
        src/Timer.cpp
        src/Timer.h
        src/Vector2.h src/Agent.cpp src/Agent.h src/Food.cpp src/Food.h src/Anthill.cpp src/Anthill.h src/AntBase.cpp src/AntBase.h src/SillyAnt.cpp src/SillyAnt.h src/Pheromone.cpp src/Pheromone.h src/AntBasePheromone.cpp src/AntBasePheromone.h src/Ant.cpp src/Ant.h src/AbstractRule.h src/OrRule.cpp src/OrRule.h src/AbstractAntRule.cpp src/AbstractAntRule.h src/AntWithRules.cpp src/AntWithRules.h)


include_directories(${SDL2_INCLUDE_DIRS} /opt/homebrew/Cellar/sdl2_gfx/1.0.4/include/SDL2 /opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/include/SDL2)
target_link_libraries (Ants PRIVATE ${SDL2_LIBRARIES} -L/opt/homebrew/Cellar/sdl2_gfx/1.0.4/lib ${SDL2_GFX_LIBRARIES} -L/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/lib ${SDL2_TTF_LIBRARIES})