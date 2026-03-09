#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer &copy){
    (void)copy;
}

Serializer::~Serializer(){
}

Serializer &Serializer::operator=(const Serializer &copy){
    (void)copy;
    return (*this);
}

uintptr_t Serializer::serialize(const Data* ptr){
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(const uintptr_t raw){
    return(reinterpret_cast<Data*>(raw));
}