cmake_minimum_required(VERSION 3.16)
project(RandomNameGenerator VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
set(SOURCES
    main.cpp
    history.cpp
    randomnamegenerator.cpp
    record.cpp
    time.cpp
)
set(HEADERS
    history.hpp
    randomnamegenerator.hpp
    record.hpp
    time.hpp
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
