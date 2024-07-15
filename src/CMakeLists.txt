add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(speed)

target_link_libraries(${PROJECT_NAME} PRIVATE Speed)