#pragma once
#include "Service.h"
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>


class GUI : public  QWidget{
private:
    Service& service;

    QListWidget* list = new QListWidget();
    QLineEdit* codeLine = new QLineEdit();
    QLineEdit* nameLine = new QLineEdit();
    QLineEdit* solarSystemLine = new QLineEdit();
    QLineEdit* massLine = new QLineEdit();
    QLineEdit* diameterLine = new QLineEdit();

    vector<QPushButton*> buttons;
    QVBoxLayout* thirdRow = new QVBoxLayout();
    QPushButton* sortByMassButton = new QPushButton("Sort By mass");
    QPushButton* sortByDiameterButton = new QPushButton("Sort By diameter");
    QPushButton* sortByNameButton = new QPushButton("Sort By name");

    void loadData(vector<Planet> planets);
    void generateButtons();
    void initGUI();
    void initConnect();
public:
    GUI(Service& service) : service(service) {
        initGUI();
        loadData(service.getAllPlanets());
        initConnect();
        generateButtons();
    };
};
