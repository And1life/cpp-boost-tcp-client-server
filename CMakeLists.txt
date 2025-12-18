cmake_minimum_required(VERSION 3.10)  
project(boost_asio_tcp_example)  

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

set(CMAKE_CXX_STANDARD 11)


find_package(Boost 1.66 REQUIRED COMPONENTS system)


add_executable(server
    apps/server_app.cpp  
    src/server.cpp       
)


target_link_libraries(server PRIVATE Boost::system)
target_include_directories(server PRIVATE include)


add_executable(client
    apps/client_app.cpp  
    src/client.cpp       
)

target_link_libraries(client PRIVATE Boost::system)
target_include_directories(client PRIVATE include)
