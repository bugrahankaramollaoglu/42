/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:14:13 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 09:52:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook pb;
	std::string reply;

	int i = 0;
	int contactNum = 0;

	while (1)
	{
	labelSTART:

		std::cout << "\nplease enter a command (A)DD, (S)EARCH, (E)XIT -> ";
		std::getline(std::cin, reply);
		std::cout << "\n";

		if (reply == "E" || reply == "EXIT")
		{
			std::cout << "farewell\n";
			return 127;
		}

		else if (reply == "A" || reply == "ADD")
		{

			Contact contact;

			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;

			/* ------------ */

		labelFN:
			std::cout << "input first name: ";
			std::getline(std::cin, firstName);
			if (firstName == "" || pb.allSpaces(firstName))
			{
				std::cout << "first name must not be empty\n";
				goto labelFN;
			}
			else
			{
				contact.setFirstName(firstName);
			}

			/* ------------ */

		labelLN:
			std::cout << "input last name: ";
			std::getline(std::cin, lastName);

			if (lastName == "" || pb.allSpaces(lastName))
			{
				std::cout << "last name must not be empty\n";
				goto labelLN;
			}
			else
				contact.setLastName(lastName);

			/* ------------ */

		labelNN:
			std::cout << "input nick name: ";
			std::getline(std::cin, nickName);

			if (nickName == "" || pb.allSpaces(nickName))
			{
				std::cout << "nick name must not be empty\n";
				goto labelNN;
			}
			else
				contact.setNickName(nickName);

			/* ------------ */

		labelPN:
			std::cout << "input phone number: ";
			std::getline(std::cin, phoneNumber);

			if (phoneNumber == "" || pb.allSpaces(phoneNumber) || !pb.isNumber(phoneNumber))
			{
				std::cout << "phone number must be a valid number\n";
				goto labelPN;
			}
			else
			{
				contact.setPhoneNumber(phoneNumber);
			}

			/* ------------ */

		labelDS:
			std::cout << "input darkest secret: ";
			std::getline(std::cin, darkestSecret);

			if (darkestSecret == "" || pb.allSpaces(darkestSecret))
			{
				std::cout << "darkest secret must not be empty\n";
				goto labelDS;
			}
			else
			{
				contact.setDarkestSecret(darkestSecret);
			}

			/* ------------ */

			pb.addContact(contact, i);

			contactNum++;

			i++;

			if (i == 8)
				i = 0;
		}

		else if (reply == "S" || reply == "SEARCH")
		{
			pb.printAllContacts();
			if (contactNum > 0)
			{
			labelID:
				std::cout << "input id of the contact you wanna reach: ";
				std::getline(std::cin, reply);

				if (reply == "")
				{
					std::cout << "id must not be empty" << std::endl;
					goto labelID;
				}
				else if (!pb.isNumber(reply))
				{
					std::cout << "it must be a number!"
							  << "\n";
					goto labelID;
				}
				else if (!pb.isValidNumber(reply))
				{
					std::cout << "it must be between 1-8!"
							  << "\n";
					goto labelID;
				}
				else if (contactNum >= pb.my_stoi(reply))
				{
					pb.printContact(reply);
				}
				else
				{
					std::cout << "only first " << contactNum << " contacts exist"
							  << "\n";
					goto labelID;
				}
			}
		}
		else
		{
			std::cout << "it is only ADD, SEARCH or EXIT mate" << std::endl;
			goto labelSTART;
		}
	}
}
