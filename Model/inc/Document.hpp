#ifndef __DOCUMENT__
#define __DOCUMENT__
   #include <vector> 
   #include "../DatabaseConnection/dbconnect.hpp"
   struct Doc {
      int id ;
      std::string title;
   };
   class Document {
      private : 
         std::vector<Doc> db_doc ; 
         Database* instance_db;
      public :
         Document();
         ~Document();
         std::vector<Doc> fetch_data();
         std::string delete_data(int id) ;
         std::string  insert_data(std::string title);
         std::string  update_data(int id,std::string title);
   };
#endif