#ifndef DATAHPP

# define DATAHPP

# include <string>

class Data{
    private:
        std::string _name;
        std::string _firstName;
        int         _age;

    public:
        Data();
        Data(std::string name, std::string firstName, int age);
        Data(const Data &copy);
        ~Data();
        Data &operator=(const Data &copy);
        int operator==(const Data &compare) const;

        std::string getName() const;
        std::string getFisrtName() const;
        int getAge() const;

        void setName(const std::string name);
        void setFisrtName(const std::string firstName);
        void setAge(const int age);
};

#endif