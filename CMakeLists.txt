cmake_minimum_required(VERSION 3.20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


project(SpaceShooter VERSION 0.1.0.0)
set(POJECT_AUTHOR "YOUR NAME <YOUR.EMAIL@esiee.fr>")
set(PROJECT_ASSETS_PATH "./../../../assets")

set(CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

if(MSVC)
    list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SFML-2.6.0")
    set(BUILD_SHARED_LIBS OFF)
    set(SFML_STATIC_LIBRARIES ON)
    set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML-2.6.0")
    set(SFML_ROOT "${PROJECT_SOURCE_DIR}/SFML-2.6.0")
endif()

# For linux : apt install libsfml-dev

# SFML2 (system)
find_package(SFML 2 COMPONENTS
                    system window graphics audio # Core for game
                    network # Optional
#                    Main # Windows OS only
                    REQUIRED)

# SPACE-SHOOTER
set(SOURCE_FILES
    # ADD SOURCE FILES HERE !!
    # Core of Game
    src/space-shooter/main.cpp
    src/space-shooter/utils.cpp
    src/space-shooter/game_state.cpp
    # Scenes
    src/space-shooter/scenes/exit.cpp
    src/space-shooter/scenes/level.cpp
    src/space-shooter/scenes/menu.cpp
    # Core of ECS
    src/space-shooter/ecs/entity.cpp
    src/space-shooter/ecs/system.cpp
    src/space-shooter/ecs/manager.cpp
    # Entities
    src/space-shooter/ecs/entites/background.cpp
    src/space-shooter/ecs/entites/player_ship.cpp
    src/space-shooter/ecs/entites/text_entity.cpp
    # Systems
    src/space-shooter/ecs/systems/input_system.cpp
    src/space-shooter/ecs/systems/rendering_system.cpp
    src/space-shooter/ecs/systems/movement_system.cpp
    src/space-shooter/ecs/systems/wait_key_system.cpp
   "src/space-shooter/ecs/systems/text_system.cpp" "src/space-shooter/ecs/entites/missile.cpp" "src/space-shooter/ecs/systems/controller_system.cpp" "src/space-shooter/ecs/systems/shape_system.cpp" "src/space-shooter/ecs/systems/oob_system.cpp")

# Add executable
add_executable(space-shooter ${SOURCE_FILES} "src/space-shooter/ecs/entites/enemy.cpp")
set_property(TARGET space-shooter PROPERTY CXX_STANDARD 20)

# Configure file
configure_file (
    "${PROJECT_SOURCE_DIR}/utils/version.hpp.in"
    "${PROJECT_BINARY_DIR}/include/space-shooter/version.hpp"
)

# Set include directories
target_include_directories(space-shooter PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_include_directories(space-shooter PRIVATE "${PROJECT_BINARY_DIR}/include") #for the generated version file
target_include_directories(space-shooter PRIVATE "${PROJECT_SOURCE_DIR}/src/space-shooter")

# Set SFML dependency
# SFML 2 (system)
target_link_libraries(space-shooter PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

# Adress + leak sanitizer !
if (MSVC)
    add_compile_options(/W4 /WX /permissive-)

# (OPTIONAL) TOGGLE ADRESS SANITIZER HERE
    add_compile_options(/fsanitize=address)
    add_link_options(/fsanitize=address)
else()
    #Compile options
    target_compile_options(space-shooter PRIVATE -Wall -Wextra -pedantic -Werror )
    target_compile_options(space-shooter PRIVATE -Wno-unused-parameter)
    target_compile_options(space-shooter PRIVATE -Wno-missing-field-initializers) # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=110064

    # (OPTIONAL) TOGGLE ADRESS SANITIZER HERE
    target_compile_options(space-shooter PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_options(space-shooter PRIVATE -fsanitize=address -fno-omit-frame-pointer)
endif()

# Install the game

# Specify the installation of the binary
install(TARGETS space-shooter DESTINATION .)

# Install the entire assets directory
install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets/ DESTINATION assets)

# Specify a custom target for creating a zip
add_custom_target(
    package
    COMMAND ${CMAKE_COMMAND} --install . --prefix package-install
    COMMAND zip -r space-shooter.zip package-install
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Packaging game and assets into space-shooter.zip"
)

