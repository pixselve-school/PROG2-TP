cmake_minimum_required(VERSION 3.16)
project(mixage)

set(CMAKE_CXX_STANDARD 14)

add_executable(mixage src/main.cpp src/imp_flot.h src/signal_constant.h src/producteur_base.h src/harmonique.h src/consommateur_base.h src/filtre/filtre_base.h src/filtre/multiplicateur.h src/filtre/operation_binaire.h src/filtre/volume.h src/filtre/filtre_compose.h src/filtre/mixeur.h src/filtre/adder.h src/utils/lecteur_fichier.h src/filtre/volume_compose.h src/filtre/fade_in.h src/filtre/fade.h src/filtre/fade_out.h src/filtre/compression.h src/filtre/echo.h src/filtre/duplicate.h src/filtre/delay.h)
target_include_directories(mixage PUBLIC ext/include)
target_link_libraries(mixage "${CMAKE_CURRENT_SOURCE_DIR}/ext/lib/liboutils.a")