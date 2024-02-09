#ifndef __MEMBRE__
#define __MEMBRE__
   #include <vector> 
   #include "../DatabaseConnection/dbconnect.hpp"
   struct Person {
      int id ;
      std::string name;
      int age ;
   };
   class Membre {
      private : 
         std::vector<Person> db_member ; 
         Database* instance_db;
      public :
         Membre();
         ~Membre();
         std::vector<Person> fetch_data();
         std::string delete_data(int id) ;
         std::string  insert_data(std::string name,int age);
         std::string  update_data(int id,std::string name,int age);
   };
#endif