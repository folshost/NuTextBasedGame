set(CMAKE_CXX_STANDARD 11)

project(NuTextBasedGame)

add_executable(NuTextBasedGame 
  main.cpp 
  Env.cpp 
  Room.cpp 
  Item.cpp 
  Player.cpp 
  helper.cpp
  file_helper.cpp
  header/Env.h
  header/file_helper.h
  header/helper.h
  header/Item.h
  header/Player.h
  header/Room.h
  header/Saves.h
)
