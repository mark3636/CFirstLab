//Лукин Марк
//13(С). Заменить все положительные числа квадратом минимального числа(std::list).
#include "ListUtils.h"

//Печать меню
void printMenu() {
	std::cout << " 1)Fill file with random numbers" << std::endl;
	std::cout << " 2)Input" << std::endl;
	std::cout << " 3)Modify" << std::endl;
	std::cout << " 4)Modify(iterators)" << std::endl;
	std::cout << " 5)Modify(transform)" << std::endl;
	std::cout << " 6)Modify(foreach)" << std::endl;
	std::cout << " 7)Sum of list" << std::endl;
	std::cout << " 8)Average of list" << std::endl;
	std::cout << " 9)Output to console" << std::endl;
	std::cout << " 10)Output to file" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << " >> ";
}

//Получение имени файла
std::string getFileName() {
	std::string fileName;
	std::cout << "\n Enter file name: ";
	std::getline(std::cin, fileName);
	std::getline(std::cin, fileName);
	if (fileName == "") fileName = "default";
	return fileName + ".txt";
}

int main() {
	std::list<int> lst;
	std::string fileName;
	std::string str;
	int choice;
	int o;
	auto begin = lst.begin();
	auto end = lst.begin();

	while (true) {
		printMenu();
		std::cin >> str;
		try {
			choice = std::stoi(str);
			switch (choice) {
			case 1:
				int N, M;
				o = 0;
				fileName = getFileName();
				std::cout << "Enter count: ";
				std::cin >> N;
				std::cout << "Enter range: ";
				std::cin >> M;
				while ((o < 1) || (o > 3))
				{
					std::cout << " 1)CycleFilling\n";
					std::cout << " 2)GenerateFilling\n";
					std::cout << " 3)Cancel\n";
					std::cout << " >> ";
					std::cin >> o;
				}
				switch (o)
				{
				case 1:
					randomCycleFilling(fileName, N, M);
					break;
				case 2:
					randomGenerateFilling(fileName, N, M);
					break;
				case 3:
					break;
				}
				break;
			case 2:
				fileName = getFileName();
				lst = listFromFile(fileName);
				listToConsole(lst);
				break;
			case 3:
				if (!lst.empty()) {
					listToConsole(lst);
					lst = modify(lst);
					listToConsole(lst);
				}
				else {
					std::cout << "List is empty!" << std::endl;
				}
				break;
			case 4:
				int a , b;
				a = b = o = 0;
				if (!lst.empty()) {
					while ((o < 1) || (o > 3)) {
						std::cout << " 1)[list.begin(), list.end())\n";
						std::cout << " 2)[a, b)\n";
						std::cout << " 3)Cancel\n";
						std::cout << " >> ";
						std::cin >> o;
					}
					switch (o) {
					case 1:
						listToConsole(lst);
						modify(lst.begin(), lst.end());
						listToConsole(lst);
						break;
					case 2:
						std::cout << "a: ";
						std::cin >> a;
						std::cout << "b: ";
						std::cin >> b;
						
						if (a >= b || b < 0 || a < 0) {
							std::cout << " Wrong range!\n";
						}
						else {
							begin = lst.begin();
							end = lst.begin();

							std::advance(begin, a);
							std::advance(end, b);

							listToConsole(lst);

							modify(begin, end);

							listToConsole(lst);
						}
						break;
					case 3:
						break;
					}
					
				}
				else {
					std::cout << "List is empty!" << std::endl;
				}
				break;
			case 5:
				if (!lst.empty()) {
					listToConsole(lst);
					lst = transformModify(lst);
					listToConsole(lst);
				}
				else {
					std::cout << "List is empty!" << std::endl;
				}
				break;
			case 6:
				if (!lst.empty()) {
					listToConsole(lst);
					lst = foreachModify(lst);
					listToConsole(lst);
				}
				else {
					std::cout << "\n List is empty!\n" << std::endl;
				}
				break;
			case 7:
				try {
					std::cout << "Sum of list = " << listSum(lst) << std::endl;
				}
				catch (const char* str) {
					std::cout << str << std::endl;
				}
				break;
			case 8:
				try {
					std::cout << "Average of list = " << listAverage(lst) << std::endl;
				}
				catch (const char* str) {
					std::cout << str << std::endl;
				}
				break;
			case 10:
				if (!lst.empty()) {
					fileName = getFileName();
					listTofile(lst, fileName);
				}
				else {
					std::cout << "\n List is empty!\n" << std::endl;
				}
				break;
			case 9:
				if (!lst.empty()) {
					listToConsole(lst);
				}
				else {
					std::cout << "\n List is empty!\n" << std::endl;
				}
				break;
			case 0:
				return 0;
				break;
			default:
				std::cout << "\n Wrong command!\n" << std::endl;
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "\n Wrong command!\n" << std::endl;
		}
	}
}