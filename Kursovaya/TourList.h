#pragma once
#include "Tour.h"

//узловой класс
class TourList {
private:
    struct Node {
        Tour tour;// Данные о туре
        Node* next;
    };
    Node* head;
    int size;
public:
    TourList();
    ~TourList();
    virtual bool addTour(Tour tour) = 0;
    virtual void displayTours() = 0;
    virtual void sortAscending() = 0;
    virtual void sortDescending() = 0;
    virtual void bookTour(std::string NameOfTour, int numberOfPeople) = 0;
    virtual void compareTwoToursByCosts(std::string nameOfFirstTour, std::string nameOfSecondTour) = 0;
    virtual void informationFromCountry(std::string country) = 0;
    bool operator<(const Tour& firstTour, const Tour& secondTour);
    friend std::ostream& operator<<(std::ostream& out, const TourList& tourList);
    
};
class GroupTour :public TourList {
private:
    struct GroupNode {
        Tour tour;
        int groupSize;
        GroupNode* next;
    };
    GroupNode* groupHead;
    int groupSize;
public:
    GroupTour();
    ~GroupTour();
    virtual bool addGroupTour(Tour tour, int groupSize);
   virtual void displayGroupTours();
    virtual void bookGroupTour(std::string NameOfTour, int numberOfPeople);
   virtual void compareTwoGroupToursByCosts(string nameOfFirstTour,string nameOfSecondTour);
   virtual void informationFromCountryForGroup(string country);
   
   
   
};
//интерфейсный класс
class Tour2 {
public:
    virtual bool addTour(Tour tour) = 0;
    virtual void displayTours() = 0;
    virtual void sortAscending() = 0;
    virtual void sortDescending() = 0;
    virtual void bookTour(std::string NameOfTour, int numberOfPeople) = 0;
    virtual void compareTwoToursByCosts(std::string nameOfFirstTour, std::string nameOfSecondTour) = 0;
    virtual void informationFromCountry(std::string country) = 0;
};
//узловой класс
class InheritedTour2 :public Tour2 {
private:
    struct Node {
        Tour tour;// Данные о туре
        Node* next;
    };
    Node* head;
    int size;
public:
    virtual bool addTour(Tour tour);
    virtual void displayTours() ;
    virtual void sortAscending() ;
    virtual void sortDescending() ;
    virtual void bookTour(std::string NameOfTour, int numberOfPeople) ;
    virtual void compareTwoToursByCosts(std::string nameOfFirstTour, std::string nameOfSecondTour) ;
    virtual void informationFromCountry(std::string country) ;
};


