# cmake_minimum_required(VERSION 3.10)
# project(StudentManagementSystem)

# set(CMAKE_CXX_STANDARD 17)


# include_directories(include)


# file(GLOB SOURCES "main.cpp" "source/*.cpp")


# add_executable(StudentApp ${SOURCES})


# include(FetchContent)
# FetchContent_Declare(
#   tabulate
#   GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
#   GIT_TAG main
# )
# FetchContent_MakeAvailable(tabulate)
# target_link_libraries(StudentApp PRIVATE xlnt tabulate)

# add_custom_command(TARGET StudentApp POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
#         $<TARGET_FILE_DIR:StudentApp>)

# cmake_minimum_required(VERSION 3.14)
# project(StudentManagementSystem)

# set(CMAKE_CXX_STANDARD 17)

# include(FetchContent)

# # Fetch xlnt
# FetchContent_Declare(
#   xlnt
#   GIT_REPOSITORY https://github.com/tfussell/xlnt.git
#   GIT_TAG main
# )
# FetchContent_MakeAvailable(xlnt)

# # Fetch tabulate
# FetchContent_Declare(
#   tabulate
#   GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
#   GIT_TAG main
# )
# FetchContent_MakeAvailable(tabulate)

# # Add your main.cpp or other source files
# add_executable(StudentManagementSystem main.cpp source/DataManager.cpp source/Student.cpp include/Student.hpp source/UI.cpp source/UserManager.cpp include/UserManager.hpp)

# # Tell the compiler where to find all the headers 
# target_include_directories(StudentManagementSystem PRIVATE include )
# # Link libraries
# target_link_libraries(StudentManagementSystem PRIVATE xlnt tabulate)

# add_custom_command(TARGET StudentManagementSystem POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
#         $<TARGET_FILE_DIR:StudentManagementSystem>)

#         if(WIN32)
#     add_custom_command(TARGET StudentManagementSystem POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#             "/c/Users/pseak/Documents/vcpkg/installed/x64-windows/bin/xlnt.dll"
#             $<TARGET_FILE_DIR:StudentManagementSystem>
#     )
# endif()

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

if(WIN32)
    add_custom_command(TARGET StudentManagementSystem POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:xlnt::xlnt>
            $<TARGET_FILE_DIR:StudentManagementSystem>
    )
endif()