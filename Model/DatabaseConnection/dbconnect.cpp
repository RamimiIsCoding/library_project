#include "dbconnect.hpp"
Database::Database(){
    db_path = "/home/manohy/project_VS/library_project/Model/database.db";
        if ( sqlite3_open( db_path, &db) !=SQLITE_OK){
            std::cerr << "unable to connect : "<<sqlite3_errmsg(db)<<std::endl; 
            std::exit(EXIT_FAILURE);
        }
    }
Database::~Database(){
    if( db != nullptr ) sqlite3_close(db);
    sqlite3_free(NULL);
    std::cout<<"data session finished"<<std::endl;
}
bool Database::isConnected() const{return db != nullptr ;}
sqlite3* Database::get_handler(){return db;}
sqlite3_stmt* Database::get_stmt(){return stmt;}