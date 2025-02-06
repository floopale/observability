#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "observability_library::observability_library" for configuration ""
set_property(TARGET observability_library::observability_library APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(observability_library::observability_library PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libobservability_library.a"
  )

list(APPEND _cmake_import_check_targets observability_library::observability_library )
list(APPEND _cmake_import_check_files_for_observability_library::observability_library "${_IMPORT_PREFIX}/lib/libobservability_library.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
