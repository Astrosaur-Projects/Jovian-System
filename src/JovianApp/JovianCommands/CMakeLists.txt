add_library(JovianCommands OBJECT)

target_sources(JovianCommands PRIVATE
	JovianRender/JovianRender.cpp
)

target_include_directories(JovianCommands PUBLIC
	${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(JovianCommands PRIVATE
	CLI11::CLI11
)