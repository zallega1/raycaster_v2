cmake_minimum_required(VERSION 3.23)
project(raycaster_v2 C)

include(FetchContent)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG		   3.4
)
FetchContent_MakeAvailable(glfw)

add_executable(raycaster_v2 raycaster_v2/main.c)

add_custom_command(
	TARGET raycaster_v2 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/raycaster_v2/textures"
        "$<TARGET_FILE_DIR:raycaster_v2>/textures"
)

target_sources(raycaster_v2
  PRIVATE
	raycaster_v2/background.c
	raycaster_v2/bullet.c
	raycaster_v2/door.c
	raycaster_v2/draw.c
	raycaster_v2/enemy.c
	raycaster_v2/gun.c
	raycaster_v2/hud.c
	raycaster_v2/imageloader.c
	raycaster_v2/item.c
	raycaster_v2/keys.c
	raycaster_v2/map.c
	raycaster_v2/player.c
	raycaster_v2/raycaster.c
	raycaster_v2/wall.c
)

find_package(OpenGL REQUIRED)

target_link_libraries(raycaster_v2
  PRIVATE 
	glfw
	OpenGL::GL
)