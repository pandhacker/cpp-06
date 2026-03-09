#ifndef SERIALIZERHPP

# define SERIALIZERHPP

# include <string>
# include "Data.hpp"
# include <stdint.h>

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();
        Serializer &operator=(const Serializer &copy);

    public:
        static uintptr_t serialize(const Data* ptr);
        static Data* deserialize(const uintptr_t raw);
};

#endif