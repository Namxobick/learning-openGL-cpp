cmake_minimum_required(VERSION 3.25)
project(learning_openGL)

set(CMAKE_CXX_STANDARD 23)


include_directories(${CMAKE_SOURCE_DIR}/directories/glfw/3.3.8)
include_directories(${CMAKE_SOURCE_DIR}/directories/glew/2.2.0_1)


add_executable(${PROJECT_NAME}
        main.cpp
        Game/Logic/source/Game.cpp Game/Logic/include/Game.h
        Game/Logic/source/Map.cpp Game/Logic/include/Map.h
        Game/GUI/source/CellGUI.cpp Game/GUI/include/CellGUI.h
        Game/GUI/source/MineGUI.cpp Game/GUI/include/MineGUI.h
        Game/GUI/source/GameGUI.cpp Game/GUI/include/GameGUI.h
        Game/Logic/source/Cell.cpp Game/Logic/include/Cell.h
        Game/GUI/source/NumberDrawer.cpp Game/GUI/include/NumberDrawer.h
        Game/GUI/source/MouseButtonHandler.cpp Game/GUI/include/MouseButtonHandler.h
        Game/GUI/source/FlagGUI.cpp Game/GUI/include/FlagGUI.h)


find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARY})

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_gl_LIBRARY} glfw)

find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLEW_LIBRARY})
