/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:43:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 13:02:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact()
	{
		this->firstName = "";
		this->lastName = "";
		this->nickName = "";
		this->phoneNumber = "";
		this->darkestSecret = "";
	};

public:
	void setFirstName(std::string firstName);
	std::string getFirstName();

	void setLastName(std::string lastName);
	std::string getLastName();

	void setNickName(std::string nickName);
	std::string getNickName();

	void setPhoneNumber(std::string phoneNumber);
	std::string getPhoneNumber();

	void setDarkestSecret(std::string darkestSecret);
	std::string getDarkestSecret();
};

#endif
