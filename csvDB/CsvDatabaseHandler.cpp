#include "CsvDatabaseHandler.h"

CsvDatabaseHandler::CsvDatabaseHandler(std::string const & path, bool & out) {
	this->path = path;
	out = InitializeDB();
	if (out && syncDB()) {
		std::cout << "���� ������ ������� ��������� �� ����� " + path + " � ������ � ������." << std::endl;
	}
	else {
		std::cout << "���� �� ������. �������� ���� � ����� csvDB, ���� ������� ������ ����." << std::endl;
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
	if (syncDB())	std::cout << "���� ������ ������� �������� � ����." << std::endl;
	else			std::cout << "������ ��� ������ ���� ������ � ����." << std::endl;
};

void CsvDatabaseHandler::printDB() const {
	for (auto item : db)
		std::cout << item.second.name << " --- " << item.second.number << std::endl;
}

void CsvDatabaseHandler::findName(std::string const & name) const {
	if (!db.count(name)) {
		std::cout << "������������ � ����� ������ �� �������." << std::endl;
		return;
	}
	auto items = db.equal_range(name);
	std::cout << "��������� ����� ������������� ��������� ��������:" << std::endl;
	for (; items.first != items.second; ++items.first) {
		std::cout << items.first->second.name << " --- " << items.first->second.number << std::endl;
	}
}


void CsvDatabaseHandler::findNumber(std::string const & number) const {
	bool isFirst = true;
	for (auto item : db) {
		if (number == item.second.name) {
			if (isFirst)	std::cout << "��������� ������ ������������� ��������� �����:" << std::endl, isFirst = false;
			std::cout << item.first << std::endl;
		}
	}
	if (isFirst) std::cout << "�� ���� ������������ � ����� ������� �� ������." << std::endl;
}

void CsvDatabaseHandler::insert(std::string const & name, std::string const & phone) {
	db.insert(std::pair<std::string, UserData>(name, UserData(name, phone)));
}

void CsvDatabaseHandler::remove(std::string const & name) {
	auto count = db.count(name);
	if (!count) {
		std::cout << "������������ � ����� ������ �� �������." << std::endl;
		return;
	}
	if (count == 1) {
		db.erase(name);
		std::cout << "������������ " << name << " �����." << std::endl;
		return;
	}
	auto items = db.equal_range(name);
	//����� ����� ��� ��������, �.�. ��� ������ �������� �������� ���������
	auto copyIter = items.first;
	std::cout << "��������� ����� ������������� ��������� ������������:" << std::endl;
	for (int i = 1; items.first != items.second; ++items.first, ++i) {
		std::cout << i << ". " << items.first->second.name << " --- " << items.first->second.number << std::endl;
	}
	int id;
	bool isFirst = true;
	do {
		if (!isFirst)	std::cout << "�� ����� �������� �����, ���������� ��� ���." << std::endl;
		std::cout << "��������, ������ ������������ ���������� ������� � ������� ��������������� �����: ";
		std::cin >> id;
		isFirst = false;
	} while (id > count || id < 1);
	while (id > 1) ++copyIter, --id;
	std::cout << "������������ " << copyIter->second.name << " c ��������� " << copyIter->second.number << " �����." << std::endl;
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