/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:13:47 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/29 13:15:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
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

private:
	Contact contacts[8];
};

#endif
