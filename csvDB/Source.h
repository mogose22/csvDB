#pragma once
#include "CsvDatabaseHandler.h"
#include <Windows.h>

//поиск
const bool find(CsvDatabaseHandler const & db);
//вывод всей БД
const bool print(CsvDatabaseHandler const & db);
//вставка элемента
bool insert(CsvDatabaseHandler & db);
//удаление элемента
bool remove(CsvDatabaseHandler & db);
//обработчик вводимых команд
bool command_handler(CsvDatabaseHandler & db);
//отчистка экрана
bool clear();