#include "Source.h"

int main() {
#if defined(_WIN32) || defined(_WIN64)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
	bool flag = true;
	CsvDatabaseHandler db("test.csv", flag);
	if (!flag) return 0;

	while (flag)	flag = command_handler(db);

	std::cout << "������ ���������." << std::endl;
	return 0;
}

bool command_handler(CsvDatabaseHandler & db) {
	std::cout << "������� ������� �� ���������� ������:" << std::endl;
	std::cout << "find, insert, remove, print, exit, clear" << std::endl;
	std::string command;
	std::cin >> command;

	if (command == "exit")		return false;
	else if (command == "find")	return find(db);
	else if (command == "insert") return insert(db);
	else if (command == "remove") return remove(db);
	else if (command == "print") return print(db);
	else if (command == "clear") return clear();
	std::cout << "������� ������� �������. ���������� ��� ���, ��� ��������, ���������� �������." << std::endl;
	return true;
}

const bool find(CsvDatabaseHandler const & db) {
	std::cout << "������� ����������� ��� ��� ������ �� �����, ���� ����������� ����� ��� ������ �� ������ (������ �����)." << std::endl;
	std::string input;
	std::cin >> input;
	size_t findNotDigit = input.find_first_not_of("1234567890"); 
	if (findNotDigit == -1) {
		std::cout << "����� ��������� ����� �� ������� ���������." << std::endl;
		db.findNumber(input);
	}
	else {
		std::cout << "����� ��������� ����� �� ������." << std::endl;
		db.findName(input);
	}
	return true;
}

const bool print(CsvDatabaseHandler const & db) {
	db.printDB();
	return true;
}

bool insert(CsvDatabaseHandler & db) {
	std::string name, phone;
	std::cout << "������� ����������� ��� ������������ � ��� ����� ����� ������: ";
	std::cin >> name >> phone;
	size_t findNotDigit = phone.find_first_not_of("1234567890");
	if (findNotDigit != -1) {
		std::cout << "� ������ ��������� �� ����� ���� �������� ����� ����." << std::endl;
		return true;
	}
	db.insert(name, phone);
	std::cout << "������������ ��������." << std::endl;
	return true;
}

bool remove(CsvDatabaseHandler & db) {
	std::string name;
	std::cout << "������� ��� ���������� ������������: ";
	std::cin >> name;
	db.remove(name);
	return true;
}

bool clear() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#endif
	return true;
}
