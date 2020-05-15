#include "CsvDatabaseHandler.h"

CsvDatabaseHandler::CsvDatabaseHandler(std::string const & path, bool & out) {
	this->path = path;
	out = InitializeDB();
	if (out && syncDB()) {
		std::cout << "База данных успешно загружена из файла " + path + " и готова к работе." << std::endl;
	}
	else {
		std::cout << "Файл не найден. Положите файл в папку csvDB, либо укажите полный путь." << std::endl;
	}
};

bool CsvDatabaseHandler::syncDB() {
	std::ofstream file(path);
	if (!file.is_open()) {
		file.close();
		return false;
	}
	for (auto const & item : db)	file << item.second.name << ";" << item.second.number << std::endl;
	file.close();
	return true;
}

CsvDatabaseHandler::~CsvDatabaseHandler() {
	if (syncDB())	std::cout << "База данных успешно записана в файл." << std::endl;
	else			std::cout << "Ошибка при записи базы данных в файл." << std::endl;
};

void CsvDatabaseHandler::printDB() const {
	for (auto item : db)
		std::cout << item.second.name << " --- " << item.second.number << std::endl;
}

void CsvDatabaseHandler::findName(std::string const & name) const {
	if (!db.count(name)) {
		std::cout << "Пользователя с таким именем не найдено." << std::endl;
		return;
	}
	auto items = db.equal_range(name);
	std::cout << "Заданному имени соответствуют следующие телефоны:" << std::endl;
	for (; items.first != items.second; ++items.first) {
		std::cout << items.first->second.name << " --- " << items.first->second.number << std::endl;
	}
}


void CsvDatabaseHandler::findNumber(std::string const & number) const {
	bool isFirst = true;
	for (auto item : db) {
		if (number == item.second.name) {
			if (isFirst)	std::cout << "Заданному номеру соответствуют следующие имена:" << std::endl, isFirst = false;
			std::cout << item.first << std::endl;
		}
	}
	if (isFirst) std::cout << "Ни один пользователь с таким номером не найден." << std::endl;
}

void CsvDatabaseHandler::insert(std::string const & name, std::string const & phone) {
	db.insert(std::pair<std::string, UserData>(name, UserData(name, phone)));
}

void CsvDatabaseHandler::remove(std::string const & name) {
	auto count = db.count(name);
	if (!count) {
		std::cout << "Пользователя с таким именем не найдено." << std::endl;
		return;
	}
	if (count == 1) {
		db.erase(name);
		std::cout << "Пользователь " << name << " удалён." << std::endl;
		return;
	}
	auto items = db.equal_range(name);
	//будет нужно при удалении, т.к. при выводе исходный итератор сдвинется
	auto copyIter = items.first;
	std::cout << "Заданному имени соответствуют следующие пользователи:" << std::endl;
	for (int i = 1; items.first != items.second; ++items.first, ++i) {
		std::cout << i << ". " << items.first->second.name << " --- " << items.first->second.number << std::endl;
	}
	int id;
	bool isFirst = true;
	do {
		if (!isFirst)	std::cout << "Вы ввели неверный номер, попробуйте ещё раз." << std::endl;
		std::cout << "Выберите, какого пользователя необходимо удалить и введите соответствующий номер: ";
		std::cin >> id;
		isFirst = false;
	} while (id > count || id < 1);
	while (id > 1) ++copyIter, --id;
	std::cout << "Пользователь " << copyIter->second.name << " c телефоном " << copyIter->second.number << " удалён." << std::endl;
	db.erase(copyIter);
}


bool CsvDatabaseHandler::InitializeDB() {
	std::ifstream file(path);	
	if (!file.is_open()) {
		file.close();
		return false;
	}
	std::istream_iterator<std::string> fin_it(file), eof;

	std::for_each(fin_it, eof, [&](std::string const & tmp) {
		size_t separator = tmp.find(';');
		db.insert(std::pair<std::string, UserData>(tmp.substr(0, separator), UserData(tmp.substr(0, separator), tmp.substr(separator + 1, tmp.length()))));
	});

	file.close();
	return true;
};