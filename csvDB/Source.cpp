#include "Source.h"

int main() {
	setlocale(LC_ALL, "Russian");
	CsvDatabaseHandler db("test.csv");
	db.PrintDB();
	bool flag = true;
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
	return true;
}

const bool print(CsvDatabaseHandler const & db) {
	db.PrintDB();
	return true;
}

bool insert(CsvDatabaseHandler & db) {
	std::cout << "��� ����� ������� ����� ���� � ��" << std::endl;
	return true;
}

bool remove(CsvDatabaseHandler & db) {
	std::cout << "��� ����� �������� ���� �� ��" << std::endl;
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
