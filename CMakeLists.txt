cmake_minimum_required(VERSION 3.13)
project(image_processor__skeleton)
add_compile_options(-Wno-multichar)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES
        include/bitmap.h
        include/improc.hpp
        src/bitmap.c
        src/improc.cpp
        )

add_executable(image_processor__skeleton
        ${SOURCE_FILES}
        main.cpp)

set(SOURCES_FILES_TESTS
        test/test.cpp
        )

# Dodaj konfigurację typu `Test`.
add_executable(my_project_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

# Dodaj katalogi z plikami nagłówkowymi wyłącznie do konkretnej konfiguracji (tu: `Test`).
target_include_directories(my_project_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks
        )

# Dodaj podkatalog `googletest-master`.
add_subdirectory(googletest-master)

# Podlinkuj bibliotekę o identyfikatorze `gmock` (w pliku CMake) wyłącznie do konkretnej
# konfiguracji (tu: `Test`).
target_link_libraries(my_project_test gmock)