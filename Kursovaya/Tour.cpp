#include "Tour.h"
using namespace std;
// ����� Tour � ����������� � ����
   Tour:: Tour() {
        name = "";
        country = "";
        numberOfPassengers = 0;
        priceOfTour = 0.0;
        numberOfAvailableTickets = 0;
    }
    // ����������� ��� ������������� �������� ������ � ���������� ����������
   Tour:: Tour(string name, string country, int numberOfPassengers, double priceOfTour, int numberOfAvailableTickets) {
        // ������������ �������� ���������� ����� ������
        this->name = name;
        this->country = country;
        this->numberOfPassengers = numberOfPassengers;
        this->priceOfTour = priceOfTour;
        this->numberOfAvailableTickets = numberOfAvailableTickets;
    }
    // ����������� ����� ������ �� �����
    void Tour:: displayInfo() {
        cout << "�������� ����: " << name << endl;
        cout << "������: " << country << endl;
        cout << "���������� ��������: " << numberOfPassengers << endl;
        cout << "����: " << priceOfTour << endl;
        cout << "���������� ���������� ����: " << numberOfAvailableTickets << endl;
        cout << "------------------------" << endl;
    }
