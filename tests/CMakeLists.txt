# production source codes
set(
    SOURCES
    ${PROJECT_SOURCE_DIR}/src
)

# test cases, ... 
set(
    TEST_SOURCES
    ${SOURCES}/speed/speed.cpp
    speedgtest.cpp
)

set(
    TEST_TARGET
    ${PROJECT_NAME}_tst
)

add_executable(${TEST_TARGET} ${TEST_SOURCES})

target_include_directories(
    ${TEST_TARGET} PRIVATE
    ${SOURCES}/speed/
)

target_compile_options(${TEST_TARGET} PRIVATE -pg)

include(../cmake/googletest.cmake)
include(GoogleTest)

target_link_libraries(${PROJECT_NAME}_tst
    PRIVATE
    GTest::gtest_main
)
