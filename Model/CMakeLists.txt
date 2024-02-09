add_subdirectory(DatabaseConnection)
set (SRC 
    src/Membre.cpp
)
set(inc
    inc/Membre.hpp
)
add_library (
    interactdb
    ${SRC}
    ${inc}
)
target_link_libraries(interactdb PUBLIC  dbconnect)
