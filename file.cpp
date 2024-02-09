#include "./Model/inc/Membre.hpp"
#include "./Model/inc/Document.hpp"
namespace View{
   class UI{
      private :
         int choice ;
      public:
         UI(){
            std::cout<<"choisir eentre les choix suivant  = " <<std::endl;
            std::cout<<" 1 - recuperer donnée " <<std::endl ; 
            std::cout<<" 2 - modifier  donnée " <<std::endl ; 
            std::cout<<" 3 - inserer donnée " <<std::endl ; 
            std::cout<<" 4 - supprimer donnée " <<std::endl ; 
            std::cout<< " entrer votre choix = " ;
            std::cin >> this->choice ;
         }
         int send_value(){
            return this->choice;
         }
         void output(std::string val_ret){
            std::cout<<val_ret<<std::endl; ;
         }
   };
}

namespace Controller{
    class parse{
      private :
         std::vector<Person> cache;  
      public :
         parse(View::UI* instance_UI,Membre* interface){
            instance_UI = new View::UI() ;
            interface = new Membre();
            switch (instance_UI->send_value())
            {
                  case 1 :
                        cache = interface->fetch_data();
                        for (int i = 0 ; i<cache.size(); i++) 
                        std::cout << "ID: " << cache[i].id << ", Name: " << cache[i].name << ", age= "<< cache[i].age << std::endl;
                     break;
                  case 2 :
                        instance_UI->output(interface->update_data(6,"Jules cesar",23));
                     break;
                  case 3 : 
                        instance_UI->output(interface->insert_data("MANOHY",22));
                     break;
                  case 4 :
                        instance_UI->output(interface->delete_data(1));
                     break;
                  default:
                     break;
            }
               delete instance_UI ;
               delete interface;
            }
            ~parse(){
               cache.clear();
               
            }
           // instance_db->store(instance_UI->send_value());
           // instance_UI->output(instance_db->fetch_data());
   };   
}
int main(){

   // Membre* test;
   // View::UI* instance_UI;
   // Controller::parse lol(instance_UI,test);
   Document* test = new Document;
   test->update_data(4,"les Compte de monte cristo");
   std::vector<Doc> cache = test->fetch_data();
   for (int i = 0 ; i<cache.size(); i++) 
                        std::cout << "ID: " << cache[i].id << ", Name: " << cache[i].title << std::endl;
   return 0;
}