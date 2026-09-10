add_subdirectory(JovianCore)
add_subdirectory(JovianApp)

add_executable(JovianSystem)

target_sources(JovianSystem PRIVATE
	Jovian.cpp
)

target_include_directories(JovianSystem PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(JovianSystem PRIVATE
	JovianCore
	JovianApp
	CLI11::CLI11
	Matplot++::cimg
	Matplot++::matplot
)