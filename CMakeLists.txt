cmake_minimum_required(VERSION 3.10)
project(App)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(src src/Application.cpp
                src/Customer.cpp
                src/Shop.cpp
                src/ShopDataBase.cpp
                src/ShopOwner.cpp
                src/User.cpp
                src/UserDataBase.cpp
)       

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME} src/main.cpp)
add_executable(${PROJECT_NAME}-ut tests/catchMain.cpp tests/tests.cpp)

set(FLAGS -Wall -Wextra -Wconversion -pedantic)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

target_link_libraries(${PROJECT_NAME} src)
target_link_libraries(${PROJECT_NAME}-ut src)
# target_include_directories(${PROJECT_NAME}-ut PRIVATE /tests/ ${CMAKE_SOURCE_DIR}/inc/)
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc/)

enable_testing()
add_test(NAME ${PROJECT_NAME}-ut COMMAND ${PROJECT_NAME}-ut)
