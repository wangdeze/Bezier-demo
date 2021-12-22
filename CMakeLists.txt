cmake_minimum_required(VERSION 2.8.3)

project(bezile_demo)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(src SRC_LIST)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC_LIST})
