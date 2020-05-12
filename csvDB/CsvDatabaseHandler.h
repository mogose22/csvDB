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
	void PrintDB() const;
	//����� �� �����
	void findName(std::string const & name) const;
	//����� �� ��������
	void findNumber(std::string const & number) const;
private:
	//��������� ������ �� ����� � ��������� ���� ����������.
	bool InitializeDB();
	//��� �����, �������� ��� ����� ����� ��������� � ������ ����.
	std::string path;
	//���� ������, ��� �����- �����. ����� ����� �����������.
	std::multimap<std::string, std::string> bdNames;
};
