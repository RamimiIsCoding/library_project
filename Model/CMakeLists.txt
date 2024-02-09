add_subdirectory(DatabaseConnection)
set (SRC 
    src/Membre.cpp
    src/Document.cpp
)
set(inc
    inc/Membre.hpp
    inc/Document.hpp
)
add_library (
    interactdb
    ${SRC}
    ${inc}
)
target_link_libraries(interactdb PUBLIC  dbconnect)
