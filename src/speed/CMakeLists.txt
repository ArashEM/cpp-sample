set(SOURCES speed.cpp)
set(LIBRARY Speed)

add_library(${LIBRARY} ${SOURCES})

target_include_directories(${LIBRARY} PUBLIC .)