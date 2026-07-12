add_library(JovianApp STATIC)

target_sources(JovianApp PRIVATE
	JovianView/JovianView.cpp
	JovianData/JovianData.cpp
	JovianFind/JovianFind.cpp
)

target_include_directories(JovianApp PUBLIC
	${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(JovianApp PRIVATE
	CLI11::CLI11
)