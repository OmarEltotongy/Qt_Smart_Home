cmake_minimum_required(VERSION 3.19)
project(SmartHome LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SmartHome
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Add JSON data files as embedded resources
qt_add_resources(SmartHome "data_resources"
    PREFIX "/data"
    FILES
        Data/system_config.json
        Data/devices.json
        Data/rooms_groups.json
        Data/energy_data.json
        Data/automation_rules.json
        Data/command_queue.json
        Data/recent_commands.json

        SystemClassesHeaderFiles/json.hpp
        SystemClassesHeaderFiles/abstractFactory.hpp
        SystemClassesHeaderFiles/adapter.hpp
        SystemClassesHeaderFiles/command.hpp
        SystemClassesHeaderFiles/composite.hpp
        SystemClassesHeaderFiles/facade.hpp
        SystemClassesHeaderFiles/observer.hpp
        SystemClassesHeaderFiles/singelton.hpp
        SystemClassesHeaderFiles/state.hpp
        SystemClassesHeaderFiles/strategy.hpp

        SystemClassesSourceFiles/abstractFactory.cpp
        SystemClassesSourceFiles/adapter.cpp
        SystemClassesSourceFiles/command.cpp
        SystemClassesSourceFiles/composite.cpp
        SystemClassesSourceFiles/facade.cpp
        SystemClassesSourceFiles/observer.cpp
        SystemClassesSourceFiles/singleton.cpp
        SystemClassesSourceFiles/state.cpp
        SystemClassesSourceFiles/strategy.cpp
    )
# This line to include the QSS file as a resource (if you have it)
# qt_add_resources(SmartHome "style_resources"
#     PREFIX "/"
#     FILES "stylesheet.qss"
# )

target_link_libraries(SmartHome
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS SmartHome
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SmartHome
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
