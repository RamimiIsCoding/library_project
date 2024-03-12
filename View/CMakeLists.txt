add_subdirectory(wxWidgets-3.2.4)
#include_directories(${CMAKE_SOURCE_DIR})
set(
    SRC
    
)
set(
    inc

)
add_library(
    libView
        {SRC}
        {inc}
)
target_link_libraries(libView wx::net wx::core wx::base)