#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream   ifs("filename");
    std::string    s1;
    std::string    s2;

    ifs >> s1 >> s2;

   // std::cout << s1 << " " << s2 << std::endl;
    ifs.close();

    std::ofstream  ofs("filename.replace");
   // ofs << s1 << " " << s2 << std::endl;
    return (0);
}