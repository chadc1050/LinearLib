cmake_minimum_required(VERSION 3.31)

SET(PROJECTNAME LinearLib)

project(${PROJECTNAME})

SET(ROOT_DIR .)

include_directories(
    ${ROOT_DIR}/include
    ${ROOT_DIR}/third-party/include
    ${ROOT_DIR}/third-party/lib/catch2
    ${ROOT_DIR}/third-party/include/catch2
)

LINK_DIRECTORIES(${ROOT_DIR}/lib)

FILE(GLOB_RECURSE PROJECT_SOURCES ${ROOT_DIR}/lib/*.cpp)

FILE(GLOB_RECURSE PROJECT_HEADERS ${ROOT_DIR}/include/*.hpp)

FILE(GLOB_RECURSE THIRD_PARTY_SOURCES ${ROOT_DIR}/third-party/lib/*.cpp)

FILE(GLOB_RECURSE THIRD_PARTY_HEADERS ${ROOT_DIR}/third-party/include/*.hpp)

set(CMAKE_CXX_STANDARD 23)

add_library(LinearLib STATIC ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${THIRD_PARTY_SOURCES}
        ${THIRD_PARTY_HEADERS})

# Enable testing
enable_testing()

# Add Catch2 main source
set(CATCH_SOURCE ${ROOT_DIR}/third-party/lib/catch2/catch_amalgamated.cpp)

FILE(GLOB_RECURSE TEST_SOURCES ${ROOT_DIR}/tests/*.cpp)

# Add test executable
add_executable(${PROJECTNAME}_Tests
    ${TEST_SOURCES}
    ${CATCH_SOURCE}
)

# Link the test executable with the main library
target_link_libraries(${PROJECTNAME}_Tests PRIVATE ${PROJECTNAME})

# Add tests to CTest
add_test(NAME ${PROJECTNAME}_Tests COMMAND ${PROJECTNAME}_Tests)

