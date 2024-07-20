set(SOURCES perceptron.cpp)
set(LIBRARY NeuralNetwrok)

add_library(${LIBRARY} ${SOURCES})

target_include_directories(${LIBRARY} PUBLIC .)