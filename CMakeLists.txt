cmake_minimum_required(VERSION 3.17)
project(CoSDLTest)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_GFX_INCLUDE_DIR}
        includes/cosdl/)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCE_FILES
        src/*.cpp
        src/**/*.cpp
        includes/cosdl/*.cpp)

add_executable(CoSDLTest ${SOURCE_FILES})

target_link_libraries(CoSDLTest
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_GFX_LIBRARIES})
