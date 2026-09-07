add_library(JovianEphemerides STATIC)

target_sources(JovianEphemerides PRIVATE
	JovianJupiter/JovianJupiter.cpp
)

target_include_directories(JovianEphemerides PUBLIC
	${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(JovianEphemerides PRIVATE
	
)