cmake_minimum_required(VERSION 2.6)
project(rakauthserver)
set(CMAKE_CXX_FLAGS " -D_ELPP_THREAD_SAFE=1 -D_ELPP_DEBUG_ERRORS=1 -D_ELPP_STACKTRACE_ON_CRASH=1 -D_ELPP_FORCE_USE_STD_THREAD=1 -D_ELPP_LOGGING_FLAGS_FROM_ARG=1 -std=gnu++11 -lodb-pgsql -lodb -lpq -lcrypto -lpthread -lrt")

include_directories ("Deps/Rak-Net-libcat/Source/")
include_directories ("Deps/libodb-2.3.0/")
include_directories ("Deps/libodb-pgsql-2.3.0/")
include_directories ("Deps/openssl/include/")

file(GLOB files "*.cpp" "*.c" "*.a" "*.cxx")

add_executable(rakauthserver ${files})
target_link_libraries(rakauthserver ${CMAKE_SOURCE_DIR}/libraknetcat.a)

install(TARGETS rakauthserver RUNTIME DESTINATION bin)
