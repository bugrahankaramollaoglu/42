/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:02:26 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 21:03:00 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer : Default Constructor Called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer : Destructor Called" << std::endl;
}

Serializer::Serializer(Serializer const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	(void)obj;
	return (*this);
}

/* ------------------------------------------------------------------- */

/* uintptr_t is an unsigned integer type that holds the value of a pointer.
often used in low-level programming when you need to manipulate raw memory
addresses, perform pointer arithmetic, or perform operations that require
treating pointers as integers */
uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}
