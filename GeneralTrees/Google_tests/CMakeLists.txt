project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# If using Google Test as an external project or submodule:
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_general_tree ../test_general_tree.cpp)
target_link_libraries(test_general_tree
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        # plus your library or object files if needed
)

enable_testing()
add_test(NAME general_tree_tests COMMAND test_general_tree)
