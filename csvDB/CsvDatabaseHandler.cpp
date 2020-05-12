#include "CsvDatabaseHandler.h"

CsvDatabaseHandler::CsvDatabaseHandler(std::string const & path, bool & out) {
	this->path = path;
	out = InitializeDB();
	if (out) {
		std::cout << "База данных успешно загружена из файла " + path + " и готова к работе." << std::endl;
	}
	else {
		std::cout << "Файл не найден. Положите файл в папку csvDB, либо укажите полный путь." << std::endl;
	}
};

CsvDatabaseHandler::~CsvDatabaseHandler() {
};

void CsvDatabaseHandler::PrintDB() const {
	for (auto item : bdNames)
		std::cout << item.first << " --- " << item.second << std::endl;
}

void CsvDatabaseHandler::findName(std::string const & name) const {
	if (!bdNames.count(name)) {
		std::cout << "Пользователя с таким именем не найдено." << std::endl;
		return;
	}
	auto items = bdNames.equal_range(name);
	std::cout << "Заданному имени соответствуют следующие телефоны:" << std::endl;
	for (; items.first != items.second; ++items.first) {
		std::cout << items.first->first << " --- " << items.first->second << std::endl;
	}
}


void CsvDatabaseHandler::findNumber(std::string const & number) const {
	bool isFirst = true;
	for (auto item : bdNames) {
		if (number == item.second) {
			if (isFirst)	std::cout << "Заданному номеру соответствуют следующие имена:" << std::endl, isFirst = false;
			std::cout << item.first  << std::endl;
		}
	}
	if (!isFirst) std::cout << "Ни один пользователь с таким номером не найден." << std::endl;
}

bool CsvDatabaseHandler::InitializeDB() {
	std::ifstream file(path);
	if (!file.is_open()) {
		file.close();
		return false;
	}
	std::string s;
	while (getline(file, s)) {
		int separator = s.find(';');
		this->bdNames.insert(std::pair<std::string, std::string>(s.substr(0, separator), s.substr(separator + 1, s.length())));
	}
	file.close();
	return true;
};