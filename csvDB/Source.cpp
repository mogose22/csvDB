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

	std::cout << "Работа завершена." << std::endl;
	return 0;
}

bool command_handler(CsvDatabaseHandler & db) {
	std::cout << "Введите команду из следующего списка:" << std::endl;
	std::cout << "find, insert, remove, print, exit, clear" << std::endl;
	std::string command;
	std::cin >> command;

	if (command == "exit")		return false;
	else if (command == "find")	return find(db);
	else if (command == "insert") return insert(db);
	else if (command == "remove") return remove(db);
	else if (command == "print") return print(db);
	else if (command == "clear") return clear();
	std::cout << "Команда введена неверно. Попробуйте ещё раз, без пробелов, маленькими буквами." << std::endl;
	return true;
}

const bool find(CsvDatabaseHandler const & db) {
	std::cout << "Введите необходимое имя для поиска по имени, либо необходимый номер для поиска по номеру (только цифры)." << std::endl;
	std::string input;
	std::cin >> input;
	size_t findNotDigit = input.find_first_not_of("1234567890"); 
	if (findNotDigit == -1) {
		std::cout << "Будет произведён поиск по номерам телефонов." << std::endl;
		db.findNumber(input);
	}
	else {
		std::cout << "Будет произведён поиск по именам." << std::endl;
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
	std::cout << "Введите добавляемое имя пользователя и его номер через пробел: ";
	std::cin >> name >> phone;
	size_t findNotDigit = phone.find_first_not_of("1234567890");
	if (findNotDigit != -1) {
		std::cout << "В номере телефонах не может быть символов кроме цифр." << std::endl;
		return true;
	}
	db.insert(name, phone);
	std::cout << "Пользователь добавлен." << std::endl;
	return true;
}

bool remove(CsvDatabaseHandler & db) {
	std::string name;
	std::cout << "Введите имя удаляемого пользователя: ";
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
