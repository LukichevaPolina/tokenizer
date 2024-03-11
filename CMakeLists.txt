cmake_minimum_required(VERSION 3.10)
project(simple_tokenizer)

#--------------------------------------Create a library--------------------------------------
file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(simple_tokenizer SHARED ${SRC})
target_include_directories(simple_tokenizer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


#--------------------------------------Create executable--------------------------------------
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/samples/main.cpp)
target_link_libraries(main PRIVATE simple_tokenizer)
