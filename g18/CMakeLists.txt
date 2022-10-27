cmake_minimum_required(VERSION 2.8...3.13)


set( CMAKE_CXX_COMPILER "C:/Program Files/TDM-GCC-64/bin/g++.exe" )
set( CMAKE_C_COMPILER "C:/Program Files/TDM-GCC-64/bin/gcc.exe" )

set( RUS_IN_CONSOLE "D:/CPP/QtPrpjects/ProjectsCPP/my_special_heders" )
set( BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/bin )
set( DATA_DIR ${CMAKE_CURRENT_LIST_DIR}/data )
set( SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src )
set( HEDERS_DIR ${SRC_DIR}/heders )

set( SOURCES 
	${SRC_DIR}/main.cpp 
	${SRC_DIR}/three_d.cpp
	${SRC_DIR}/str_type.cpp
	)
set( HEADERS 
	${RUS_IN_CONSOLE}/rusinconsole.h
	${HEDERS_DIR}/mymanip.hpp
	${HEDERS_DIR}/three_d.hpp
	${HEDERS_DIR}/oldtests.hpp
	${HEDERS_DIR}/str_type.hpp
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
	${HEDERS_DIR}
	${DATA_DIR}
	)

#target_link_libraries(
#	main 
#	${OPENSSL_LIBRARIES}
#	${WSOCK32_LIBRARY}
#	${WS2_32_LIBRARY}
#	)

install(
	TARGETS main
	DESTINATION ${BINARY_DIR}
	)
	