# raycaster_v2

## About this project
This is my first real solo project using C with GLFW to handle the windowing and graphics. It is a first person shooter game that uses a simple raycasting engine to simulate a 3D environment, inspired by early FPS titles such as Wolfenstein 3D. All textures were created by me, but I am not an artist. There is no sound as of right now.

I started this project because I wanted to make a game in C and was playing a lot of boomer shooters at the time. I used 3DSage's "Create your own raycaster" tutorial on YouTube initially but ended up recreating the code myself once I felt like I understood the general logic behind the engine well enough. I unfortunately didn't find out until way later that immediate mode in OpenGL is depreciated now, but for this project it is fine. There are still a lot of optimizations to be made and features I would like to add, so we'll see how far I get. My motivation to work on this comes and goes, and I do want to start another project eventually. My goal for now is to complete the first level with different enemy types and multiple weapons for the player.

## How to run

Open the .sln file in VS2022, set build config to x64, and run

## How to play

No mouse support (sorry), game is entirely playable on keyboard 

### Menus
- Up/Down - Navigate menus
- Space/Enter - Select option

### Gameplay

- W/S - Move forward/backward
- A/D - Strafe left/right
- Left/right - Turn camera left/right
- Space - Fire weapon
- E - Open doors (must be very close to the door)
- P - Restart level
