cmake_minimum_required(VERSION 3.16)
project(mixage)

set(CMAKE_CXX_STANDARD 14)

add_executable(mixage src/main.cpp src/imp_flot.h src/signal_constant.h src/producteur_base.h src/harmonique.h src/consommateur_base.h src/filtre/filtre_base.h src/filtre/multiplicateur.h src/filtre/operation_binaire.h src/filtre/volume.h src/filtre/filtre_compose.h)
target_include_directories(mixage PUBLIC ext/include)
target_link_libraries(mixage "${CMAKE_CURRENT_SOURCE_DIR}/ext/lib/liboutils.a")