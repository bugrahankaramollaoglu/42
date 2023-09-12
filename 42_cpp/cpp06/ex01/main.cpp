#include "Serializer.hpp"

int	main(void)
{
	Data*	data1 = new Data;
	Data*	data2;
	uintptr_t		store_data;

	data1->num = 42;
	store_data = Serializer::serialize(data1);
	data2 = Serializer::deserialize(store_data);

	std::cout << "Original pointer address and value: "
		<< data1 << " " << data1->num << std::endl;
	std::cout << "Deserialized pointer address and value: "
		<< data2 << " " << data2->num << std::endl;

	delete data1;
}