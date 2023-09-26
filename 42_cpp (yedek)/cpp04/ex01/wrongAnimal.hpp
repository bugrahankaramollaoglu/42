/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:18:55 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 22:34:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const& other);
	WrongAnimal& operator=(WrongAnimal const& other);
	~WrongAnimal();
public:
	void makeSound() const;
protected:
	std::string type;
};
