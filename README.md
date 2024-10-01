# Handmade _SDL_

_Handmade SDL_ is a humble C++ game engine framework wrapped around the popular and cross-platform _Simple DirectMedia Layer_ library. It was designed as a teaching tool, allowing students and aspiring game programmers to make simple 2D sprite-based games while learning intermediate and advanced C++ concepts. The engine can load images, render animations, play audio, display text, handle basic collisions, and integrate UI features via the _ImGui_ library. It currently only supports _Windows 10_, but if you wish to use the engine in a _MacOS_ or _Linux_ environment, you will need to link the appropriate library files.

## The Wiki

Every bit of robust software out there isn't complete without the proper documentation, and my own project is no exception. Check the attached [Wiki](https://github.com/karsten-vermeulen-dev/Handmade-SDL/wiki) for more technical information about the various parts of the game engine.

## Building the source
Whether you clone the repo or directly download the source code, you must generate a working project and environment out of the code and library files provided. You are advised to download and use [CMake](https://cmake.org) to do this. You may wish to use the CMake GUI app or build from the terminal, but whichever method you choose, the CMake source folder is the one you see above, with the _CMakeLists.txt_ file within. Generate the project files into the destination folder of your choice, even if that's the same folder as the source folder. In terms of preferred IDE, mine is the industry-standard [Visual Studio Community 2022](https://visualstudio.microsoft.com/downloads), and with that in mind, the rest of my documentation will reference this IDE only.

## Compiling and running the engine

Once CMake has created the build folder, open the solution via the **Handmade.sln** file. Within Visual Studio, in the _Solution Explorer_, ensure the _Handmade_ project is active by right-clicking it and selecting **Set as Startup Project**. Now, build and run the project in either **Debug** or **Release** mode, which you can set in the toolbar above. You will be presented with an empty game linked by three game states. 

## Folder structure

Below is a table detailing the folders within the repo before building them with CMake.

| Folder        | Use           | 
| ------------- | --------------| 
| .git          | All the files and folders that manage and track this repository are kept here. It's usually a hidden folder, and only appears if you've cloned or forked the repo, but if you spot it, never delete it!  |
| Assets        | Stores all the fonts, sounds, music, image backgrounds, and sprite sheets that you can use to build your first demo. As you build your game, you can add your own assets into the respective sub-folders within this folder. This folder is copied over by CMake if your source and build folders are different |
| bin           | Keeps the SDL 2.0 .dll files, which are copied to the appropriate build folders when compiling the engine   |  
| lib           | Stores the SDL 2.0 .lib files, which CMake automatically links to the project when generating the solution files      |   
| Logo          | The image files for the _Handmade_ logo      | 
| src           | Stores the complete source code of the game engine. Within this folder are two subfolders which store further source code for the _SDL_ and _imgui_ libraries. Any additional source code that you add to the project should be placed here. All of this source code is automatically hooked into the engine by CMake  | 

Below is another table detailing the folders within the CMake build folder after Visual Studio compilation.

| Folder        | Use           | 
| ------------- | --------------| 
| .vs           | Another hidden folder storing Visual Studio's build data |
| CMakeFiles    | Keeps the relevant CMake files and folders after creating a CMake build folder |
| Debug         | After compiling the Visual Studio project in **Debug** mode, this folder is generated and contains the executable **Handmade.exe** file, which you can run as-is within Windows. The relevant _Assets_ folder and .dll files will have been copied here by CMake |
| Release       | Same as the **Debug** folder, only this folder is created when the project is compiled in **Release** mode within Visual Studio. Ideally, this is the folder you use when shipping your final game |
| Handmade.dir  | Stores the **Debug** and/or **Release** folders for Visual Studio's build files |
| x64           | More Visual Studio build files with **Debug** and/or **Release** folders within |

**Note**: If the _.vs_, _Debug_, _Release_, _Handmade.dir_, and/or _x64_ folders become too cluttered, you can safely delete them. They will automatically regenerate when re-compiling the project in Visual Studio.

## Sponsor me
If the software I create is useful to you, and you'd like for me to create tons more, then consider [sponsoring me](https://github.com/sponsors/karsten-vermeulen-dev).

---

<br>

<p align="center"><img src=https://github.com/karsten-vermeulen-dev/Handmade-SDL/blob/main/Logo/Logo.png width=250 height=250></p> <br>

<p align="center"><b>Designed to teach. Made from scratch. Built by hand.</p>
