/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:39:48 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 15:16:54 by bkaramol         ###   ########.fr       */
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
		std::cerr << "file exists, but does not contain the string" << std::endl;
		return;
	}

	// dosyanın hata durumunu siler
	file.clear();
	// stream başlangıç noktasını dosyanın başına götürür
	file.seekg(0, std::ios::beg);

	// işlemler
	line = "";
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(s1);

		// pos burada s1'in başlangıç noktası
		// s1 gördüğü kısımlarda s1 bitene kadar buna giriyor
		while (pos != std::string::npos)
		{
			// fileRep outstream'ine chainAppend yapılmış
			// önce line yani file'ın bir satırını baştan (0)
			// s1 yani eski str görene kadar alıp file.replace dosyasına atılmış
			// daha sonra bunun da sonuna yeni str yani s2 eklenmiş
			fileRep << line.substr(0, pos) << s2;
			// burada ise s1 + s1'in ilk konumu kadar kaydırıyoruz line'ı
			// artık yeni line s1'den sonraki satır sonuna kadar olan kısım oldu
			line = line.substr(pos + s1.length());
			// her defasında güncelliyoruz
			pos = line.find(s1);
		}
		// görmediği yani s1 olmayan satırları direkt line'da biriktiriyor
		fileRep << line << std::endl;
	}
	file.close();
	fileRep.close();
}
