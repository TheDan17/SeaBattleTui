cmake_minimum_required(VERSION 3.26)
project(PractProj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -static-libgcc -static-libstdc++ -std=c++17")

add_executable(PractProj main.cpp

        tool/stack.cpp
        tool/stack.h
        tool/string/strings_data.cpp
        tool/string/strings_data.h
        tool/string/mng_string.cpp
        tool/string/mng_string.h

        core/core_cpp/TaskManager.cpp
        core/core_h/TaskManager.h
        core/interface/interface_cpp/units.cpp
        core/interface/interface_h/elements.h
        core/interface/interface_cpp/screen_converter.cpp
        core/interface/interface_h/screen_converter.h

        core/core_cpp/concept.cpp
        core/core_h/concept.h
        core/core_h/global_config.h
        tool/array/array.cpp
        tool/array/array.h

        core/interface/interface_cpp/consoleManager.cpp
        core/interface/interface_h/consoleManager.h
        core/interface/interface_h/colors.h
        core/interface/units/units.h
        core/interface/interface_cpp/bufferManager.cpp
        core/interface/interface_h/bufferManager.h
        core/core_cpp/audio.cpp
        core/core_h/audio.h
        tool/order.cpp
        tool/order.h
        core/interface/units/units_cpp/Layer.cpp
        core/interface/units/units_h/Layer.h
        core/interface/units/units_cpp/Element.cpp
        core/interface/units/units_h/Element.h
        core/core_cpp/global_config.cpp
        core/interface/interface_cpp/debug.cpp
        core/interface/interface_h/debug.h
        core/interface/units/units_cpp/staticList.cpp
        core/interface/units/units_h/staticList.h
        core/interface/units/units_cpp/InteractList.cpp
        core/interface/units/units_h/InteractList.h
        tool/tools.h
        core/core_cpp/data.cpp
        core/core_h/data.h
        tool/string/str.cpp
        tool/string/str.h
        core/interface/interface_cpp/statusManager.cpp
        core/interface/interface_h/statusManager.h
        core/interface/units/units_cpp/taskList.cpp
        core/interface/units/units_h/taskList.h
        core/interface/units/units_cpp/GameField.cpp
        core/interface/units/units_h/GameField.h
        core/interface/units/units_cpp/Text.cpp
        core/interface/units/units_h/Text.h
        core/interface/units/units_cpp/ShipPattern.cpp
        core/interface/units/units_h/ShipPattern.h
        core/interface/units/units_cpp/Status.cpp
        core/interface/units/units_h/Status.h
)
target_link_libraries(PractProj PUBLIC
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        winMM.Lib)