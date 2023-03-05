# minimum CMake version required
	cmake_minimum_required(VERSION 3.15)
	# Project name, version and description
	project(AchooBot_CPP VERSION 0.1 DESCRIPTION "AchooBot C/C++")
	 
	# Add DPP as dependency
	add_subdirectory(libs/DPP)
	add_subdirectory(libs/opus)
	#add_subdirectory(libs/opus-tools)
	#add_subdirectory(libs/opusfile)
	#add_subdirectory(libs/libopusenc)
	# You can also add any other libs you want to use
	 
	# Create an executable
	add_executable(${PROJECT_NAME}
	    src/main.cpp
	    # your other files...
	)
	 
	# Linking libraries
	target_link_libraries(${PROJECT_NAME}
	    dpp
	    # Add any other libs you want to use here
	)
	
	# Specify includes
	target_include_directories(${PROJECT_NAME} PRIVATE
	    libs/DPP/include
		#libs/libopusenc/include
		libs/opus/include
		#libs/opus-tools/include
		#libs/opusfile/include
	    # Remember to add the include directories of any other libraries too
	)
	 
	# Set C++ version
	set_target_properties(${PROJECT_NAME} PROPERTIES
	    CXX_STANDARD 17
	    CXX_STANDARD_REQUIRED ON
	)