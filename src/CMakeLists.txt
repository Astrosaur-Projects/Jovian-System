add_executable(JovianOrrery)

target_sources(JovianOrrery PRIVATE
	main.cpp
)

target_include_directories(JovianOrrery PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)