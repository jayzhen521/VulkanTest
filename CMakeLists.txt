cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(OpenGLLab LANGUAGES C CXX)

# find_include and find_library

find_path(GLFW_INCLUDE_DIR
    GLFW/glfw3.h
    HINTS
        $ENV{GLFW_PATH}/include
)

find_path(GLOG_INCLUDE_DIR
    glog/logging.h
    HINTS
        $ENV{GLOG_PATH}/include
)

find_path(STB_INCLUDE_DIR
    stb_image.h
    HINTS
        $ENV{STB_PATH}
)

find_path(VULKAN_INCLUDE_DIR
    vulkan/vulkan.h
    HINTS
        $ENV{VULKAN_PATH}/Include
)

find_library(GLFW_LIBRARY_DEBUG
    glfw3dll
    HINTS
        $ENV{GLFW_PATH}/lib/Debug
)

find_library(GLFW_LIBRARY_RELEASE
    glfw3dll
    HINTS
        $ENV{GLFW_PATH}/lib/Release
)

find_library(VULKAN_LIBRARY
    vulkan-1.lib
    HINTS
        $ENV{VULKAN_PATH}/Lib
)

# end find_include and find_library

#macro
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
#end macro

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

add_subdirectory(Projects)