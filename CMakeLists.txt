cmake_minimum_required(VERSION 2.8)

project(glut-demo)
add_executable(glut-demo src/demo.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(catkin REQUIRED COMPONENTS  rosbag roscpp )

#include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} )
#target_link_libraries(glut-demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}  ${catkin_LIBRARIES})

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
target_link_libraries(glut-demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )




#catkin_package(
#  CATKIN_DEPENDS rosbag roscpp 
#)
