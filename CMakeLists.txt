cmake_minimum_required(VERSION 3.5)

project(Game)

add_executable(
  ${PROJECT_NAME}
  main.cpp 
)

add_subdirectory(core)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC core
  /usr/include/allegro5
)

target_link_libraries(${PROJECT_NAME} core allegro allegro_font allegro_primitives allegro_image)
