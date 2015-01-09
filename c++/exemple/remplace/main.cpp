#include <string>
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string	filename(av[1]);
		std::string outfile(filename + ".replace");
		std::string s1(av[2]);
		std::string s2(av[3]);
		std::string line;
		size_t pos;

		std::ifstream ifs(filename.c_str());
		std::ofstream ofs(outfile.c_str());
		if (!ifs.is_open())
		{
			std::cout << "Cannot open file: " << filename << std::endl;
			return 1;
		}
		while (std::getline(ifs, line))
		{
			while ((pos = line.find(s1)) != std::string::npos)
			{
				line.replace(pos, s1.size(), s2);
				pos += s2.size();
			}
			ofs << line << std::endl;
		}
		ifs.close();
		ofs.close();
	}
	else
		std::cout << "usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
	return 0;
}
