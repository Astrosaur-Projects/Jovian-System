add_library(JovianApp STATIC)

add_subdirectory(JovianCommands)

target_include_directories(JovianApp PUBLIC
	$<TARGET_OBJECTS:JovianCommands>
)

target_link_libraries(JovianApp PRIVATE
	JovianCommands
	CLI11::CLI11
)