cmake_minimum_required(VERSION 3.19)
project(SmartHome LANGUAGES CXX)

# Find Qt6
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# Standard setup for Qt project
qt_standard_project_setup()

# Application target
qt_add_executable(SmartHome
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    # Core system
    src/core/SmartHomeController_Singelton.cpp
    src/core/SmartHomeController_Singelton.hpp
    src/core/SmartHomeFacade.cpp
    src/core/SmartHomeFacade.hpp
    src/core//SysemStatus.cpp
    src/core/SystemStatus.hpp
    src/core/SystemSummary.hpp
    src/core/SystemSummary.cpp

    # Devices
    src/devices/Device.hpp
    src/devices/Device.cpp
    src/devices/Light.hpp
    src/devices/Light.cpp
    src/devices/LEDLight.hpp
    src/devices/LEDLight.cpp
    src/devices/HalogenLight.hpp
    src/devices/HalogenLight.cpp
    src/devices/Thermostat.hpp
    src/devices/Thermostat.cpp
    src/devices/SmartThermostatA.hpp
    src/devices/SmartThermostatA.cpp
    src/devices/SmartThermostatB.hpp
    src/devices/SmartThermostatB.cpp
    src/devices/SecurityCamera.hpp
    src/devices/SecurityCamera.cpp
    src/devices/WiredCamera.hpp
    src/devices/WiredCamera.cpp
    src/devices/DoorLock.hpp
    src/devices/DoorLock.cpp
    src/devices/MotionSensor.hpp
    src/devices/MotionSensor.cpp

    # Device states
    src/devices/states/DeviceState.hpp
    src/devices/states/DeviceState.cpp
    src/devices/states/OfflineState.hpp
    src/devices/states/OfflineState.cpp
    src/devices/states/OffState.hpp
    src/devices/states/OffState.cpp
    src/devices/states/OnState.hpp
    src/devices/states/OnState.cpp
    src/devices/states/TransitioningState.hpp
    src/devices/states/TransitioningState.cpp
    src/devices/states/DimmingState.hpp
    src/devices/states/DimmingState.cpp

    # Factories
    src/factories/DeviceFactory.hpp
    src/factories/DeviceFactory.cpp
    src/factories/PhilipsFactory.hpp
    src/factories/PhilipsFactory.cpp
    src/factories/GoogleNestFactory.hpp
    src/factories/GoogleNestFactory.cpp
    src/factories/RingFactory.hpp
    src/factories/RingFactory.cpp
    src/factories/LegacyDeviceFactory.hpp
    src/factories/LegacyDeviceFactory.cpp

    # Groups
    src/groups/DeviceComponent.hpp
    src/groups/DeviceComponent.cpp
    src/groups/DeviceGroup.hpp
    src/groups/DeviceGroup.cpp
    src/groups/RoomGroup.hpp
    src/groups/RoomGroup.cpp
    src/groups/FloorGroup.hpp
    src/groups/FloorGroup.cpp
    src/groups/FunctionalGroup.hpp
    src/groups/FunctionalGroup.cpp

    # Commands
    src/commands/Command.hpp
    src/commands/Command.cpp
    src/commands/DeviceCommand.hpp
    src/commands/DeviceCommand.cpp
    src/commands/TurnOnCommand.hpp
    src/commands/TurnOnCommand.cpp
    src/commands/TurnOffCommand.hpp
    src/commands/TurnOffCommand.cpp
    src/commands/SetBrightnessCommand.hpp
    src/commands/SetBrightnessCommand.cpp
    src/commands/GroupCommand.hpp
    src/commands/GroupCommand.cpp
    src/commands/ScenarioCommand.hpp
    src/commands/ScenarioCommand.cpp
    src/commands/CommandQueue.hpp
    src/commands/CommandQueue.cpp

    # Events
    src/events/Event.hpp
    src/events/Event.cpp
    src/events/Observer.hpp
    src/events/DeviceObserver.hpp
    src/events/DeviceObserver.cpp
    src/events/AutomationObserver.hpp
    src/events/AutomationObserver.cpp
    src/events/EventBus.hpp
    src/events/EventBus.cpp

    # Automation
    src/automation/AutomationEngine.hpp
    src/automation/AutomationEngine.cpp
    src/automation/AutomationStrategy.hpp
    src/automation/AutomationStrategy.cpp
    src/automation/ComfortModeStrategy.hpp
    src/automation/ComfortModeStrategy.cpp
    src/automation/EnergySavingStrategy.hpp
    src/automation/EnergySavingStrategy.cpp
    src/automation/AwayModeStrategy.hpp
    src/automation/AwayModeStrategy.cpp
    src/automation/SleepModeStrategy.hpp
    src/automation/SleepModeStrategy.cpp
    src/automation/AutomationRule.hpp
    src/automation/AutomationRule.cpp
    src/automation/Action.cpp
    src/automation/Action.hpp
    src/automation/Condition.cpp
    src/automation/Condition.hpp
    src/automation/Trigger.cpp
    src/automation/Trigger.hpp

    # Integration
    src/integration/DeviceIntegrator.hpp
    src/integration/DeviceIntegrator.cpp
    src/integration/NativeIntegrator.hpp
    src/integration/NativeIntegrator.cpp
    src/integration/LegacyDeviceAdapter.hpp
    src/integration/LegacyDeviceAdapter.cpp
    src/integration/LegacyDevice.hpp
    src/integration/LegacyDevice.cpp

    # Management
    src/management/DeviceRegistry.hpp
    src/management/DeviceRegistry.cpp
    src/management/GroupManager.hpp
    src/management/GroupManager.cpp

    # Common
    src/common/json.hpp
    src/common/IntegrationTypes.hpp
    src/common/DeviceTypes.hpp
    src/common/GroupTypes.hpp
    src/common/EventTypes.hpp
    src/common/CommandStatus.hpp
    src/common/Priority.hpp
    src/common/CameraTypes.hpp
    src/common/LightTypes.hpp
    src/common/LockTypes.hpp
    src/common/SensorTypes.hpp
    src/common/ThermostatTypes.hpp

)

# JSON & config resources
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
)

# Optional: stylesheet
# qt_add_resources(SmartHome "style_resources"
#     PREFIX "/"
#     FILES "stylesheet.qss"
# )

# Include paths
target_include_directories(SmartHome PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link with Qt
target_link_libraries(SmartHome
    PRIVATE
        Qt::Core
        Qt::Widgets
)

# Install rules
include(GNUInstallDirs)

install(TARGETS SmartHome
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install headers
install(DIRECTORY src/ DESTINATION include/SmartHome
    FILES_MATCHING PATTERN "*.h"
)

# Deployment script
qt_generate_deploy_app_script(
    TARGET SmartHome
    OUTPUT_SCRIPT deploy_script
)
install(SCRIPT ${deploy_script})
