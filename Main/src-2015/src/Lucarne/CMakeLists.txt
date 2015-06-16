cmake_minimum_required(VERSION 2.6)
project(Lucarne)

ADD_EXECUTABLE(Lucarne
  main.cpp 
  script.cpp 
  script.h
  tilemap.cpp
  tilemap.h
  entity.cpp
  entity.h
  background.cpp
  background.h
  physics.cpp
  physics.h
  ./scripts/coin.lua
  ./scripts/player.lua
  ./scripts/ennemy.lua
  ./scripts/level.lua
)
  
TARGET_LINK_LIBRARIES(Lucarne common ${LIBSL_LIBRARIES} ${LIBSL_GL_LIBRARIES} lua luabind Box2D)

AUTO_BIND_SHADERS( ${SHADERS} )
 