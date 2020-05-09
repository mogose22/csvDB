#include "Source.h"


int main() {
	setlocale(LC_ALL, "Russian");
	CsvDatabaseHandler db("test.csv");
	db.PrintDB();

	return 0;
}