#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <map>

//7567

//return random number <from; to>
int returnRandom(int from, int to) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(from, to);
	return dist6(rng);
}

//return sum of numbers
int sumOfWords(std::vector<std::string> &vec) {
	int sum = 0;
	for (auto &i : vec)
		sum += i.size();
	return sum;
}

//return words with sum of letter equal to 8 or higher
std::vector<std::string> wordsInLogin(std::vector<std::string> &words) {
	std::vector<std::string> wordsInPass;
	do {
		std::string actual = words[returnRandom(0, 7556)];
		if (std::find(std::begin(wordsInPass), std::end(wordsInPass), actual) == std::end(wordsInPass))
			wordsInPass.push_back(actual);

	} while (sumOfWords(wordsInPass) < 5);

	return wordsInPass;
}

void transformation(std::vector<std::string> &words, std::string &signs) {
	for (auto &i : words) {
		for (int j = 0; j < i.size(); j++) {
			if ((i[j] == 'H' || i[j] == 'x' || i[j] == 'J' || i[j] == 'q' || i[j] == 'I' || i[j] == 'i') && returnRandom(1, 100) % 4 == 0) {
				switch (i[j]) {
					case 'H': case 'x':
						i[j] = '#';
						break;
					case 'J': case 'q':
						i[j] = '&';
						break;
					case 'I':
						i[j] = '1';
						break;
					case 'i':
						i[j] = '!';
						break;
				}
			}
			else if ((i[j] == 'A' || i[j] == 'a' || i[j] == '10') && returnRandom(1, 100) % 2 == 0) {
				switch (i[j]) {
					case 'a': case 'A':
						i[j] = '@';
						break;
					case 'S':
						i[j] = '$';
						break;
					case 'e': case 'E':
						i[j] = '3';
						break;
				}
			}
			else if (returnRandom(1, 100) % 5 == 0) {
				i[j] = signs[returnRandom(0, 23)];
			}
		}
	}
}

std::vector<std::string> SAN(std::string &signs, int start, int end) {
	std::vector<std::string> toReturn;
	toReturn.push_back(std::to_string(returnRandom(start, end)));
	std::string t; t += signs[returnRandom(0, 23)];
	toReturn.push_back(t);
	t = ""; t += signs[returnRandom(0, 23)];
	toReturn.push_back(t);
	return toReturn;
}

std::string login(std::vector<std::string> &words, std::vector<std::string> &san) {
	std::string log = words[0];
	log += san[2];
	if (words.size() > 2)
		log += words[words.size() - 1];
	log += san[1];
	for (int i = 1; i < words.size() - 1; i++)
		log += words[i];
	log += san[0];
	return log;
}

int main()
{
	std::fstream file;
	file.open("words.txt", std::ios::in);
	//array for the words that I will use to make password
	std::vector<std::string> words;
	
	std::string word;
	while (file >> word)
		words.push_back(word);
	
	file.close();

	//singns for the login
	std::string signs = "!@#$%^&*()_-+=}{[]|?><~'"; //23
	//put into vector few words from big vector array
	auto loginWords = wordsInLogin(words);
	//transform some words
	transformation(loginWords, signs);
	//now we rand signs and numbers
	auto signsAndNumber = SAN(signs, 0, 10000);
	//put the all data into one login and write it out
	std::cout << login(loginWords, signsAndNumber) << std::endl;

	system("pause");
	return 0;
}

