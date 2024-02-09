#ifndef __DBCONNECT__
#define __DBCONNECT__
    #include <sqlite3.h>
    #include <iostream>
    class Database {
      private :
         //int database ;
         sqlite3* db ;
         sqlite3_stmt* stmt;
         const char* db_path ; 
      public :
         Database();
         ~Database();
         bool isConnected() const;
         sqlite3* get_handler();
         sqlite3_stmt* get_stmt();
   };
#endif