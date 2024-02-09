cmake_minimum_required(VERSION 3.22.1)
project(test )
set (CMAKE_CXX_COMPILER g++ )
#active le cmalist dans le ss-repertoire
add_subdirectory(Model)

add_executable( output file.cpp )

#pour faire la linkgae dans le systeme 
target_link_libraries(output PRIVATE  interactdb)

#pour specicifier les chemin des entetes pour la creation de la cible 
#target_include_directories(output PRIVATE lib lib/include )
