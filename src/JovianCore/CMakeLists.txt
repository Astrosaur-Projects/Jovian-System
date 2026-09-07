add_subdirectory(JovianEphemerides)

add_library(JovianCore STATIC)

target_sources(JovianCore PRIVATE
	JovianRegistry/JovianRegistry.cpp
	JovianCommandInterface.h
)

target_include_directories(JovianCore PUBLIC
	${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(JovianCore PRIVATE
	JovianEphemerides
	CLI11::CLI11
)