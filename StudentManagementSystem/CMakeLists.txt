cmake_minimum_required(VERSION 3.14)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(xlnt CONFIG REQUIRED)
find_package(tabulate CONFIG REQUIRED)

add_executable(StudentManagementSystem
    main.cpp
    source/DataManager.cpp
    source/Student.cpp
    source/UI.cpp
    source/UserManager.cpp
)

target_include_directories(StudentManagementSystem PRIVATE include)
target_link_libraries(StudentManagementSystem PRIVATE xlnt::xlnt tabulate::tabulate)
target_include_directories(StudentManagementSystem PRIVATE
    include
    source
    ${tabulate_SOURCE_DIR}/include
    ${xlnt_SOURCE_DIR}/include     
)

if(WIN32)
    add_custom_command(TARGET StudentManagementSystem POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:xlnt::xlnt>
            $<TARGET_FILE_DIR:StudentManagementSystem>
    )
endif()