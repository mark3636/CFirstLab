#include "ListUtils.h"

void printMenu() {
	std::cout << " 1)Fill file with random numbers" << std::endl;
	std::cout << " 2)Input" << std::endl;
	std::cout << " 3)Modify" << std::endl;
	std::cout << " 4)Modify(iterators)" << std::endl;
	std::cout << " 5)Modify(transform)" << std::endl;
	std::cout << " 6)Modify(foreach)" << std::endl;
	std::cout << " 7)Sum of list" << std::endl;
	std::cout << " 8)Average of list" << std::endl;
	std::cout << " 9)Output" << std::endl;
	std::cout << "10)Exit" << std::endl;
	std::cout << "Enter the command: ";
}

std::string getFileName() {
	std::string fileName;
	std::cout << "Enter file name: ";
	std::getline(std::cin, fileName);
	std::getline(std::cin, fileName);
	return fileName;
}

int main() {
	std::list<int> lst;
	std::string fileName;
	char ch;

	while (true) {
		printMenu();
		std::cin >> ch;
		switch (ch) {
		case '1':
			int N, M;
			fileName = getFileName();
			std::cout << "Enter count: ";
			std::cin >> N;
			std::cout << "Enter range: ";
			std::cin >> M;
			randomCycleFilling(fileName, N, M);
			randomGenerateFilling(fileName, N, M);
			break;
		case '2':
			fileName = getFileName();
			lst = listFromFile(fileName);
			listToConsole(lst);
			break;
		case '3':
			if (!lst.empty()) lst = modify(lst);
			else {
				std::cout << "List is empty!" << std::endl;
			}
			break;
		case '4':
			if (!lst.empty()) lst = modify(lst.begin(), lst.end());
			else {
				std::cout << "List is empty!" << std::endl;
			}
			break;
		case '5':
			if (!lst.empty()) lst = transformModify(lst);
			else {
				std::cout << "List is empty!" << std::endl;
			}
			break;
		case '6':
			if (!lst.empty()) lst = foreachModify(lst);
			else {
				std::cout << "List is empty!" << std::endl;
			}
			break;
		case '7':
			std::cout << "Sum of list = " << listSum(lst) << std::endl;
			break;
		case '8':
			std::cout << "Average of list = " << listAverage(lst) << std::endl;
			break;
		case '9':
			if (!lst.empty()) {
				fileName = getFileName();
				listTofile(lst, fileName);
			}
			else {
				std::cout << "List is empty!" << std::endl;
			}
			break;
		case '10':
			return 0;
			break;
		default:
			std::cout << "Wrong command!" << std::endl;
			break;
		}
	}
}