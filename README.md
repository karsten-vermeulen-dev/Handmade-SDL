# Handmade _SDL_

_Handmade SDL_ is a humble **C++** game engine framework wrapped around the popular and cross-platform **Simple DirectMedia Layer** library. It was designed as a teaching tool, allowing students and aspiring game programmers to make simple 2D sprite-based games while learning intermediate and advanced C++ concepts. The engine can load images, render animations, play audio, display text, and handle basic collisions. This game engine currently only supports Windows 10. If you wish to use the engine in a MacOS or Linux environment, you will need to link the appropriate library files. If you're comfortable to build for Windows only, read on.

# Building the source

Whether you clone the repo or download the ZIP, you must generate a working project and environment out of the raw source code and library files provided. To do this, it is advised to download and use [CMake](https://cmake.org). I prefer to use the CMake GUI app, however, many programmers enjoy the terminal. Whichever method you choose, the CMake source folder is the one you see up above, with the CMakeLists.txt file within. Generate the project files into the destination folder of your choice, even if that is the same folder as the source folder. My preference for IDE to use when developing is [Visual Studio Community 2022](https://visualstudio.microsoft.com/downloads) 

# The Wiki

Every bit of robust software out there isn’t complete without the proper documentation, and my own project is no exception. However, given the time I have available and the amount of material that needs to be written, the attached [Wiki](https://github.com/karsten-vermeulen-dev/Handmade-SDL/wiki) is very much a work in progress. Keep checking back for updates, and if you'd like to see rapid development of the Wiki (and the game engine), consider [sponsoring me](https://github.com/sponsors/karsten-vermeulen-dev)

# Folder structure

Below is a table detailing the folders within the repo and what they store within.

| Folder        | Use           | 
| ------------- | --------------| 
| Assets        | Stores all the fonts, sounds, music, image backgrounds, and sprite sheets that you can use to build your first demo |
| bin           | Keeps the SDL 2.0 .dll files which are copied to the appropriate build folders when compiling the engine      |  
| lib           | Stores the SDL 2.0 .lib files which CMake automatically links to the project when generating the solution files      |   
| Logo          | The image files for the _Handmade_ logo      | 
| src           | Stores the complete source code of the game engine. Within this is a subfolder called _SDL_, which stores all of the headers for the SDL library. These headers are automatically hooked into the engine by CMake    | 

<br> 

---

<br>

<p align="center"><img src=https://github.com/karsten-vermeulen-dev/Handmade-SDL/blob/main/Logo/Logo.png width=250 height=250></p>
