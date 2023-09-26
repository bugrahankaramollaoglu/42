/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:13:47 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/24 14:36:52 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];

public:
	PhoneBook()
	{
		for (int i = 0; i < 8; i++)
			this->contacts[i] = Contact();
	};
	void addContact(Contact contact, int i);
	void printAllContacts();
	void printContact(const std::string &rep);
	bool isNumber(const std::string &s);
	bool isValidNumber(const std::string &s);
	bool allSpaces(const std::string &s);
	int my_stoi(const std::string &str); // 98de stoi yasak
};

#endif
