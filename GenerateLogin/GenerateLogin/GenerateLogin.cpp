#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <map>

//return words with sum of letter equal to 8 or higher
/*std::vector<std::string> words(std::vector<std::string> words) {

}
*/
int main()
{
	std::fstream file, newFile;
	file.open("words.txt", std::ios::out);
	newFile.open("newword.txt", std::ios::in | std::ios::app);
	if (newFile.is_open())
		std::cout << "new file is open" << std::endl;
	if (file.is_open())
		std::cout << "file is open" << std::endl;
	std::vector<std::string> wordx;

	int index; std::string word;
	while (file >> index >> word) {
		std::cout << word << std::endl;
		newFile << word << "\n";
	}
	
	file.close(); newFile.close();

	system("pause");
	return 0;
}

