# include <iostream>
# include <string>
# include <fstream>

#define ERROR       -1
#define SUCCESS     0

int    ft_replace( std::ifstream &ifs, char **argv, std::string filename)
{
    std::string     a  = argv[2];
    std::string     b  = argv[3];
    std::string     filename_copy = filename.append(".replace");
    std::ofstream   ofs(filename_copy.c_str(), std::ios::out | std::ios::trunc); 

    if(ofs.fail() || !ofs.is_open())
    {
        if(ofs.fail() )
            std::cerr << "Filename : " << filename_copy << " doesn't exists !" << std::endl;
        if (!ofs.is_open())
            std::cerr << "Failed to open " << filename_copy << '\n';
        return (ERROR);
    }

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
    ofs.close();
    return (SUCCESS);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Needs 3 params " << '\n';
        return (ERROR);
    }

    std::string     filename = argv[1];
    std::ifstream   ifs(filename.c_str(), std::ios::in);  

    if(ifs.fail() || !ifs.is_open() || ft_replace(ifs, argv, filename) != SUCCESS)
    {
        if(ifs.fail() )
            std::cerr << "Filename : " << filename << " doesn't exists !" << std::endl;
        if (!ifs.is_open())
            std::cerr << "Failed to open " << filename << '\n';
        return (ERROR);
    }
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    ifs.close();  
    return (SUCCESS);
}
