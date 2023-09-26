/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:02:40 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 21:10:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data;

	data->name = "achraf";
	data->age = 30;

	std::cout << "Name: " << Serializer::deserialize(Serializer::serialize(data))->name << std::endl;
	std::cout << "Age: " << Serializer::deserialize(Serializer::serialize(data))->age << std::endl;

	delete data;

	std::cout << "\n";

	Data deneme;
	deneme.age = 22;
	deneme.name = "bugra";
	std::cout << deneme.age << "\n";
	std::cout << deneme.name << "\n";
}
