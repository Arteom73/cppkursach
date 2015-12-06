#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
struct Clients
{
    int id;
    string name;
    int phone;
    Clients *nextClient;
    Clients *prevClient;
};
Clients *headClient;

struct Services {
	int id;
	char name;
	float price;
	Services *nextService;
    Services *prevService;
};
Clients *headService;

struct Payment {
	int id;
	int id_client;
	int id_service;
	float sum;
	int date;
	Payment *nextPayment;
    Payment *prevPayment;
};
Clients *headPayment;

struct Spending {
	int id;
	int id_client;
	int id_service;
	float count;
	int date;
	Spending *nextSpending;
    Spending *prevSpending;
};
Clients *headSpending;

class Work {
    private:
        int clientsCount = 0;
        int servicesCount = 0;
        int paymentCount = 0;
        int spendingCount = 0;
    public:
        void loadClients(string file) {
            Clients *node = new Clients;
            string client;
            ifstream usersFile(file.c_str());
            while (std::getline(usersFile, client)) {
                stringstream item(client);
                string id;
                string name;
                string phone;
                getline(item, id, ';');
                getline(item, name, ';');
                getline(item, phone, ';');
                this->addClients(name, atoi(phone.c_str()), atoi(id.c_str()));
            }
            cout << "\������� ���������...\n\n";
        }
        void showClients() {
            if (headClient == NULL)
            {
                cout << "\n������ ����\n\n";
            }
            else
            {
                Clients *a = headClient;
                cout << "\n�������� ������: " << endl;
                do
                {
                    cout << "ID: " << a->id << '\n';
                    cout << "NAME: " << a->name << '\n';
                    cout << "PHONE: " << a->phone << '\n';
                    a = a->nextClient;
                } while(a != headClient);
                cout << "\n\n";
            }
        }
        void addClients(string name, int phone, int id) {
            Clients *node = new Clients;
            if(id == -1)
            {
                clientsCount++;
            }
            else
            {
                clientsCount = id;
            }


            node->id = clientsCount;
            node->name = name;
            node->phone = phone;
            if (headClient == NULL)
            {
                node->nextClient = node;
                node->prevClient = node;
                headClient = node;
            }
            else
            {
                Clients *p = headClient;
                for(int i = clientsCount; i > 1; i--)
                {
                    p = p->nextClient;
                }
                p->prevClient->nextClient = node;
                node->prevClient = p->prevClient;
                node->nextClient = p;
                p->prevClient = node;
            }
            cout << "\������ ��������...\n\n";
        }
        void editClients() {
        }
        int deleteClients(int position) {
            if (headClient == NULL)
            {
                cout << "\n������ ����\n\n";
                return 0;
            }
            if (headClient == headClient->nextClient)
            {
                delete headClient;
                headClient = NULL;
            }
            else
            {
                Clients *a = headClient;
                for (int i = position; i > 1; i--)
                {
                    a = a->nextClient;
                }
                if (a == headClient)
                {
                    headClient = a->nextClient;
                }
                a->prevClient->nextClient = a->nextClient;
                a->nextClient->prevClient = a->prevClient;
                delete a;
            }
            cout << "\n������� ������...\n\n";
        }
};

int main(void)
{
    setlocale(LC_ALL, "rus");
    int x, y;
    Work work;
    string name;
    do
    {
        cout << "1. ������� ��������" << endl;
        cout << "2. ������� �����" << endl;
        cout << "3. ������� �����" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. ����� �������������" << endl;
        cout << "6. ����� �� �������" << endl;
        cout << "0. �����" << endl;
        cout << "\n����� �������� > ";
        cin >> x;
        switch (x)
        {
        case 1:
            do
            {
                cout << "1. ��������� �� �����" << endl;
                cout << "2. ��������" << endl;
                cout << "3. �������������" << endl;
                cout << "4. �������" << endl;
                cout << "5. ������" << endl;
                cout << "6. ��������� � ����" << endl;
                cout << "0. �����" << endl;
                cout << "\n����� �������� > ";
                cin >> y;
                switch (y)
                {
                case 1:
                    {
                        string path;
                        cout << "���� � ����� > ";
                        cin >> path;
                        work.loadClients(path);
                        break;
                    }
                case 2:
                    {
                        string name;
                        int phone;
                        cout << "NAME > ";
                        cin >> name;
                        cout << "PHONE > ";
                        cin >> phone;
                        work.addClients(name, phone, -1);
                        break;
                    }
                case 3:
                    {
                        work.editClients();
                        break;
                    }
                case 4:
                    int position;
                    cout << "ID > ";
                    cin >> position;
                    work.deleteClients(position);
                    break;
                case 5:
                    work.showClients();
                case 6:
                    //work.saveClients();
                    break;
                }
            } while (y!=0);
        case 2:
            break;
        case 3:
            break;
        }
    } while (x!=0);
}
