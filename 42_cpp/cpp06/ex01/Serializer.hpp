/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:02:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 21:10:52 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Serializer_HPP_
#define _Serializer_HPP_

#include <iostream>

struct Data
{
	int age;
	std::string name;
};

class Serializer
{
public:
	Serializer();
	Serializer(Serializer const &obj);
	~Serializer();
	Serializer &operator=(const Serializer &obj);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
