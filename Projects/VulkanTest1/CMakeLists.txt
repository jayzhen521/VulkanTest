get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

if(MSVC)
    file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*h)
    file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
    add_executable(${ProjectId} ${SRC_FILES} ${INCLUDE_FILES} ${SHADER_FILES})
else()
    add_executable(${ProjectId} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
endif()

target_include_directories(${ProjectId} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${VULKAN_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    $ENV{GLM_PATH}
    ${GLOG_INCLUDE_DIR})

target_link_libraries(${ProjectId}
    PRIVATE
    ${VULKAN_LIBRARY}
    debug $ENV{GLOG_PATH}/lib/glogd.lib ${GLFW_LIBRARY_DEBUG}
    optimized $ENV{GLOG_PATH}/lib/glog.lib ${GLFW_LIBRARY_RELEASE})

if(MSVC)
    set_property(TARGET ${ProjectId} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()