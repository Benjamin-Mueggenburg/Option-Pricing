cmake_minimum_required(VERSION 3.14)

project(OptionPricing VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


add_executable(BinomialDemo demo.cpp binomial.cpp zubairBinomialOption.cpp)

target_include_directories(BinomialDemo PUBLIC 
                            "${PROJECT_BINARY_DIR}"
)
