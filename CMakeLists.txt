cmake_minimum_required(VERSION 3.25)
project(SimularePlanete)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/octav/Qt/6.5.0/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(SimularePlanete main.cpp Planet.cpp Planet.h Tests.cpp Tests.h Repository.cpp Repository.h RepositoryException.cpp RepositoryException.h Service.cpp Service.h GUI.cpp GUI.h)
target_link_libraries(SimularePlanete
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

