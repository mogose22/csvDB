#include "CsvDatabaseHandler.h"

CsvDatabaseHandler::CsvDatabaseHandler(std::string const & path) {
	this->path = path;
	auto flag = InitializeDB();
	if (flag) {
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
		std::cout << item.first + " --- " + item.second << std::endl;
};

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