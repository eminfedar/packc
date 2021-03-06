cmake_minimum_required(VERSION 2.8)

project(packc)

set(SHARED_FLAGS)
set(CMAKE_C_FLAGS "-std=c17 ${SHARED_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++17 ${SHARED_FLAGS}")


set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

# set(PROJECT_UTILS_DIR ${PROJECT_DIR}/utils)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/ProjectCreator.cpp
        ${PROJECT_SOURCE_DIR}/Application.cpp
        ${PROJECT_SOURCE_DIR}/ProjectBuilder.cpp
        ${PROJECT_SOURCE_DIR}/FileManager.cpp
        )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/ProjectCreator.hpp
        ${PROJECT_INCLUDE_DIR}/ProjectBuilder.hpp
        ${PROJECT_INCLUDE_DIR}/Application.hpp
        ${PROJECT_INCLUDE_DIR}/FileManager.hpp
        ${PROJECT_INCLUDE_DIR}/json.hpp
        )

include_directories(${PROJECT_INCLUDE_DIR})
# target_link_libraries(ncurses)
# if (UNIX AND NOT APPLE)
#    link_libraries(stdc++fs)
# endif (UNIX AND NOT APPLE)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
