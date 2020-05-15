#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "UserData.h"

struct CsvDatabaseHandler {
	//Конструктор принимает имя файла с базой данных.
	CsvDatabaseHandler(std::string const & path, bool & out);
	//Деструктор пока ничего не делает. Возможно ничего и не понадобился, у тебя пока не одного new.
	~CsvDatabaseHandler();
	//Будем выводить текущую отсортированную ДБ в консоль.
	void printDB() const;
	//Поиск по ключу.
	void findName(std::string const & name) const;
	//Поиск по значению.
	void findNumber(std::string const & number) const;
	//Добавление пользователя.
	void insert(std::string const & name, std::string const & phone);
	//Удаление пользователя.
	void remove(std::string const & name);
private:
	//Считываем данные из файла и заполняем наш мультимап.
	bool InitializeDB();
	//Записываем нашу бд обратно в файл.
	bool syncDB();
	//Имя файла, возможно тут можно будет указывать и полные пути.
	std::string path;
	//База данных, где ключи- имена. Имена могут повторяться.
	std::multimap<std::string, UserData> db;
};
