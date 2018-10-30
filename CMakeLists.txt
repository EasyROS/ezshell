cmake_minimum_required(VERSION 2.8)
project(ezshell)

find_package(catkin REQUIRED COMPONENTS

)

catkin_package(
        CATKIN_DEPENDS
)
### include TL package
include_directories(${catkin_INCLUDE_DIRS})

option(Test "This is a option for Test, test the package" OFF)

set(SOURCES_DIRECTORIES
        bindsys
        command
)

foreach (DIRECTORY ${SOURCES_DIRECTORIES})
    message(STATUS "-- Sources: Adding ${DIRECTORY}/")
    include (${DIRECTORY}/source.cmake)
    set (PREFIXED_SOURCES)
    foreach (SOURCE ${Source})
        set (PREFIXED_SOURCES ${PREFIXED_SOURCES} ${DIRECTORY}/${SOURCE})
    endforeach (SOURCE)
    set (ALL_SOURCES ${ALL_SOURCES} ${PREFIXED_SOURCES})
endforeach (DIRECTORY)

foreach (SSSS ${ALL_SOURCES})
    message(STATUS "-- Sources: ${SSSS}")
endforeach (SSSS)

foreach (DIRECTORY ${SOURCES_DIRECTORIES})
if(${Test} STREQUAL "ON")
    message(STATUS "-- Sources: Test ${DIRECTORY}/test.cpp")
    add_executable (${DIRECTORY} ${ALL_SOURCES} ${DIRECTORY}/test.cpp)
endif()
endforeach (DIRECTORY)

#target_link_libraries(Test ${catkin_LIBRARIES})

