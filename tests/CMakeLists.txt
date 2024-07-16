set(SOURCES speedgtest.cpp)

add_executable(${PROJECT_NAME}_tst ${SOURCES})

add_subdirectory(../src/speed ${PROJECT_BINARY_DIR}/tests/speed)

include(../cmake/googletest.cmake)
include(GoogleTest)

target_link_libraries(${PROJECT_NAME}_tst
    PRIVATE
    Speed
    GTest::gtest_main
)
