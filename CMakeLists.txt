cmake_minimum_required (VERSION 3.6)
project (pic_convolving_engine CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O2 -Wall -Wno-psabi")



#######################################################
#                                                     #
# Add new directories with *.cpp files to this list   #
# All source code should be compiled in build process #
#                                                     #
# Author: Wolanski Grzegorz                           #
#                                                     #
#######################################################



# collect directories to SOURCE_DIRECTORIES variable
# directories should be added manually here
set(SOURCE_DIRECTORIES
        Miscellanous/
        STBlib/
        IO/
        ImageProcessing/
   )


#######################################################


# collect all *.cpp files from SOURCE_DIRECTORIES into SOURCE_FILES variable
foreach(SOURCE_DIRECTORY ${SOURCE_DIRECTORIES})

    # create *_REGEX pattern for each directory
    set(${SOURCE_DIRECTORY}_REGEX ${SOURCE_DIRECTORY}*.cpp)

    # collect *.cpp files in *_FILES variable for given directory
    file(GLOB_RECURSE ${SOURCE_DIRECTORY}_FILES ${${SOURCE_DIRECTORY}_REGEX})

    # append all *.cpp files from each directory to SOURCE_FILES variable
    list(APPEND SOURCE_FILES ${${SOURCE_DIRECTORY}_FILES})

endforeach()

# append main.cpp to already collected *.cpp files
list(APPEND SOURCE_FILES main.cpp)


#######################################################


# link boost libs
find_package(Boost 1.66.0 COMPONENTS program_options)
if(Boost_FOUND)

    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(bin ${SOURCE_FILES})
    target_link_libraries(bin ${Boost_LIBRARIES})

endif()

target_include_directories(bin PRIVATE ${CMAKE_SOURCE_DIR})
