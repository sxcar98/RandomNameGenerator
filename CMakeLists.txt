cmake_minimum_required(VERSION 3.16)

# 工程名和 C++ 标准
project(NamePicker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# MSYS2 UCRT64 下 Qt6 的 cmake 包在 /ucrt64/lib/cmake 下
# 使用 find_package 找到 Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# 源码文件
set(SOURCES
    main.cpp
    history.cpp
    namepicker.cpp
    record.cpp
    time.cpp
)

set(HEADERS
    history.hpp
    namepicker.hpp
    record.hpp
    time.hpp
)

# 可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# 链接 Qt6 库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# 如果你想让 exe 更像 Windows 程序（无黑色控制台窗口），可以加：
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
