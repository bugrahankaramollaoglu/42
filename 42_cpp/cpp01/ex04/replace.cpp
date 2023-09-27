/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:54:32 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 16:59:46 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace()
{
}

Replace::~Replace()
{
}

int Replace::ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void Replace::fun(std::string filee, std::string s1, std::string s2)
{
	const char *filee_cstr = filee.c_str();

	// c_str'ye çeviriyoruz çünkü c++98'de ifstream ofstream std::string almıyor
	std::ifstream file(filee_cstr);
	std::ofstream fileRep((filee + ".replace").c_str());

	if (!file.is_open())
	{
		std::cerr << "file cannot be opened, prob no such file" << std::endl;
		return;
	}

	if (!fileRep.is_open())
	{
		std::cerr << "file.replace cannot be opened" << std::endl;
		return;
	}

	if (file.peek() == EOF)
	{
		std::cerr << "file exists, but empty" << std::endl;
		return;
	}

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
		std::cerr << "file exists, but does not contain the string" << std::endl;
		return;
	}

	// error flaglerini temizleyip
	file.clear();

	// imleci başa aliyoruz
	// eğer böyle yapmazsak ilk buldugu karakterin oldugu satırı .rep'e atmiyor
	file.seekg(0, std::ios::beg);

	line = "";
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(s1);
		// std::cout << pos << "\n"; // eğer bunu yazdırırsak bulamadıgı durumlarda
		// 18446744073709551615 oluyor pos. bu max size_t değeri. failde bu dönüyor.
		// s1 olan satırlarda buna giriyor
		while (pos != std::string::npos)
		{
			// fileRep'in içine iki şey yazdırıyor chain halinde
			// önce satırın başlangıcından s1'i gördügü yere kadar
			// her şeyi normal file.replace'e atiyor sonra s2 ekliyor
			fileRep << line.substr(0, pos) << s2;

			// daha sonra satırı, s1'den sonrası olarak güncelliyor
			line = line.substr(pos + s1.length());

			// daha sonra aynı satırda başka s1 varsa posu tekrar güncelliyor
			// başka bulamazsa find() npos döndüreceginden, inner while bitmiş oluyor
			pos = line.find(s1);
		}

		// satırda kalan s1 harici her şey de .replace dosyasına
		// atiliyor ve alt satıra geçiyor
		fileRep << line << std::endl;
	}
	file.close();
	fileRep.close();
}
