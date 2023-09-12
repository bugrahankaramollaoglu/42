/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:18:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 12:18:44 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) { (void) copy; }

Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void) rhs;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}
