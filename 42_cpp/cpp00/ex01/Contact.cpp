/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:10:42 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 02:28:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::applyFirstName(std::string fn)
{
	this->firstName = fn;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

/* ----------- */

void Contact::applyLastName(std::string ln)
{
	this->lastName = ln;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

/* ----------- */

void Contact::applyNickName(std::string nn)
{
	this->nickName = nn;
}

std::string Contact::getNickName()
{
	return this->nickName;
}

/* ----------- */

void Contact::applyPhoneNumber(std::string pn)
{
	this->phoneNumber = pn;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

/* ----------- */

void Contact::applyDarkestSecret(std::string ds)
{
	this->darkestSecret = ds;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}
