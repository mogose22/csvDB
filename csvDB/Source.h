#pragma once
#include "CsvDatabaseHandler.h"
#include <Windows.h>

//�����
const bool find(CsvDatabaseHandler const & db);
//����� ���� ��
const bool print(CsvDatabaseHandler const & db);
//������� ��������
bool insert(CsvDatabaseHandler & db);
//�������� ��������
bool remove(CsvDatabaseHandler & db);
//���������� �������� ������
bool command_handler(CsvDatabaseHandler & db);
//�������� ������
bool clear();