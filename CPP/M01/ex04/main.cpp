#include <iostream>
#include <string>
#include <fstream>

#define ERROR -1

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Needs 3 params " << '\n';
        return (ERROR);
    }
    
    std::string     filename = argv[1];
    std::string     a  = argv[2];
    std::string     b  = argv[3];
    
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
    
    char c;
    size_t i;
    std::string temp;
    while(ifs.get(c))
    {
        if (c == a[0])
        {
            i = 0;
            temp.erase(temp.begin(), temp.end());
            while (i < a.size() && c == a[i])
            {
                temp.operator+=(c);
                i++;
                if (i == a.size())
                {
                    temp.operator+=("\0");
                    ofs << b;
                    break ;
                }
                ifs.get(c);
                if (c != a[i])
                {
                    temp.operator+=(c);
                    ofs << temp;
                    break ;
                }
            }
        }
        else
            ofs << c;
    }

    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    // std::cout << "A la fin de la lecture le curseur de trouve a l'octet " << ifs.tellg() << "." << std::endl;
       
    // on ferme les fichiers
    ifs.close();  
    ofs.close();

    return (0);
}
