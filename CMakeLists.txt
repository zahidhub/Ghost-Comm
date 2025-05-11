# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Define Project name
project(ghostComm)

# Create a static lib, so that others can link against it
add_library(ghostcomm_lib src/ghostComm.c)

# Define an executable target named ghostComm, built from main.c
add_executable(ghostComm src/main.c)

# Link the ghostomm_lib with the executable. 'PRIVATE' means
# ghostcomm_lib inlcudes dirs/etc. only
target_link_libraries(ghostComm PRIVATE ghostcomm_lib)

# Adds ${PROJECT_BINARY_DIR} to ghostComms include path
target_include_directories(ghostComm PUBLIC "${PROJECT_BINARY_DIR}")

#--------------------------------------------------------------------
########################### Build the test ##########################
#--------------------------------------------------------------------

# Turn on CTest support so you can register and run tests with add_test()
enable_testing()

# Define an execuatable target run_tests from test source
add_executable(run_tests tests/testGhostComm.c)

# Link the test to the library so that tests work
target_link_libraries(run_tests PRIVATE ghostcomm_lib)

# Register a CTest called 'ghostCommTests'. Invokes on 'ctest' or 'make test'
add_test(NAME ghostCommTests COMMAND run_tests)