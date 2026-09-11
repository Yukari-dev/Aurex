cmake_minimum_required(VERSION 3.20)
project(Forma VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

find_library(AXIOM_LIB 
  NAMES axiom 
  PATHS /usr/local/lib
)

find_path(AXIOM_INCLUDE_DIR 
  NAMES axiom.h 
  PATHS /usr/local/include
)

file(GLOB_RECURSE PRAXIS_SOURCES
  "src/forma/*.cpp"
  "src/forma/layout/*.cpp"
  "src/forma/input/*.cpp"
  "src/forma/components/*.cpp"
  "src/forma/render/*.cpp"
  "src/forma/render/renderNodes/*.cpp"
  "src/forma/animation/*.cpp"
  "src/forma/animation/attributes/*.cpp"
  "src/forma/animation/groups/*.cpp"
)

add_library(Forma STATIC ${PRAXIS_SOURCES})

target_include_directories(Forma PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  ${AXIOM_INCLUDE_DIR}
  ${AXIOM_INCLUDE_DIR}/platform
  ${AXIOM_INCLUDE_DIR}/renderer2d
  ${AXIOM_INCLUDE_DIR}/rhi
)

target_link_libraries(Forma PUBLIC
  ${AXIOM_LIB}
  Vulkan::Vulkan
  glfw
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sandbox/main.cpp")
  add_executable(forma sandbox/main.cpp)
  target_link_libraries(forma PRIVATE Forma)
endif()
