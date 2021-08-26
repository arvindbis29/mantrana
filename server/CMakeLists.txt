project(mantrana_server)

set(CMAKE_CXX_STANDARD 14)

find_package(
        Qt5
        HINTS "$ENV{QTDIR}"
        REQUIRED COMPONENTS
        Core
        Network
        WebSockets
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB PROJECT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB PROJECT_STATIC "${CMAKE_CURRENT_SOURCE_DIR}/Static/*.qrc")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        ${PROJECT_HEADER}
        ${PROJECT_SOURCE}
        ${PROJECT_STATIC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTORCC TRUE)

target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Network
        Qt5::WebSockets
)

