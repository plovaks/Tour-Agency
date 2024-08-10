#include "TourList.h"
    // ����������� ������ �� ���������, ������ ��������� �� ���������
    TourList::TourList() {
        head = nullptr;
        size = 0;
    }
    // ���������� ������, ��������� ������� ������, ���������� ��� ������� ���� ������
    TourList:: ~TourList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // ����� ������, ����������� ��� � ������
    bool TourList::addTour(Tour tour) {
        Node* newNode = new Node;
        newNode->tour = tour;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
        return true;
    }
    // ����� ������, ������� ������� ���������� � ������ �� �����
    void TourList:: displayTours() {
        Node* current = head;
        while (current != nullptr) {
            current->tour.displayInfo();
            current = current->next;
        }
    }
    // ���������� ������ �� �����������
    void TourList:: sortAscending() {
        for (int i = 0; i < size - 1; i++) {
            Node* current = head;
            Node* nextNode = head->next;

            for (int j = 0; j < size - 1 - i; j++) {
                if (current->tour.priceOfTour > nextNode->tour.priceOfTour) {
                    swap(current->tour, nextNode->tour);
                }

                current = nextNode;
                nextNode = nextNode->next;
            }
        }
    }
    // ���������� ������ �� ��������
    void TourList:: sortDescending() {
        for (int i = 0; i < size - 1; i++) {
            Node* current = head;
            Node* nextNode = head->next;

            for (int j = 0; j < size - 1 - i; j++) {
                if (current->tour.priceOfTour < nextNode->tour.priceOfTour) {
                    swap(current->tour, nextNode->tour);
                }

                current = nextNode;
                nextNode = nextNode->next;
            }
        }
    }
    // ����� ������, ����������� ���, ������������ � �������� ���������
    void TourList:: bookTour(string NameOfTour, int numberOfPeople) {
        Node* current = head;
        Node* prev = nullptr;
        bool ticketsAvailable = false;

        while (current != nullptr) {
            if (current->tour.name == NameOfTour && current->tour.numberOfAvailableTickets >= numberOfPeople) {
                current->tour.numberOfAvailableTickets -= numberOfPeople;
                // �������� ���� �� ������, ���� ���������� �������<=0
                if (current->tour.numberOfAvailableTickets <= 0) {
                    if (prev == nullptr) {
                        // ���� ������� ������� ������ � ������
                        head = current->next;
                        delete current;
                        current = head;
                    }
                    else {
                        // ���� ������� ������� �� ������ � ������
                        prev->next = current->next;
                        delete current;
                        current = prev->next;
                    }
                    size--;
                }
                else {
                    // ���� ������ ��������, ������� � ���������� �������
                    prev = current;
                    current = current->next;
                }
                ticketsAvailable = true;
            }
            else {
                prev = current;
                current = current->next;
            }
        }

        if (!ticketsAvailable) {
            cout << "��� ��������� ������� �� ���!" << endl;
        }
        else {
            cout << "��� ������������ �� " << numberOfPeople << " �������!" << endl;
        }
    }
    // �������� ���� ����� �� ����
    void TourList::compareTwoToursByCosts(string nameoffirsttour, string nameofsecondtour) {
        Node* current = head;
        Node* temp = current->next;
        bool firsttourfound = false;
        bool secondtourfound = false;
        while (current != nullptr && temp != nullptr)
        {
            if (current->tour.name == nameoffirsttour)
            {
                firsttourfound = true;
            }
            if (temp->tour.name == nameofsecondtour)
            {
                secondtourfound = true;
            }
            if (firsttourfound && secondtourfound) {
                if (current->tour.priceOfTour > temp->tour.priceOfTour) {
                    cout << nameoffirsttour << " ������� " << nameofsecondtour << " �� " << current->tour.priceOfTour - temp->tour.priceOfTour << endl;
                }
                else {
                    cout << nameofsecondtour << " ������� " << nameoffirsttour << " �� " << temp->tour.priceOfTour - current->tour.priceOfTour << endl;
                }
                return;
            }
            current = current->next;
            temp = temp->next;

        }
        if (!firsttourfound) {
            cout << "��� � ������ " << nameoffirsttour << " �� ������!" << endl;
        }
        if (!secondtourfound) {
            cout << "��� � ������ " << nameofsecondtour << " �� ������" << endl;
        }

    }
    //���������� ��������� ���������
    bool operator<(const Tour& firstTour, const Tour& secondTour) {
        return firstTour.priceOfTour < secondTour.priceOfTour;
    }
    //������� ��������� � �������� ��������� ����������� ������ �� ������ ������ TourList � ���������� ������ �� ������� ������
    TourList& TourList::operator=(const TourList& other) {
        //�������� �� ������, ���� ������� ������ � ���������� � �������� ��������� ������ �����.
        if (this == &other) {
            //���� ������� ���������, ������������ ������ �� ������� ������ ��� ���������� �������������� ��������
            return *this;
        }
        // ������� �������� ������
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        // ����������� ������ �� ������ other
        Node* current = other.head;
        while (current != nullptr) {
            addTour(current->tour);
            current = current->next;
        }

        return *this;
    }
    //���������� ��������� ������
    //������� ��������� ����� ������ out � ����������� ������ �� ������ TourList, ������� ����� ����������
    ostream& operator<<(ostream& out, const TourList& tourList) {
        //���������� ��������� current, ������� ��������� �� ������ ������ ����� ������� tourList
        TourList::Node* current = tourList.head;
        while (current != nullptr) {
            out << "�������� ����: " << current->tour.name << endl;
            out << "���������� ��������� �������: " << current->tour.numberOfAvailableTickets << endl;
            out << "���� ����: " << current->tour.priceOfTour << endl;
            current = current->next;
        }
        return out;
    }

    // ����� ���� ��������� ����� �� �������� ������
    void TourList:: informationFromCountry(string country)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->tour.country == country)
            {
                cout << "�������� ����: " << current->tour.name << endl;
                cout << "���������� ��������� �������: " << current->tour.numberOfAvailableTickets << endl;
                cout << "���� ����: " << current->tour.priceOfTour << endl;
            }
            current = current->next;

        }
    }
    //������� ���������� ���, �������� �������
    InheritedTour2* pPointer = new InheritedTour2;
    void test(Tour2* pPointer) {
        pPointer->displayTours();
    }
    test(pPointer);//�������� ������� ��� ������������ ����