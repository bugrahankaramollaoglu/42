/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:38:42 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:53:15 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>


class Replace
{
public:
	Replace();
	~Replace();

public:
	int ft_strlen(char *s);
	void fun(std::string filee, std::string s1, std::string s2);
};

#endif
