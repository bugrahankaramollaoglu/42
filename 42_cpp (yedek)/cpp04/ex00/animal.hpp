/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:36:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 14:21:05 by bkaramol         ###   ########.fr       */
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
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

public:
	// subject bu fonksiyonun virtual olmasını istiyor, virtual yazmasak da
	// dog ve cat kendi getType() ve makeSound() fonksiyonlarını cagırıyorlar
	// normalde basedeki bir fonksiyonu derivedlarda override edebilmek icin virtual
	// tanımlıyoruz am c++98'de override olmadıgından dog ve cat sınıflarında bu fonksiyonu
	// yeniden yazar gibi yaziyoruz.
	virtual void makeSound() const;
	std::string getType() const;
};