# cmake_minimum_required(VERSION 3.16)

# project(zappy-gui VERSION 1.0)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "-Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

# file(GLOB SRC_LIST src/*.cpp src/socket/*.cpp src/GUI/*.cpp src/SFML/*.cpp src/parser/*.cpp src/cache/*.cpp)
# add_executable(plazza ${SRC_LIST})

# if (APPLE)
# endif()
cmake_minimum_required(VERSION 3.16)

project(zappy_gui VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# Chemin vers les bibliothèques SFML
set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1_2")
include_directories(/usr/local/Cellar/sfml/2.5.1_2/include)
link_directories(/usr/local/Cellar/sfml/2.5.1_2/lib)

# Chemin vers le framework freetype
set(FREETYPE_FRAMEWORK_PATH /Library/SFML/extlibs/libs-osx/Frameworks/freetype.framework)

# Recherche des packages SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Liste des fichiers source
file(GLOB SRC_LIST src/*.cpp src/socket/*.cpp src/GUI/*.cpp src/SFML/*.cpp src/parser/*.cpp src/cache/*.cpp)

# Définition du répertoire de sortie de l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")


# Création de l'exécutable
add_executable(zappy_gui ${SRC_LIST})

# Inclusion des headers SFML
target_include_directories(zappy_gui PRIVATE ${SFML_INCLUDE_DIRS} ${FREETYPE_FRAMEWORK_PATH}/Headers)

# Liaison des bibliothèques SFML
target_link_libraries(zappy_gui PRIVATE sfml-graphics sfml-window sfml-system sfml-audio ${FREETYPE_FRAMEWORK_PATH})
