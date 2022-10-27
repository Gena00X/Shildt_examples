cmake_minimum_required(VERSION 2.8...3.13)


set( CMAKE_CXX_COMPILER "C:/Program Files/TDM-GCC-64/bin/g++.exe" )
set( CMAKE_C_COMPILER "C:/Program Files/TDM-GCC-64/bin/gcc.exe" )
set( RUS_IN_CONSOLE "D:/CPP/QtPrpjects/ProjectsCPP/my_special_heders" )
set( CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/bin )
set( SOURCES src/main.cpp )
set( HEADERS 
	 src/heders/heder1.hpp 
	 src/heders/template_func.hpp 
	 src/heders/template_queue.hpp
	 )

project(main)

add_executable(
	main 
	${SOURCES}
	${HEADERS}
	)
	
target_compile_features(
	main 
	PRIVATE cxx_std_17
	)

include_directories(
	${RUS_IN_CONSOLE}
	${CMAKE_CURRENT_LIST_DIR}/src/heders
	)

#target_link_libraries(
#	main 
#	${OPENSSL_LIBRARIES}
#	${WSOCK32_LIBRARY}
#	${WS2_32_LIBRARY}
#	)

install(
	TARGETS main
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
	)
	