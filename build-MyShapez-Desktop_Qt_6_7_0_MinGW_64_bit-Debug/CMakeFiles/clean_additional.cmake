# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyShapez_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyShapez_autogen.dir\\ParseCache.txt"
  "MyShapez_autogen"
  )
endif()
