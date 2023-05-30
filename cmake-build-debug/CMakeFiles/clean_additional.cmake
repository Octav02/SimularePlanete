# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SimularePlanete_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SimularePlanete_autogen.dir/ParseCache.txt"
  "SimularePlanete_autogen"
  )
endif()
