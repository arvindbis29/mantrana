project (mantrana_client)

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC_SEARCH_PATHS)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (
    Qt5
    HINTS "$ENV{QTDIR}"
    REQUIRED COMPONENTS
    Core
    Widgets
    Network
    WebSockets
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB PROJECT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB PROJECT_WINDOW_UI "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")
file(GLOB PROJECT_STATIC "${CMAKE_CURRENT_SOURCE_DIR}/Static/*.qrc")

set(GUI_TYPE)
if (WIN32)
    set(GUI_TYPE WIN32)
else ()
    set(GUI_TYPE)
endif ()

add_executable(
        ${PROJECT_NAME}
        ${GUI_TYPE} main.cpp
        ${PROJECT_SOURCE}
        ${PROJECT_HEADER}
        ${PROJECT_WINDOW_UI}
        ${PROJECT_STATIC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOUIC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTORCC TRUE)

target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Widgets
        Qt5::Network
        Qt5::WebSockets
)
