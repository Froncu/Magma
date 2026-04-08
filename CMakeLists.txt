cmake_minimum_required(VERSION 3.15)
project(magma)

add_subdirectory(eruptor)

add_executable(${PROJECT_NAME}
   source/magma.cpp)

target_include_directories(${PROJECT_NAME}
   PRIVATE source)

target_link_libraries(${PROJECT_NAME}
   PRIVATE eruptor_entry)

set_target_properties(${PROJECT_NAME} PROPERTIES
   CXX_STANDARD 23
   CXX_STANDARD_REQUIRED TRUE
   LINK_DEPENDS $<TARGET_FILE:eruptor>)

target_compile_options(${PROJECT_NAME}
   PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
   PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>)

add_custom_command(TARGET ${PROJECT_NAME}
   POST_BUILD COMMAND
   ${CMAKE_COMMAND} -E copy_if_different
   $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
   $<TARGET_FILE_DIR:${PROJECT_NAME}>
   COMMAND_EXPAND_LISTS)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
   ${CMAKE_SOURCE_DIR}/assets
   $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)