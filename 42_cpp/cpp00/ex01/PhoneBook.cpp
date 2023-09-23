/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:32:37 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 13:00:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::addContact(Contact contact, int i)
{
	this->contacts[i] = contact;
}

void PhoneBook::printAllContacts(void)
{
	std::string firstName{};
	std::string lastName{};
	std::string nickname{};

	std::cout << " |----------|----------|----------|----------|" << std::endl;
	std::cout << " |   Index  | FirstName| LastName | NickName |" << std::endl;
	std::cout << " |----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		firstName = this->contacts[i].getFirstName();
		lastName = this->contacts[i].getLastName();
		nickname = this->contacts[i].getNickName();
		std::cout << " |" << std::setw(10) << i + 1 << "|";
		if (firstName.length() > 10)
			std::cout << firstName.substr(0, 9) << "."
					  << "|";
		else
			std::cout << std::setw(10) << firstName << "|";
		if (lastName.length() > 10)
			std::cout << lastName.substr(0, 9) << "."
					  << "|";
		else
			std::cout << std::setw(10) << lastName << "|";
		if (nickname.length() > 10)
			std::cout << nickname.substr(0, 9) << "."
					  << "|";
		else
			std::cout << std::setw(10) << nickname << "| ";
		std::cout << "\n";
	}
	std::cout << " |----------|----------|----------|----------|"
			  << "\n\n";
}

void PhoneBook::printContact(const std::string &rep)
{
	int indeks = std::stoi(rep) - 1;
	std::cout << "\nFirst name: " << this->contacts[indeks].getFirstName() << "\n";
	std::cout << "Last name: " << this->contacts[indeks].getLastName() << "\n";
	std::cout << "NickName: " << this->contacts[indeks].getNickName() << "\n";
	std::cout << "Phone number: " << this->contacts[indeks].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << this->contacts[indeks].getDarkestSecret() << "\n";
}

bool PhoneBook::isNumber(const std::string &s)
{
	for (char c : s)
	{
		if (!isdigit(c))
			return 0;
	}
	return 1;
}

bool PhoneBook::isValidNumber(const std::string &s)
{
	int num{};
	num = std::stoi(s);
	return (num >= 1 && num <= 8);
}

bool PhoneBook::allSpaces(const std::string &s)
{
	for (size_t i{0}; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return 0;
	}
	return 1;
}


