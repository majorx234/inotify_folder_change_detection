cmake_minimum_required(VERSION 3.16)

project(inotify_folder_change_detection
  DESCRIPTION "check for file changes in folder"
  VERSION 0.1.0
  LANGUAGES CXX)

include_directories(${PROJECT_INCLUDE_DIR})

set(FOLDER_WATCHER_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/folder_watcher.cpp
)

add_executable(folder_watcher)
target_sources(folder_watcher
 PRIVATE
  ${FOLDER_WATCHER_SRC}
)
