// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <locale>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

struct clients {
	int id;
	char name;
	char phone;
};
struct services {
	int id;
	char name;
	float price;
};
struct payment {
	int id;
	int id_client;
	int id_service;
	float sum;
	char date;
};
struct spending {
	int id;
	int id_client;
	int id_service;
	float count;
	char date;
};

int main(void)
{
	setlocale(LC_ALL, "RUSSIAN");
	printf("Здравствуйте!\n");
	printf("Введите код для выполнения действия:\n");
	int act;
	int act2;
	std::ifstream usersFile("clients.txt");
	std::vector<std::string> users;

	while (true) {
		printf("1 - пользователи\n");
		printf("0 - выход\n");
		cin >> act;
		int back = 0;
		switch (act) {
			case 0:
				exit(1);
				break;
			case 1:

				while (back == 0) {
					printf("1 - список\n");
					printf("2 - добавить\n");
					printf("3 - изменить\n");
					printf("4 - удалить\n");
					printf("0 - назад\n");

					cin >> act2;

					switch (act2) {
						case 0:
							back = 1;
							break;
						case 1:

							if (!usersFile.is_open()) {
								cout << "Не открыт\n";
							} else {
								std::string line;
								int count = 0;
								while (std::getline(usersFile, line)) {
									users.push_back(line);
									count++;
								}
								for (int i = 0; i < count; i++) {
									cout << users[i] << '\n';
								}
							}

							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						default:
							printf("Неверное действие!\n");
					};
					printf("\n\n");
				}
				break;
			default:
				printf("Неверное действие!\n");
		}
		printf("\n\n");
	}
	usersFile.close();
	/*int array[n] = { 4,44,446,4466 };

	errno_t err;

	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	err = fopen_s(&stream, "d:\\aaa.txt", "r");
	for (int i = 0; i<n; i++)
		fprintf(stream, "%6.2d", array[i]);
	fclose(stream);*/


}
