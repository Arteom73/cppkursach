// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
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

class Work {
    public:
        void showClients() {
        }
        void addClients() {
        }
        void editClients() {
        }
        void deleteClients() {
        }
};

struct clients {
	int id;
	string name;
	string phone;
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
	printf("������������!\n");
	printf("������� ��� ��� ���������� ��������:\n");
	int act;
	int act2;
	std::ifstream usersFile("clients.txt");
    std::vector<clients> cli;

	while (true) {
		printf("1 - ������������\n");
		printf("0 - �����\n");
		cin >> act;
		int back = 0;
		switch (act) {
			case 0:
				exit(1);
				break;
			case 1:

				while (back == 0) {
					printf("1 - ������\n");
					printf("2 - ��������\n");
					printf("3 - ��������\n");
					printf("4 - �������\n");
					printf("0 - �����\n");

					cin >> act2;

					switch (act2) {
						case 0:
							back = 1;
							break;
						case 1:

							if (!usersFile.is_open()) {
								cout << "�� ������\n";
							} else {
								std::string line;
								std::string line2;
								int count = 0;
								while (std::getline(usersFile, line)) {
									//users.push_back(line);
									stringstream ss(line);
                                    int i = 0;
									cli.push_back(clients());
									while (std::getline(ss, line2, ';')) {
                                        //cout << line2 << '\n';
                                        if(i == 0) {
                                            cli[count].id = atoi(line2.c_str());
                                        }
                                        if(i == 1)
                                            cli[count].name = line2;
                                        if(i == 2)
                                            cli[count].phone = line2;
                                        i++;
									}
									count++;
								}

								for (int i = 0; i < count; i++) {
                                    cout << "�����: " << cli[i].id << '\n';
                                    cout << "���: " << cli[i].name << '\n';
                                    cout << "�������: " << cli[i].phone << '\n';
                                    cout << '\n';
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
							printf("�������� ��������!\n");
					};
					printf("\n\n");
				}
				break;
			default:
				printf("�������� ��������!\n");
		}
		printf("\n\n");
	}
	usersFile.close();
}
