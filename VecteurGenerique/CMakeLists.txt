cmake_minimum_required(VERSION 3.21)
project(VecteurGenerique)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(VecteurGenerique main.cpp vecteur.h)
add_executable(VecteurGeneriqueTest vecteur.h test_common.hh test_vecteur.cc)
target_link_libraries(VecteurGeneriqueTest gtest_main)