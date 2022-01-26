cmake_minimum_required(VERSION 3.21)
project(Vecteur)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(Vecteur main.cpp vecteur.cpp vecteur.h memory.cxx)
add_executable(Vecteur_test vecteur.cpp vecteur.h tests/test_main.cc tests/test_common.h tests/test_common.cc tests/test_vecteur_p1.cc tests/test_vecteur_p2.cc)
target_link_libraries(Vecteur_test gtest_main)
