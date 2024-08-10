#include "TourList.h"
    // Конструктор класса по умолчанию, задает параметры по умолчанию
    TourList::TourList() {
        head = nullptr;
        size = 0;
    }
    // Деструктор класса, выполняет очистку памяти, выделенной для каждого узла списка
    TourList:: ~TourList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Метод класса, добавляющий тур в список
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
    // Метод списка, который выводит информацию о списке на экран
    void TourList:: displayTours() {
        Node* current = head;
        while (current != nullptr) {
            current->tour.displayInfo();
            current = current->next;
        }
    }
    // Сортировка списка по возрастанию
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
    // Сортировка списка по убыванию
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
    // Метод класса, бронирующий тур, передаваемый в качестве параметра
    void TourList:: bookTour(string NameOfTour, int numberOfPeople) {
        Node* current = head;
        Node* prev = nullptr;
        bool ticketsAvailable = false;

        while (current != nullptr) {
            if (current->tour.name == NameOfTour && current->tour.numberOfAvailableTickets >= numberOfPeople) {
                current->tour.numberOfAvailableTickets -= numberOfPeople;
                // Удаление тура из списка, если количество билетов<=0
                if (current->tour.numberOfAvailableTickets <= 0) {
                    if (prev == nullptr) {
                        // Если текущий элемент первый в списке
                        head = current->next;
                        delete current;
                        current = head;
                    }
                    else {
                        // Если текущий элемент не первый в списке
                        prev->next = current->next;
                        delete current;
                        current = prev->next;
                    }
                    size--;
                }
                else {
                    // Если билеты доступны, переход к следующему элменту
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
            cout << "Нет доступных билетов на тур!" << endl;
        }
        else {
            cout << "Тур забронирован на " << numberOfPeople << " человек!" << endl;
        }
    }
    // Сранение двух туров по цене
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
                    cout << nameoffirsttour << " дешевле " << nameofsecondtour << " на " << current->tour.priceOfTour - temp->tour.priceOfTour << endl;
                }
                else {
                    cout << nameofsecondtour << " дешевле " << nameoffirsttour << " на " << temp->tour.priceOfTour - current->tour.priceOfTour << endl;
                }
                return;
            }
            current = current->next;
            temp = temp->next;

        }
        if (!firsttourfound) {
            cout << "Тур с именем " << nameoffirsttour << " не найден!" << endl;
        }
        if (!secondtourfound) {
            cout << "Тур с именем " << nameofsecondtour << " не найден" << endl;
        }

    }
    //перегрузка оператора сравнения
    bool operator<(const Tour& firstTour, const Tour& secondTour) {
        return firstTour.priceOfTour < secondTour.priceOfTour;
    }
    //Функция принимает в качестве параметра константную ссылку на другой объект TourList и возвращает ссылку на текущий объект
    TourList& TourList::operator=(const TourList& other) {
        //проверка на случай, если текущий объект и переданный в качестве параметра объект равны.
        if (this == &other) {
            //если объекты совпадают, возвращается ссылка на текущий объект без выполнения дополнительных действий
            return *this;
        }
        // Очистка текущего списка
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        // Копирование данных из списка other
        Node* current = other.head;
        while (current != nullptr) {
            addTour(current->tour);
            current = current->next;
        }

        return *this;
    }
    //перегрузка оператора потока
    //функция принимает поток вывода out и константную ссылку на объект TourList, который будет выводиться
    ostream& operator<<(ostream& out, const TourList& tourList) {
        //объявление указателя current, который указывает на начало списка туров объекта tourList
        TourList::Node* current = tourList.head;
        while (current != nullptr) {
            out << "Название тура: " << current->tour.name << endl;
            out << "Количество доступных билетов: " << current->tour.numberOfAvailableTickets << endl;
            out << "Цена тура: " << current->tour.priceOfTour << endl;
            current = current->next;
        }
        return out;
    }

    // Вывод всех доступных туров по заданной стране
    void TourList:: informationFromCountry(string country)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->tour.country == country)
            {
                cout << "Название тура: " << current->tour.name << endl;
                cout << "Количество доступных билетов: " << current->tour.numberOfAvailableTickets << endl;
                cout << "Цена тура: " << current->tour.priceOfTour << endl;
            }
            current = current->next;

        }
    }
    //создает конкретный тип, заданный классом
    InheritedTour2* pPointer = new InheritedTour2;
    void test(Tour2* pPointer) {
        pPointer->displayTours();
    }
    test(pPointer);//передача объекта как абстрактного типа