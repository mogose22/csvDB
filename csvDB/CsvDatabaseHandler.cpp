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
	for (auto const & item : dbNames)	file << item.first << ";" << item.second << std::endl;
	file.close();
	return true;	
}

CsvDatabaseHandler::~CsvDatabaseHandler() {
	if (syncDB())	std::cout << "���� ������ ������� �������� � ����." << std::endl;
	else			std::cout << "������ ��� ������ ���� ������ � ����." << std::endl;
};

void CsvDatabaseHandler::printDB() const {
	for (auto item : dbNames)
		std::cout << item.first << " --- " << item.second << std::endl;
}

void CsvDatabaseHandler::findName(std::string const & name) const {
	if (!dbNames.count(name)) {
		std::cout << "������������ � ����� ������ �� �������." << std::endl;
		return;
	}
	auto items = dbNames.equal_range(name);
	std::cout << "��������� ����� ������������� ��������� ��������:" << std::endl;
	for (; items.first != items.second; ++items.first) {
		std::cout << items.first->first << " --- " << items.first->second << std::endl;
	}
}


void CsvDatabaseHandler::findNumber(std::string const & number) const {
	bool isFirst = true;
	for (auto item : dbNames) {
		if (number == item.second) {
			if (isFirst)	std::cout << "��������� ������ ������������� ��������� �����:" << std::endl, isFirst = false;
			std::cout << item.first  << std::endl;
		}
	}
	if (isFirst) std::cout << "�� ���� ������������ � ����� ������� �� ������." << std::endl;
}

void CsvDatabaseHandler::insert(std::string const & name, std::string const & phone) {
	dbNames.insert(std::pair<std::string, std::string>(name, phone));
}

void CsvDatabaseHandler::remove(std::string const & name) {
	auto count = dbNames.count(name);
	if (!count) {
		std::cout << "������������ � ����� ������ �� �������." << std::endl;
		return;
	}
	if (count == 1) {
		dbNames.erase(name);
		std::cout << "������������ " << name << " �����." << std::endl;
		return;
	}
	auto items = dbNames.equal_range(name);
	//����� ����� ��� ��������, �.�. ��� ������ �������� �������� ���������
	auto copyIter = items.first;
	std::cout << "��������� ����� ������������� ��������� ������������:" << std::endl;
	for (int i = 1; items.first != items.second; ++items.first, ++i) {
		std::cout << i << ". " << items.first->first << " --- " << items.first->second << std::endl;
	}
	int id;
	bool isFirst = true;
	 do{
		if (!isFirst)	std::cout << "�� ����� �������� �����, ���������� ��� ���." << std::endl;
		std::cout << "��������, ������ ������������ ���������� ������� � ������� ��������������� �����: ";
		std::cin >> id;
		isFirst = false;
	}while (id > count || id < 1);
	while (id > 1) ++copyIter, --id;
	std::cout << copyIter->first << " " << copyIter->second << std::endl;
	std::cout << "������������ " << copyIter->first << " c ��������� " << copyIter->second << " �����." << std::endl;
	dbNames.erase(copyIter);
}


bool CsvDatabaseHandler::InitializeDB() {
	std::ifstream file(path);
	if (!file.is_open()) {
		file.close();
		return false;
	}
	std::string s;
	while (getline(file, s)) {
		size_t separator = s.find(';');
		this->dbNames.insert(std::pair<std::string, std::string>(s.substr(0, separator), s.substr(separator + 1, s.length())));
	}
	file.close();
	return true;
};