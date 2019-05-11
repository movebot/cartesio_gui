
find_package(catkin REQUIRED COMPONENTS roscpp cartesian_interface urdf)
find_package(Eigen3 REQUIRED)

add_executable(joy_gui src/joy_gui/main.cpp 
                       src/joy_gui/joygui_backend.cpp 
                       src/joy_gui/ui/qml.qrc)
                       
target_compile_definitions(joy_gui PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(joy_gui PRIVATE Qt5::Core Qt5::Quick ${catkin_LIBRARIES})
target_include_directories(joy_gui PRIVATE ${catkin_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS} src/joy_gui)