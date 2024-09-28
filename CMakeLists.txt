cmake_minimum_required(VERSION 3.10)

project(Handmade)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_FILES ${CMAKE_SOURCE_DIR}/src/Background.h 
${CMAKE_SOURCE_DIR}/src/BoxCollider.h
${CMAKE_SOURCE_DIR}/src/Button.h
${CMAKE_SOURCE_DIR}/src/EndState.h
${CMAKE_SOURCE_DIR}/src/Game.h
${CMAKE_SOURCE_DIR}/src/GameObject.h
${CMAKE_SOURCE_DIR}/src/GameState.h
${CMAKE_SOURCE_DIR}/src/Input.h
${CMAKE_SOURCE_DIR}/src/MenuKey.h
${CMAKE_SOURCE_DIR}/src/Music.h
${CMAKE_SOURCE_DIR}/src/Player.h
${CMAKE_SOURCE_DIR}/src/PlayState.h
${CMAKE_SOURCE_DIR}/src/Screen.h
${CMAKE_SOURCE_DIR}/src/Sound.h
${CMAKE_SOURCE_DIR}/src/SphereCollider.h
${CMAKE_SOURCE_DIR}/src/StartState.h
${CMAKE_SOURCE_DIR}/src/Text.h
${CMAKE_SOURCE_DIR}/src/Texture.h
${CMAKE_SOURCE_DIR}/src/Utility.h
${CMAKE_SOURCE_DIR}/src/Vector.h)

set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/Background.cpp 
${CMAKE_SOURCE_DIR}/src/BoxCollider.cpp
${CMAKE_SOURCE_DIR}/src/Button.cpp
${CMAKE_SOURCE_DIR}/src/EndState.cpp
${CMAKE_SOURCE_DIR}/src/Game.cpp
${CMAKE_SOURCE_DIR}/src/GameObject.cpp
${CMAKE_SOURCE_DIR}/src/Input.cpp
${CMAKE_SOURCE_DIR}/src/Main.cpp
${CMAKE_SOURCE_DIR}/src/MenuKey.cpp
${CMAKE_SOURCE_DIR}/src/Music.cpp
${CMAKE_SOURCE_DIR}/src/Player.cpp
${CMAKE_SOURCE_DIR}/src/PlayState.cpp
${CMAKE_SOURCE_DIR}/src/Screen.cpp
${CMAKE_SOURCE_DIR}/src/Sound.cpp
${CMAKE_SOURCE_DIR}/src/SphereCollider.cpp
${CMAKE_SOURCE_DIR}/src/StartState.cpp
${CMAKE_SOURCE_DIR}/src/Text.cpp
${CMAKE_SOURCE_DIR}/src/Texture.cpp
${CMAKE_SOURCE_DIR}/src/Utility.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_demo.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_draw.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdl2.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdlrenderer2.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_tables.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_widgets.cpp)

add_executable(Handmade ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/SDL)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/imgui)

target_link_libraries(Handmade 
${CMAKE_SOURCE_DIR}/lib/SDL2.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2main.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_image.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_mixer.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_ttf.lib)

source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Music.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Sound.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Text.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Texture.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/BoxCollider.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/SphereCollider.h)
source_group("Header Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Vector.h)
source_group("Header Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Game.h)
source_group("Header Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Input.h)
source_group("Header Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Screen.h)
source_group("Header Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Utility.h)
source_group("Header Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/Background.h)
source_group("Header Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/GameObject.h)
source_group("Header Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/MenuKey.h)
source_group("Header Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/Player.h)
source_group("Header Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/EndState.h)
source_group("Header Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/GameState.h)
source_group("Header Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/PlayState.h)
source_group("Header Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/StartState.h)

source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Music.cpp)
source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Sound.cpp)
source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Text.cpp)
source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/Texture.cpp)
source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/BoxCollider.cpp)
source_group("Source Files/Components" FILES ${CMAKE_SOURCE_DIR}/src/SphereCollider.cpp)
source_group("Source Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Game.cpp)
source_group("Source Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Input.cpp)
source_group("Source Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Main.cpp)
source_group("Source Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Screen.cpp)
source_group("Source Files/Core" FILES ${CMAKE_SOURCE_DIR}/src/Utility.cpp)
source_group("Source Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/Background.cpp)
source_group("Source Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/GameObject.cpp)
source_group("Source Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/MenuKey.cpp)
source_group("Source Files/GameObjects" FILES ${CMAKE_SOURCE_DIR}/src/Player.cpp)
source_group("Source Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/EndState.cpp)
source_group("Source Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/PlayState.cpp)
source_group("Source Files/GameStates" FILES ${CMAKE_SOURCE_DIR}/src/StartState.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_demo.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_draw.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdl2.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdlrenderer2.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_tables.cpp)
source_group("Source Files/imgui" FILES ${CMAKE_SOURCE_DIR}/src/imgui/imgui_widgets.cpp)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets
$<TARGET_FILE_DIR:Handmade>/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets 
${CMAKE_BINARY_DIR}/Assets)