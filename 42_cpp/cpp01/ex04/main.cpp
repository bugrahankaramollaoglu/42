/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:47 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/21 19:14:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int ft_strlen(char *s);
void fun(std::string filee, std::string s1, std::string s2);

int main(int ac, char **av)
{
	// parametreler hatalı girilmişse
	if (ac != 4 || ft_strlen(av[1]) == 0 || ft_strlen(av[2]) == 0 || ft_strlen(av[3]) == 0)
	{
		std::cerr << "erroneous params" << std::endl;
		exit(-1);
	}
	else
		fun(av[1], av[2], av[3]);
	return 0;
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void fun(std::string filee, std::string s1, std::string s2)
{
	std::ifstream file(filee);
	std::ofstream fileRep(filee + ".replace");

	// dosyalar açılamiyosa (yoksa)
	if (!file)
	{
		std::cerr << "file cannot be opened" << std::endl;
		return;
	}

	if (!fileRep)
	{
		std::cerr << "file.replace cannot be opened" << std::endl;
		return;
	}

	// file varsa ama boşsa
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "file exists, but empty" << std::endl;
		return;
	}

	// file varsa, doluysa ama aranan string yoksa
	std::string line;
	bool isExtant = false;
	while (std::getline(file, line))
	{
		if (line.find(s1) != std::string::npos)
		{
			isExtant = true;
			break;
		}
	}
	if (!isExtant)
	{
		std::cerr << "file does not contain the string" << std::endl;
		return;
	}

	file.clear();
	file.seekg(0, std::ios::beg);

	// işlemler
	line = "";
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			fileRep << line.substr(0, pos) << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		fileRep << line << std::endl;
	}

	file.close();
	fileRep.close();
}

