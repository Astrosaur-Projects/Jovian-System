add_library(JovianCore STATIC)

target_sources(JovianCore PRIVATE
	JovianSchema/JovianRegistry/JovianRegistry.cpp
	JovianSchema/JovianCommandInterface.h
)

target_include_directories(JovianCore PUBLIC
	${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(JovianCore PRIVATE
	CLI11::CLI11
)