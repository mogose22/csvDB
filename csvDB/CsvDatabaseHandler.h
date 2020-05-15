#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "UserData.h"

struct CsvDatabaseHandler {
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
	std::multimap<std::string, UserData> db;
};
