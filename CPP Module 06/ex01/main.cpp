#include "main.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(Serializer &other)
{
    (void)other;
}

Serializer &Serializer::operator = (Serializer &other)
{
    (void)other;
    return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t resulte;

    resulte = reinterpret_cast<uintptr_t>(ptr);
    return (resulte);
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    Data* resulte = reinterpret_cast<Data*>(raw);
    return resulte;
}

int main()
{
    Data D, *data;
    uintptr_t U;

    D.i = 42;
    D.sh = 1337;
    D.name = "Achraf";

    std::cout << "i = " <<D.i << " | ";
    std::cout << "sh = " << D.sh << " | ";
    std::cout << "name = " << D.name << std::endl;

    U = Serializer::serialize(&D);
    data = Serializer::deserialize(U);

    std::cout << "i = " <<data->i << " | ";
    std::cout << "sh = " << data->sh << " | ";
    std::cout << "name = " << data->name << std::endl;

    if (&D == data) std::cout << "\nsame adress !\n";
}
