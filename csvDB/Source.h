#pragma once
#include "CsvDatabaseHandler.h"
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

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