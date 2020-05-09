#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>

class CsvDatabaseHandler {
public:
	//����������� ��������� ��� ����� � ����� ������.
	CsvDatabaseHandler(std::string const & path);
	//���������� ���� ������ �� ������. �������� ������ � �� �����������, � ���� ���� �� ������ new.
	~CsvDatabaseHandler();
	//����� �������� ������� ��������������� �� � �������.
	void PrintDB() const;
private:
	//��������� ������ �� ����� � ��������� ���� ����������.
	bool InitializeDB();
	//��� �����, �������� ��� ����� ����� ��������� � ������ ����.
	std::string path;
	//���� ������, ��� �����- �����. ����� ����� �����������.
	std::multimap<std::string, std::string> bdNames;
};
