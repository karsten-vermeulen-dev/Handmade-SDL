cmake_minimum_required(VERSION 3.10)

project(Handmade)

set(CMAKE_CXX_STANDARD 17)

add_executable(Handmade 
src/Background.cpp 
src/BoxCollider.cpp
src/Button.cpp
src/EndState.cpp
src/Game.cpp
src/GameObject.cpp
src/GameState.cpp
src/Input.cpp
src/Main.cpp
src/MenuKey.cpp
src/Music.cpp
src/Plane.cpp
src/Player.cpp
src/PlayState.cpp
src/Screen.cpp
src/Sound.cpp
src/SphereCollider.cpp
src/StartState.cpp
src/Text.cpp
src/Texture.cpp
src/Utility.cpp)

target_link_libraries(Handmade 
${CMAKE_SOURCE_DIR}/lib/SDL2.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2main.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_image.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_mixer.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_ttf.lib)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets
$<TARGET_FILE_DIR:Handmade>/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets 
${CMAKE_BINARY_DIR}/Assets)
