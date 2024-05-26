cmake_minimum_required (VERSION 3.10.2)
project (mod-lab06-markov)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)

# Добавление Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# Для выполнения обновления только один раз
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TextGenerator src/main.cpp src/textgen.cpp test/tests.cpp)
target_link_libraries(TextGenerator gtest_main)

include(GoogleTest)
gtest_discover_tests(TextGenerator)
