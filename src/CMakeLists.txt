add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(speed)
add_subdirectory(nn)

target_compile_options(${PROJECT_NAME}  PRIVATE -Wall -Weffc++ -Wextra)
target_link_libraries(${PROJECT_NAME} PRIVATE Speed NeuralNetwrok)