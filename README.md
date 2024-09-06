# Handmade _SDL_

_Handmade SDL_ is a humble C++ game engine framework wrapped around the popular and cross-platform _Simple DirectMedia Layer_ library. It was designed as a teaching tool, allowing students and aspiring game programmers to make simple 2D sprite-based games while learning intermediate and advanced C++ concepts. The engine can load images, render animations, play audio, display text, handle basic collisions, and integrate UI features via the _ImGui_ library. It currently only supports Windows 10, but if you wish to use the engine in a MacOS or Linux environment, you will need to link the appropriate library files. If you're comfortable building for Windows only, read on.

# Building the source

Whether you clone the repo or download the ZIP, you must generate a working project and environment out of the raw source code and library files provided. To do this, it is advised to download and use [CMake](https://cmake.org). I prefer to use the CMake GUI app, however, many programmers enjoy the terminal. Whichever method you choose, the CMake source folder is the one you see up above, with the CMakeLists.txt file within. Generate the project files into the destination folder of your choice, even if that is the same folder as the source folder. Generate files for the IDE of your choosing, however, my preference, and hence recommendation, is to use [Visual Studio Community 2022](https://visualstudio.microsoft.com/downloads). 

# Compiling and running the engine

With Visual Studio in mind, the rest of my documentation will reference this industry-standard IDE. Once CMake has created the build folder, open the solution via the **Handmade.sln** file. Within Visual Studio, in the _Solution Explorer_, ensure the _Handmade_ project is active by right-clicking it and selecting **Set as Startup Project**. Now, build and run the project in either **Debug** or **Release** mode, which you can set in the toolbar above. You will be presented with an empty game linked by three game states. More on that in the [Wiki](https://github.com/karsten-vermeulen-dev/Handmade-SDL/wiki).  

# The Wiki

Every bit of robust software out there isn’t complete without the proper documentation, and my own project is no exception. However, given the time I have available and the amount of material that needs to be written, the attached [Wiki](https://github.com/karsten-vermeulen-dev/Handmade-SDL/wiki) is very much a work in progress. Keep checking back for updates, and if you'd like to see rapid development of the Wiki (and the game engine), consider [sponsoring me](https://github.com/sponsors/karsten-vermeulen-dev).

# Folder structure

Below is a table detailing the folders within the repo before building them with CMake.

| Folder        | Use           | 
| ------------- | --------------| 
| Assets        | Stores all the fonts, sounds, music, image backgrounds, and sprite sheets that you can use to build your first demo |
| bin           | Keeps the SDL 2.0 .dll files which are copied to the appropriate build folders when compiling the engine      |  
| lib           | Stores the SDL 2.0 .lib files which CMake automatically links to the project when generating the solution files      |   
| Logo          | The image files for the _Handmade_ logo      | 
| src           | Stores the complete source code of the game engine. Within this folder are two subfolders which store further source code for the _SDL_ and _imgui_ libraries. All of this source code is automatically hooked into the engine by CMake  | 

Below is another table detailing the folders within the CMake build folder after Visual Studio compilation.

| Folder        | Use           | 
| ------------- | --------------| 
| Assets        | Stores all the fonts, sounds, music, image backgrounds, and sprite sheets that you can use to build your first demo. (Copied over by CMake if source and build folders are different) |
| CMakeFiles    | Keeps the relevant CMake files and folders after creating a CMake buid folder |
| Debug         | After compiling the Visual Studio project in **Debug** mode, this folder is generated and contains the executable **Handmade.exe** file which you can run as-is within Windows. The relevant _Assets_ folder and .dll files will have been copied here by CMake |
| Release       | Same as the **Debug** folder, only this folder is created when the project is compiled in **Release** mode within Visual Studio. Ideally, this is the folder you use when shipping your final game |
| Handmade.dir  | Stores the **Debug** and/or **Release** folders for Visual Studio's build files |
| x64           | More Visual Studio build files with **Debug** and/or **Release** folders within |

**Note**: If the _Debug_, _Release_, _Handmade.dir_, and/or _x64_ folders become too cluttered, you can safely delete them. They will automatically regenerate when re-compiling the project in Visual Studio.

<br> 

---

<br>

<p align="center"><img src=https://github.com/karsten-vermeulen-dev/Handmade-SDL/blob/main/Logo/Logo.png width=250 height=250></p>
