cmake_minimum_required(VERSION 3.0)
project(Graper)

include_directories(${CMAKE_SOURCE_DIR})

include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# graper static lib
add_library(graper_sl STATIC
            src/graper.cpp)

add_executable(graper_test
               test/graper_main_test.cpp)
target_link_libraries(graper_test
                      graper_sl
                      gtest_main)

gtest_discover_tests(graper_test)
