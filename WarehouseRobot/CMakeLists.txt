cmake_minimum_required(VERSION 3.14)
project(WarehouseRobot)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Define the location where the header file will be downloaded.
set(OLCPGE_HEADER "${CMAKE_BINARY_DIR}/include/olcPixelGameEngine.h")

# Check if the header already exists to avoid re-downloading it every time.
if(NOT EXISTS "${OLCPGE_HEADER}")
    # Download the olcPixelGameEngine header file
    file(DOWNLOAD
            "https://raw.githubusercontent.com/OneLoneCoder/olcPixelGameEngine/master/olcPixelGameEngine.h"
            "${OLCPGE_HEADER}"
            SHOW_PROGRESS
    )
endif()

# Include the directory where the header file is downloaded.
include_directories("${CMAKE_BINARY_DIR}/include")

# Define your executable and source files
add_executable(${PROJECT_NAME} main.cpp
        WarehouseMap.h)

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Link against GDI+, dwmapi, and shlwapi (Windows only)
if(WIN32)
    target_link_libraries(${PROJECT_NAME} gdiplus dwmapi shlwapi)
endif()

