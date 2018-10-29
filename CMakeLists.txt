cmake_minimum_required(VERSION 2.8)
project(ShellService)

find_package(catkin REQUIRED COMPONENTS

)

catkin_package(
        CATKIN_DEPENDS
)
### include TL package
include_directories(${catkin_INCLUDE_DIRS})

option(Test "This is a option for Test, test the package" OFF)

set(SOURCES_DIRECTORIES
	sys_tree
    sys_bind
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

if(${Test} STREQUAL "ON")
    #ADD_DEFINITIONS(-DBindTestRun)
    #add_executable(sys_bind_test ${ALL_SOURCES})
endif()

#if(${Test} STREQUAL "ON")
add_executable (Test test/main.cpp ${ALL_SOURCES})
#endif()

#target_link_libraries(Test ${catkin_LIBRARIES})

