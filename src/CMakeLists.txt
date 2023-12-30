include(ExternalProject)

ExternalProject_Add(cxxopt 
	GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
	SOURCE_DIR "cxxopt-src"
	INSTALL_COMMAND ""
	BUILD_COMMAND ""
)
# Get the source directory of the external project
ExternalProject_Get_Property(cxxopt SOURCE_DIR)

# Print the source directory (for demonstration purposes)
message(STATUS "Source directory of ExternalProjectExample: ${SOURCE_DIR}")
ExternalProject_Get_Property(cxxopt source_dir)
set(CXXOPT_LIB_INCLUDE_DIR ${source_dir}/include)

add_custom_target(DownloadExternalProject
    DEPENDS cxxopt
)


add_executable(HackAssembler 
    main.cpp 
    hack_parser.cpp
    hack_instruction.cpp
    hack_code.cpp
)

add_dependencies(HackAssembler DownloadExternalProject)

target_include_directories(HackAssembler PRIVATE ${CXXOPT_LIB_INCLUDE_DIR})
include_directories(.)

