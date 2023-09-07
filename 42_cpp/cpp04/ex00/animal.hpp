/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:36:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 23:56:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Animal
{
protected:
	std::string type;

public:
	Animal();
	// virtual ~ demezsek freelerken hata veriyor
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

public:
	virtual void makeSound() const;
	std::string getType() const;
};
