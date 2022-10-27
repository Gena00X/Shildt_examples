cmake_minimum_required(VERSION 2.8...3.13)

set( MY_SPECIAL_HEDERS "H:/CPP/QtPrpjects/ProjectsCPP/my_special_heders" )
set( BINARY_DIR 	${CMAKE_CURRENT_LIST_DIR}/bin )
set( SOURCES_DIR 	${CMAKE_CURRENT_LIST_DIR}/src )
set( HEDERS_DIR 	${CMAKE_CURRENT_LIST_DIR}/src/heders )
set( SOURCES 		${SOURCES_DIR}/main.cpp )

project(main)

add_executable( main ${SOURCES} )
include_directories(main 
					${HEDERS_DIR} 
					${MY_SPECIAL_HEDERS}
					)

install(TARGETS main DESTINATION ${BINARY_DIR} )

target_compile_features( main PRIVATE cxx_std_17 )

