#include "../inc/Membre.hpp"
Membre::Membre(): instance_db(new Database()){}

Membre::~Membre(){
    delete instance_db;
    db_member.clear();
}

std::vector<Person> Membre::fetch_data(){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "SELECT * FROM membre;" ;
    int row_count = sqlite3_prepare_v2( 
        instance_db->get_handler(),
        query.c_str(), 
        -1,&stmt,nullptr
        );
    while ((row_count = sqlite3_step(stmt)) == SQLITE_ROW) {
        Person temp ; // func bind 
        db_member.push_back(
            {   
                sqlite3_column_int(stmt, 0),
                std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))),
                sqlite3_column_int(stmt, 2)
            }
        );
    }
    return db_member ;
}

std::string Membre::delete_data(int id) {
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "DELETE FROM membre WHERE num_membre = ?";
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

std::string  Membre::insert_data(std::string name,int age){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "INSERT INTO membre (nom, age) VALUES (?, ?); ";
    int row_count = sqlite3_prepare_v2(instance_db->get_handler(), query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt,1,name.c_str(),-1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2,age);  
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de l'exécution de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    } else {
        std::cout << "INSERTION de ligne réussie." << std::endl;
    }
    sqlite3_finalize(stmt);
    return "insertion finished";
}

std::string  Membre::update_data(int id,std::string name,int age){
    sqlite3_stmt* stmt = instance_db->get_stmt() ;
    std::string query = "UPDATE membre SET nom = ?, age = ? WHERE num_membre = ?";
    int row_count = sqlite3_prepare_v2(instance_db->get_handler(), query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt,1,name.c_str(),-1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2,age);  
    sqlite3_bind_int(stmt, 3,id); 
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de l'exécution de la requête: " << sqlite3_errmsg(instance_db->get_handler()) << std::endl;
    } else {
        std::cout << "Suppression de ligne réussie." << std::endl;
    }
    sqlite3_finalize(stmt);
    return "update finished";  
}
