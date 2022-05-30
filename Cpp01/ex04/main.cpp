
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 4) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "Example of use: ./sed [filename] [string1] [string2] " << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Open input file
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error: file \"" << argv[1] << "\" can not be opened "  << std::endl;
		return (1);
	}
	
	// Open output file
	std::string filename_output = filename + ".replace";
	std::ofstream ofs(filename_output.c_str());
	if (!ofs.is_open())
	{
		std::cout << "Error: file \"" << argv[1] << "\" can not be opened "  << std::endl;
		return (1);
	}

	// Copy in buffer input file.
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();

	// Init string with file input.
	std::string str =  buffer.str();

	// Start the find and replace.
	for(size_t pos = str.find(s1); pos != std::string::npos; pos = str.find(s1, pos + s1.length()) )
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
	}

	// Save the new-replace in output file.
	ofs << str;
	ofs.close();
	return (0);
}
