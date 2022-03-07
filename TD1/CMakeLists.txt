cmake_minimum_required(VERSION 3.21)
project(TD1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TD1 clientpile.cc pile.hh pile.cc pile_avoid_copies.hh Chainon.h pile_chainon.hh)