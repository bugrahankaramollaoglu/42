/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:36:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/03 02:03:37 by bkaramol         ###   ########.fr       */
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
	// destructorlara virtual koymazsak
	// delete ile silemiyoruz, memory leak oluyor
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

public:
	virtual void makeSound() const;
	std::string getType() const;
};
