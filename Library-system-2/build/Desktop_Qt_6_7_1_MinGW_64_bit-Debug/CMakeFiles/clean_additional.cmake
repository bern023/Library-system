# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Library-system-2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Library-system-2_autogen.dir\\ParseCache.txt"
  "Library-system-2_autogen"
  )
endif()
