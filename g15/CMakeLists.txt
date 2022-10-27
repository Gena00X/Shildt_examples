cmake_minimum_required(VERSION 2.8...3.13)

#set( CMAKE_CXX_COMPILER "C:/Program Files/TDM-GCC-64/bin/g++.exe" )
#set( CMAKE_C_COMPILER "C:/Program Files/TDM-GCC-64/bin/gcc.exe" )
project(main)
#project(project_name)

set(SOURCES src/main.cpp )
set(HEADER_FILES )

add_executable(
		main #project_name
		${HEADER_FILES}
		${SOURCES}
		)
include_directories(src/heders D:/CPP/QtPrpjects/ProjectsCPP)		
#find_package(package_name REQUIRED)
#find_library(LIBRARY_NAME library_name)

#include_directories(
#		 ${PACKAGE_NAME_INCLUDE_DIR}
#					)

#target_link_libraries(
#	project_name
#	${PACKAGE_NAME_LIBRARIES}
#	${LIBRARY_NAME_LIBRARY}
#	)