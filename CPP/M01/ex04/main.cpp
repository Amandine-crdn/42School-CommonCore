#include <iostream>
#include <string>
#include <fstream>
//std::ios_base
int main()
{
    std::string     filename = "test.txt";
    std::string     s1;
    std::string     s2;
    
    // on ouvre le fichier en lecture //c_str pour les extensions
    std::ifstream   ifs(filename.c_str(), std::ios::in);  
    //gerer erreur exist et open
    if(ifs.fail())
    {
        if (ifs.fail())
            std::cerr << "Filename : " << filename << " doesn't exists !" << std::endl;
        return (-1);
    }
    if (!ifs.is_open())
        std::cerr << "Failed to open " << filename << '\n';

    std::string     filename_copy = filename.append(".replace");
    // on ouvre le fichier en ecriture et on efface s'il ya du contenu
    std::ofstream   ofs(filename_copy.c_str(), std::ios::out | std::ios::trunc); 
     //gerer erreur exist et open
    if(ofs.fail())
    {
        if (ofs.fail())
            std::cerr << "Filename : " << filename_copy << " doesn't exists !" << std::endl;
        return (-1);
    }
    if (!ofs.is_open())
        std::cerr << "Failed to open " << filename_copy << '\n';
    
    while(std::getline(ifs, s1)) //proteger ?
    {
        if (ifs.tellg() >= 0) // pour gerer le \n du getline a la fin du fichier
            ofs << s1 << std::endl; 
        else
            ofs << s1;
    }
    // std::cout << "Durant la lecture le curseur de trouve a l'octet " << ifs.tellg() << "." << std::endl;
    //apres lecture revenir en haut du fichier
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    // std::cout << "A la fin de la lecture le curseur de trouve a l'octet " << ifs.tellg() << "." << std::endl;
       
    // on ferme les fichiers
    ifs.close();  
    ofs.close();

    return (0);
}