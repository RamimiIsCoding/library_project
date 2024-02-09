# private : sqlite isn't used on other library
add_library(
    dbconnect 
        dbconnect.cpp
        dbconnect.hpp
)
target_link_libraries(dbconnect PUBLIC sqlite3)
