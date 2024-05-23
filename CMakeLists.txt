# CMakeList.txt : CMake project for HDMI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)
include(FetchContent)

# Enable Hot Reload for MSVC compilers if supported.
#if (POLICY CMP0141)
#   cmake_policy(SET CMP0141 NEW)
#   set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
#endif()

project ("HDMI")

# Add source and include directories
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/menus/*.cpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/menus/*.hpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/*.hpp")

# FOR LVGL: Specify path to own LVGL config header
set(LV_CONF_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/include/lv_conf.h
    CACHE STRING "" FORCE)

# Add LVGL from lib folder
add_subdirectory(lib/SDL2)

# Fetch LVGL from GitHub
FetchContent_Declare(lvgl GIT_REPOSITORY https://github.com/lvgl/lvgl.git)
FetchContent_MakeAvailable(lvgl)

# Add source to this project's executable.
add_executable (HDMI_test "HDMI.cpp" "HDMI.h" ${SOURCES} ${HEADERS})

# The target depends on LVGL
target_link_libraries(HDMI_test PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(HDMI_test PRIVATE lvgl::lvgl lvgl::examples lvgl::demos)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HDMI_test PROPERTY CXX_STANDARD 20)
endif()

# For Visual Studio "edit and continue" function support
# if(MSVC)
#    target_compile_options(HDMI_test PUBLIC "/ZI")
#    target_link_options(HDMI_test PUBLIC "/INCREMENTAL")
# endif()

# TODO: Add tests and install targets if needed.