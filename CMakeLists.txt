cmake_minimum_required (VERSION 3.15)

project (Project_Rachel_Dekel_Esther_Wahnon)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (Project_Rachel_Dekel_Esther_Wahnon WIN32 "")

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources/levels)
add_subdirectory (resources/sound)
add_subdirectory (resources/texture)
add_subdirectory (resources/font)
configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)

set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)
find_package (SFML 2.5 COMPONENTS audio REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Project_Rachel_Dekel_Esther_Wahnon sfml-graphics sfml-main)
target_link_libraries (Project_Rachel_Dekel_Esther_Wahnon sfml-audio sfml-main)

set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Project_Rachel_Dekel_Esther_Wahnon sfml-graphics sfml-main)