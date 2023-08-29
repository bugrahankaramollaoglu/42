/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:43:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 10:43:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
public:
	Contact()
	{
		this->firstName = "";
		this->lastName = "";
		this->nickName = "";
		this->phoneNumber = "";
		this->darkestSecret = "";
	};

	void applyFirstName(std::string firstName);
	std::string getFirstName();

	void applyLastName(std::string lastName);
	std::string getLastName();

	void applyNickName(std::string nickName);
	std::string getNickName();

	void applyPhoneNumber(std::string phoneNumber);
	std::string getPhoneNumber();

	void applyDarkestSecret(std::string darkestSecret);
	std::string getDarkestSecret();

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
