#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.x = 42;
    data.name = "Hello Serialization";

    std::cout << "Original pointer:   " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (raw):   " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized ptr:   " << ptr << std::endl;

    if (ptr == &data)
		std::cout << "\033[32mSuccess: Pointers match!\033[0m" << std::endl;
    else
		std::cout << "\033[31mError: Pointers don't match!\033[0m" << std::endl;
    return 0;
}
