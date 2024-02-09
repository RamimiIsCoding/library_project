#include "../inc/Document.hpp"
Document::Document(): instance_db(new Database()){}

Document::~Document(){
    delete instance_db;
    db_doc.clear();
}

std::vector<Doc> Document::fetch_data(){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "SELECT * FROM document;" ;
    int row_count = sqlite3_prepare_v2( 
        instance_db->get_handler(),
        query.c_str(), 
        -1,&stmt,nullptr
        );
    while ((row_count = sqlite3_step(stmt)) == SQLITE_ROW) {
        db_doc.push_back(
            {   
                sqlite3_column_int(stmt, 0),
                std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))),
            }
        );
    }
    return db_doc ;
}

std::string Document::delete_data(int id) {
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "DELETE FROM document WHERE num_document = ?";
    int rc = sqlite3_prepare_v2(instance_db->get_handler(), query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur lors de la préparation de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    }
    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur lors de l'exécution de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    } 
    sqlite3_finalize(stmt);       
        return ("Suppression réussie de = " + std::to_string(id));
}

std::string  Document::insert_data(std::string title){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "INSERT INTO Document (titre) VALUES (?); ";
    int row_count = sqlite3_prepare_v2(instance_db->get_handler(), query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt,1,title.c_str(),-1, SQLITE_STATIC);
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de l'exécution de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    } else {
        std::cout << "INSERTION de ligne réussie." << std::endl;
    }
    sqlite3_finalize(stmt);
    return "insertion finished";
}

std::string  Document::update_data(int id,std::string title){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "UPDATE Document SET titre = ? WHERE num_document = ?";
    int row_count = sqlite3_prepare_v2(instance_db->get_handler(), query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt,1,title.c_str(),-1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2,id); 
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de l'exécution de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    } else {
        std::cout << "Suppression de ligne réussie." << std::endl;
    }
    sqlite3_finalize(stmt);
    return "update finished";  
}
