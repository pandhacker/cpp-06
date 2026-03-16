#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data("audric", "gantaume", 21);

	std::cout << "data: " << &data << " and as exemple the name: " << data.getName() << std::endl
	<< "data serialized: " << Serializer::serialize(&data) << std::endl
	<< "data serialized and reverted: " << Serializer::deserialize(Serializer::serialize(&data)) << " and as exemple the name: " << Serializer::deserialize(Serializer::serialize(&data))->getName() << std::endl;

}