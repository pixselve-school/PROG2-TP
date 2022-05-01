cmake_minimum_required(VERSION 3.23)
project(Ants)

INCLUDE(FindPkgConfig)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH /opt/homebrew/Cellar/sdl2_ttf)


find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_GFX REQUIRED SDL2_gfx)


add_executable(Ants src/ant-environment/Environment.cpp
        src/ant-environment/Environment.h
        src/main.cpp
        src/utils/MathUtils.h
        src/utils/Rectangle.h
        src/utils/Renderer.cpp
        src/utils/Renderer.h
        src/utils/Timer.cpp
        src/utils/Timer.h
        src/utils/Vector2.h src/ants/Agent.cpp src/ants/Agent.h src/ant-environment/Food.cpp src/ant-environment/Food.h src/ants/Anthill.cpp src/ants/Anthill.h src/ants/AntBase.cpp src/ants/AntBase.h src/ants/SillyAnt.cpp src/ants/SillyAnt.h src/ant-environment/Pheromone.cpp src/ant-environment/Pheromone.h src/ants/AntBasePheromone.cpp src/ants/AntBasePheromone.h src/ants/Ant.cpp src/ants/Ant.h src/ants/AbstractRule.h src/rules/OrRule.cpp src/rules/OrRule.h src/rules/AbstractAntRule.cpp src/rules/AbstractAntRule.h src/ants/AntWithRules.cpp src/ants/AntWithRules.h)


include_directories(${SDL2_INCLUDE_DIRS} /opt/homebrew/Cellar/sdl2_gfx/1.0.4/include/SDL2 /opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/include/SDL2)
target_link_libraries (Ants PRIVATE ${SDL2_LIBRARIES} -L/opt/homebrew/Cellar/sdl2_gfx/1.0.4/lib ${SDL2_GFX_LIBRARIES} -L/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/lib ${SDL2_TTF_LIBRARIES})