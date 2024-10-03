# include the SFML specific macros
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# Add Emscripten-specific settings
if(EMSCRIPTEN)
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "Disable audio for Emscripten")
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "Disable network for Emscripten")
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "Force static libraries for Emscripten")
endif()

# let CMake know about our additional libraries paths
if (SFML_OS_WINDOWS)
    # Windows-specific settings
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers")
    # Additional settings for Windows...
    
elseif(SFML_OS_MACOSX)
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers")
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${PROJECT_SOURCE_DIR}/extlibs/libs-osx/lib/")

# Add this block to handle Emscripten case
elseif(EMSCRIPTEN)
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers")
    # Emscripten does not support dynamic libraries, so we disable those modules.
    set(SFML_BUILD_AUDIO OFF)
    set(SFML_BUILD_NETWORK OFF)

endif()

# Define the path of our additional CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Set the output directory for SFML libraries
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# Add the modules subdirectories

# sfml-system
add_subdirectory(System)

# sfml-main and sfml-activity
if(SFML_OS_WINDOWS OR SFML_OS_ANDROID OR SFML_OS_IOS)
    add_subdirectory(Main)
endif()

# sfml-window
if(SFML_BUILD_WINDOW OR SFML_BUILD_GRAPHICS)
    add_subdirectory(Window)
endif()

# sfml-network
if(SFML_BUILD_NETWORK)
    add_subdirectory(Network)
endif()

# sfml-graphics
if(SFML_BUILD_GRAPHICS)
    add_subdirectory(Graphics)
endif()

# sfml-audio
if(SFML_BUILD_AUDIO)
    add_subdirectory(Audio)
endif()
