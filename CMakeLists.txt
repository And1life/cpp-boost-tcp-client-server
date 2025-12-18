cmake_minimum_required(VERSION 3.10)  
project(boost_asio_tcp_example)  


set(CMAKE_CXX_STANDARD 11)


find_package(Boost 1.66 REQUIRED COMPONENTS system)


add_executable(server
    apps/server_app.cpp  
    src/server.cpp       
)


target_link_libraries(server PRIVATE Boost::system)


target_include_directories(server PRIVATE include)
