cmake_minimum_required(VERSION 3.14)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src
  /usr/include/allegro5
)

add_executable(
  ${PROJECT_NAME}
  gameobject_test.cpp
  vector2_test.cpp
  ../core/vector2.cpp
  ../core/vector2.h
  ../core/gameobject.h
  ../core/gameobject.cpp
  ../core/transform.h
  ../core/transform.cpp
  ../core/component.h
  ../core/component.cpp
  ../core/sprite.cpp
  ../core/sprite.h
)

target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
  allegro
  allegro_font
)

include(GoogleTest)
gtest_discover_tests(Tests)
