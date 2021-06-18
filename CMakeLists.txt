cmake_minimum_required(VERSION 3.19)
project(ProyectoII_LetsPlay)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "-DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(UI Forms/puzzlewindow.ui)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        Sources/gpsettings.cpp
        Headers/gpsettings.h
        Sources/gpsettings.ui
        Sources/main.cpp
        Sources/ballwindowsettings.cpp
        Headers/mainwindow.h
        Sources/mainwindow.ui
        Sources/main.cpp
        Sources/PuzzlePiece.cpp
        Headers/PuzzlePiece.h
        Sources/PuzzleGrid.cpp
        Headers/PuzzleGrid.h
        Headers/Direction.h
        Sources/GeneticSolver.cpp
        Headers/GeneticSolver.h
        Sources/Chromosome.cpp
        Headers/Chromosome.h
        Sources/puzzlewindow.cpp
        Headers/puzzlewindow.h
        Sources/puzzlewindow.ui
        Sources/bpsettings.cpp
        Sources/bpsettings.ui
        Headers/bpsettings.h
        Sources/ballwindowsettings.cpp
        Sources/ballwindowsettings.ui
        Headers/ballwindowsettings.h
        Sources/mainwindow.cpp
        Headers/ball.h
        Sources/ball.cpp
        Headers/BoardManger.h
        Sources/BoardManger.cpp
        Headers/ConectionManager.h
        Sources/ConectionManager.cpp
        Headers/player.h
        Sources/player.cpp
        Sources/foosballwindow.cpp Headers/foosballwindow.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS Network ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network ${REQUIRED_LIBS_QUALIFIED})
