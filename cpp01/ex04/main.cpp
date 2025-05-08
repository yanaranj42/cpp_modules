/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:15:02 by yanaranj          #+#    #+#             */
/*   Updated: 2025/05/08 13:22:17 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
//#include <cstring>

void	outputfile(std::string filename, std::string s1, std::string s2, std::string line)
{
	std::ofstream outfile;
	int	pos;
	
	outfile.open((filename.append(".replace")));
	if (!outfile)
	{
		std::cout << "Cannot open fd" << std::endl;
		return ;
	}
	for (int i = 0; i < (int)line.size(); i++)
	{
		pos = line.find(s1, i);
		if (pos != -1 && pos == i)
		{
			outfile << s2;
			i += std::string(s1).size() - 1;
		}
		else
			outfile << line[i];
	}
	outfile.close();
}

int main(int ac, char **av)
{
	std::ifstream infile;
	std::string	line;
	char c;
	
	if (ac != 4)
	{
		std::cout << "expecting >>" << std::endl;
		std::cout << "./replace [filename] [string 1] [string 2]";
	}
	else
	{
		infile.open(av[1]);
		if (!infile)
		{
			std::cout << "Cannot open fd" << std::endl;
			return (1);
		}
		getline(infile, line, '\0');
		if (line == "")
		{
			std::cout << "File is empty" << std::endl;
			return (1);
		}
		outputfile(av[1], av[2], av[3], line);
		infile.close();
	}
	return (0);
}