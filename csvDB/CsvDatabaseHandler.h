#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>

class CsvDatabaseHandler {
public:
	//����������� ��������� ��� ����� � ����� ������.
	CsvDatabaseHandler(std::string const & path, bool & out);
	//���������� ���� ������ �� ������. �������� ������ � �� �����������, � ���� ���� �� ������ new.
	~CsvDatabaseHandler();
	//����� �������� ������� ��������������� �� � �������.
	void printDB() const;
	//����� �� �����.
	void findName(std::string const & name) const;
	//����� �� ��������.
	void findNumber(std::string const & number) const;
	//���������� ������������.
	void insert(std::string const & name, std::string const & phone);
	//�������� ������������.
	void remove(std::string const & name);
private:
	//��������� ������ �� ����� � ��������� ��� ���������.
	bool InitializeDB();
	//���������� ���� �� ������� � ����.
	bool syncDB();
	//��� �����, �������� ��� ����� ����� ��������� � ������ ����.
	std::string path;
	//���� ������, ��� �����- �����. ����� ����� �����������.
	std::multimap<std::string, std::string> dbNames;
};
