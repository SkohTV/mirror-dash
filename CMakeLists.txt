cmake_minimum_required(VERSION 3.10)
project(MyProject)

# List of directories to search for source files
set(SOURCES
	primitives
	interfaces
	tests
)

# List of banned filenames (without extensions)
set(BANNED
	_structs
)


# Compile flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -g")

# Find all source files in the specified directories
foreach(SOURCE ${SOURCES})
	file(GLOB_RECURSE SOURCES_LIST_${SOURCE}
		${SOURCE}/*.c
		${SOURCE}/*.h
	)

	# Exclude any banned files from the list of sources
	foreach(BANNED_FILE ${BANNED})
		list(REMOVE_ITEM SOURCES_LIST_${SOURCE} "${SOURCE}/${BANNED_FILE}.c")
		list(REMOVE_ITEM SOURCES_LIST_${SOURCE} "${SOURCE}/${BANNED_FILE}.h")
	endforeach()

	list(APPEND SOURCES_LIST ${SOURCES_LIST_${SOURCE}})
endforeach()

# Create the executable
add_executable(MyExecutable ${SOURCES_LIST} main.c)

# Add the links
target_link_libraries(MyExecutable PRIVATE SDL2 SDL2_image SDL2_mixer m)
