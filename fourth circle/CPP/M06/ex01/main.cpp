#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int		i;
	char	c;
	bool	b;
    std::string    s;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data data;
	Data *ptr;
	uintptr_t raw;

	data.i = 22;
	data.c = 'A';
	data.b = true;
    data.s = "coucou";

	std::cout << data.i << std::endl;
	std::cout << data.c << std::endl;
	std::cout << data.b << std::endl;
	std::cout << data.s << std::endl;
	std::cout << "adresse de data : " << &data << std::endl;

	std::cout << "-----------------------" << std::endl;
	raw = serialize(&data);
	std::cout << &raw << std::endl;

	std::cout << "-----------------------" << std::endl;
	ptr = deserialize(raw);
	std::cout << "adresse de ptr : " << ptr << std::endl;
    
	std::cout << ptr->i << std::endl;
	std::cout << ptr->c << std::endl;
	std::cout << ptr->b << std::endl;
	std::cout << ptr->s << std::endl;


	return (0);
}