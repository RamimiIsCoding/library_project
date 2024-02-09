#include "module.hpp"
#include "test.hpp"
#include <sqlite3.h>
#include <vector>

namespace Model{

   struct Person {
    int id;
    std::string name;
    int age;
   };

   class Database {
      private :
         //int database ;
         sqlite3* db ;
         sqlite3_stmt* stmt;
         const char* db_path ; 
      public :
         Database(){
               db_path = "/home/manohy/project_VS/library_project/database.db";
               if ( sqlite3_open( db_path, &db) !=SQLITE_OK){
                  std::cerr << "unable to connect : "<<sqlite3_errmsg(db)<<std::endl; 
                  std::exit(EXIT_FAILURE);
               }
         }
         ~Database(){
            if( db != nullptr ){
               sqlite3_close(db);
            }
            sqlite3_free(NULL);
            std::cout<<"data session finished"<<std::endl;
         }
         bool isConnected() const{
            return db != nullptr ;
         }

         //std::vector<Person>
         void fetch_data(const char* query){
            int row_count = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
            std::vector<Person> people;
            while ((row_count = sqlite3_step(stmt)) == SQLITE_ROW) {
                people.push_back(
                     {
                        sqlite3_column_int(stmt, 0),
                        std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))),
                        sqlite3_column_int(stmt, 2)
                     }
               );
            }
            for (int i = 0 ; i<people.size(); i++) 
                  std::cout << "ID: " << people[i].id << ", Name: " << people[i].name << ", age= "<< people[i].age << std::endl;
            people.clear();
         }
         void delete_data() {
            std::string query = "DELETE from membre WHERE num_membre=1;";
         }
      };

   enum camera_state  {sleep,scan,end};

   class ESP32{
      private :
         camera_state value ;
      public :
         ESP32(){
            value = sleep ;
         }
         camera_state start_scan(){
            std::cout<<"start scanning ..."<<std::endl;
            value = scan ;
            return value ;
         }
         camera_state end_scanning(){
            std::cout<<"end scanning : return data to controler"<<std::endl;
            value = end ;
            return value ;
         }
         ~ESP32(){
            value = sleep;
         }
   };
}
namespace View{
   class UI{
      private :
         int input ;
      public:
         UI(){
            std::cout<<"entrer data from VIEW = ";
            std::cin>>this->input;
            std::cout<<"input succesfull"<<std::endl;
         }
         int send_value(){
            return input ;
         }
         void output(int val_ret){
            std::cout<<val_ret<<std::endl; ;
         }
   };
}

// namespace Controller{
//    class parse{
//       private :
//          int temp_data ;
//       public :
//          parse(Model::Database* instance_db , View::UI* instance_UI){
//             instance_UI = new View::UI() ;
//             instance_db = new Model::Database() ;
//            // instance_db->store(instance_UI->send_value());
//             instance_UI->output(instance_db->fetch_data());
//          }
//    };   
// }
int main(){
   // std::cout<<"hello from linua"<<std::endl ;
   // func();
   // test_mod();
   // etudiant test ;
   // test.out();
   // Model::Database* database;
   // View::UI* UI;
   // Controller::parse instance(database,UI);
   Model::Database database;
   if (database.isConnected()) {
      database.fetch_data("SELECT * FROM membre;");
      database.delete_data();
       
   }
   return 0;
}