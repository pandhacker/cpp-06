#include "Data.hpp"

Data::Data(): _name("no name"), _firstName("no first name"), _age(0){
}

Data::Data(std::string name, std::string firstName, int age): _name(name), _firstName(firstName), _age(age){

}

Data::Data(const Data &copy): _name(copy._name), _firstName(copy._firstName), _age(copy._age){
}

Data::~Data(){
}

Data &Data::operator=(const Data &copy){
    _name = copy._name;
    _firstName = copy._firstName;
    _age = copy._age;

    return (*this);
}

int Data::operator==(const Data &compare) const{
    if (_age == compare._age && _name == compare._name && _firstName == compare._firstName)
        return (1);
    return (0);
}


std::string Data::getName() const{
    return (_name);
}

std::string Data::getFisrtName() const{
    return (_firstName);
}

int Data::getAge() const{
    return(_age);
}


void Data::setName(const std::string name){
    _name = name;
}

void Data::setFisrtName(const std::string firstName){
    _firstName = firstName;
}

void Data::setAge(const int age){
    _age = age;
}
