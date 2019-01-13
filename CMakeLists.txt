cmake_minimum_required(VERSION 3.10)
project(RDAlgebra2)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2")

find_package(SDL2)

if(MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wpedantic)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

if (FOUND_SDL2)
    file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
    add_executable(RDAlgebra2 ${SRC_FILES}  main.cpp)
    target_include_directories(RDAlgebra2 ${SDL2_INCLUDE_DIR} include)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
endif()

enable_testing()
file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(linal_tests ${TEST_FILES} )
target_compile_features(linal_tests PUBLIC cxx_std_17)
target_include_directories(linal_tests PUBLIC include)
target_link_libraries(linal_tests gtest gmock gtest_main)
add_test(AllTests linal_tests)
