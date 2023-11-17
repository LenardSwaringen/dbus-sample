cmake_minimum_required(VERSION 3.5)

project(dbus-example)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${PROJECT_SOURCE_DIR}/out")

find_package(PkgConfig REQUIRED)
pkg_check_modules(DBUS REQUIRED dbus-1 dbus-c++-1)

set(CMAKE_CXX_STANDARD 17)

add_custom_command(OUTPUT dbus_hello_xml2cpp
        COMMAND dbusxx-xml2cpp com.sample.hello.xml --proxy=dbus_hello_proxy.h --adaptor=dbus_hello_adaptor.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}  #当前命令在当前目录下运行, 是生成的文件在当前目录下
        COMMENT "build hello xml2cpp file"
)
add_custom_target(dbus_hello_xml2cpp_task ALL DEPENDS dbus_hello_xml2cpp)

include_directories(
        /usr/include/dbus-1.0
        /usr/include/dbus-c++-1
)

add_executable(server server.cpp)
add_executable(client client.cpp)

add_dependencies(server dbus_hello_xml2cpp_task)
add_dependencies(client dbus_hello_xml2cpp_task)

target_link_libraries(server dbus-c++-1)
target_link_libraries(client dbus-c++-1)




