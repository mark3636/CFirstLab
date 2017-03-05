#pragma once

#include <iostream>
#include <list>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>

//Минимальный элемент в списке
int getMin(std::list<int> lst) {
	if (lst.empty()) {
		throw "ListIsEmpty";
	}
	int min = lst.front();
	for (int el : lst) {
		if (el < min) {
			min = el;
		}
	}
	return min;
}

//Минимальный элемент в списке используюя итераторы
int getItMin(std::list<int>::iterator begin, std::list<int>::iterator end) {
	int min = *begin;
	for (auto it = begin; it != end; ++it) {
		if (*it < min) min = *it;
	}
	return min;
}

//Сумма элементов списка
int listSum(std::list<int> lst) {
	if (lst.empty()) {
		throw "ListIsEmpty";
	}
	int sum = 0;
	for (int el : lst) {
		sum += el;
	}
	return sum;
}

//Среднее арифметическое списка
double listAverage(std::list<int> lst) {
	try {
		int sum = listSum(lst);
		return (double)sum / lst.size();
	}
	catch (std::string str) {
		std::cout << str << std::endl;
	}
}

class Transform {
private:
	int min;
public:
	Transform(const int& value) :min(value) {}
	int operator() (int& elem) const {
		return (elem > 0 ? min : elem);
	}
};

class Foreach {
private:
	int min;
public:
	Foreach(const int& value) :min(value) {}
	void operator() (int& elem) {
		if (elem > 0) elem = min;
	}
};

//Заполнение файла случайными числами(цикличное)
std::fstream randomCycleFilling(std::string fileName, int N, int M) {
	srand(time(NULL));
	std::fstream fout(fileName, std::ios::out);
	for (int i = 0; i < N; ++i) {
		fout << (rand() % (2 * M) + 1) - M << "\n";
	}
	fout.close();
	return fout;
}

//Заполнение файла случайными числами(generate(rand))
std::fstream randomGenerateFilling(std::string fileName, int N, int M) {
	std::vector<int> v(N);
	std::fstream fout(fileName, std::ios::out);
	std::generate(v.begin(), v.end(), rand);
	for (int i = 0; i < N; i++) {
		fout << (v[i] % (2 * M) + 1) - M << "\n";
	}
	fout.close();
	return fout;
}

//Получение списка из файла
std::list<int> listFromFile(std::string fileName) {
	std::fstream fin(fileName, std::ios::in);
	std::list<int> lst;
	int el;

	while (fin >> el) {
		lst.push_back(el);
	}
	fin.close();
	return lst;
}

//modify
std::list<int> modify(std::list<int> lst) {
	try {
		int min = getMin(lst);
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			if (*it > 0) *it = min;
		}
		return lst;
	}
	catch (std::string str) {
		std::cout << str << std::endl;
	}
}

//modify с итераторами
std::list<int> modify(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	std::list<int> result;
	try {
		int min = getItMin(begin, end);
		for (auto it = begin; it != end; it++) {
			result.push_back(*it > 0 ? min : *it);
		}
		return result;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		return result;
	}
}

//modify с transform
std::list<int> transformModify(std::list<int> lst) {
	try {
		int min = getMin(lst);
		std::list<int> result;
		result.resize(lst.size());
		std::transform(lst.begin(), lst.end(), result.begin(), Transform(min));
		return result;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		return lst;
	}
}

//modify с foreach
std::list<int> foreachModify(std::list<int> lst) {
	try {
		int min = getMin(lst);
		std::for_each(lst.begin(), lst.end(), Foreach(min));
		return lst;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		return lst;
	}
}

//Вывод списка в консоль
void listToConsole(std::list<int> lst) {
	for (int x : lst) {
		std::cout << " " << x;
	}
	std::cout << std::endl;
}

//Вывод списка в файл
void listTofile(std::list<int> lst, std::string fileName) {
	std::fstream fout(fileName, std::ios::out);
	for (int x : lst) {
		fout << x << std::endl;
	}
	fout.close();
}