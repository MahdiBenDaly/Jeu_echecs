cmake_minimum_required(VERSION 3.21)
project(JeuEchecs VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.3 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Pick up the existing source and header files in Projet/, including Q_OBJECT headers.
file(GLOB CHESS_CODE CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/Projet/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Projet/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Projet/*.ui"
)

qt_add_executable(JeuEchecs ${CHESS_CODE})
target_link_libraries(JeuEchecs PRIVATE Qt6::Widgets)
set_target_properties(JeuEchecs PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.mahdibendaly.jeuechecs"
    MACOSX_BUNDLE_BUNDLE_NAME "JeuEchecs"
)

# Source code currently uses relative paths such as images/roiBlanc.png
# and scenarios/classique.txt, so install these files in predictable places.
if(APPLE)
    # CMake includes these files inside JeuEchecs.app/Contents/Resources/.
    file(GLOB CHESS_ASSETS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/Projet/images/*.png"
        "${CMAKE_CURRENT_SOURCE_DIR}/Projet/scenarios/*.txt"
    )
    foreach(asset IN LISTS CHESS_ASSETS)
        get_filename_component(asset_name "${asset}" NAME)
        if(asset_name MATCHES "^\\.")
            continue()  # Don't package macOS ._ metadata files.
        endif()
        get_filename_component(asset_dir "${asset}" DIRECTORY)
        get_filename_component(asset_group "${asset_dir}" NAME)
        set_source_files_properties("${asset}" PROPERTIES
            MACOSX_PACKAGE_LOCATION "Resources/${asset_group}")
        target_sources(JeuEchecs PRIVATE "${asset}")
    endforeach()
else()
    # On Windows, assets are beside the executable inside the installed bin/ folder.
    install(DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/Projet/images"
        "${CMAKE_CURRENT_SOURCE_DIR}/Projet/scenarios"
        DESTINATION "${CMAKE_INSTALL_BINDIR}"
        PATTERN ".*" EXCLUDE
    )
endif()

install(TARGETS JeuEchecs
    BUNDLE DESTINATION .
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

# Runs Qt's macdeployqt or windeployqt on install, including libraries/plugins.
qt_generate_deploy_app_script(
    TARGET JeuEchecs
    OUTPUT_SCRIPT qt_deploy_script
    NO_TRANSLATIONS
)
install(SCRIPT "${qt_deploy_script}")
