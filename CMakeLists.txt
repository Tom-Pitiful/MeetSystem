cmake_minimum_required(VERSION 3.5) #cmake最低版本
project(KernelMeet VERSION 1.0.0 LANGUAGES CXX)#项目名称，版本，语言
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_PATH "D:/Software/Qt/6.2.4/mingw_64")#QT套件的位置
set(CMAKE_PREFIX_PATH ${QT_PATH}/lib/cmake)#Qt自带的cmake
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)#设置可执行文件生成的目录

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Gui)#CMake尝试查找并加载Qt6,同时CMake加载Widgets模块
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Gui)

#将源码等文件放入src中
include_directories(${PROJECT_SOURCE_DIR}/include)#包含include下的头文件
file(GLOB_RECURSE HEAD_FILE ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)#匹配所有的h文件
file(GLOB_RECURSE SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)#匹配所有的CPP文件
file(GLOB_RECURSE FORMS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.ui)#匹配所有的ui文件
file(GLOB_RECURSE RESOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.qrc)#匹配所有的qrc文件


add_executable(${PROJECT_NAME} ${HEAD_FILE} ${SOURCE_FILE} ${FORMS_FILE} ${RESOURCE_FILE}) 

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Gui)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
