add_subdirectory(JovianCore)

add_executable(JovianSystem)

target_sources(JovianSystem PRIVATE
	Jovian.cpp
)

target_include_directories(JovianSystem PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(JovianSystem PRIVATE
	JovianCore
	CLI11::CLI11
)