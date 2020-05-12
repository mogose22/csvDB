#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>

class CsvDatabaseHandler {
public:
	//Конструктор принимает имя файла с базой данных.
	CsvDatabaseHandler(std::string const & path, bool & out);
	//Деструктор пока ничего не делает. Возможно ничего и не понадобился, у тебя пока не одного new.
	~CsvDatabaseHandler();
	//Будем выводить текущую отсортированную ДБ в консоль.
	void PrintDB() const;
	//Поиск по ключу
	void findName(std::string const & name) const;
	//Поиск по значению
	void findNumber(std::string const & number) const;
private:
	//Считываем данные из файла и заполняем наши мультимапы.
	bool InitializeDB();
	//Имя файла, возможно тут можно будет указывать и полные пути.
	std::string path;
	//База данных, где ключи- имена. Имена могут повторяться.
	std::multimap<std::string, std::string> bdNames;
};
