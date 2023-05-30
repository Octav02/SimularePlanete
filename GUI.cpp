//
// Created by octav on 25.05.2023.
//

#include "GUI.h"

void GUI::initConnect() {
    QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
        if (list->selectedItems().isEmpty()) {
            codeLine->setText("");
            nameLine->setText("");
            solarSystemLine->setText("");
            massLine->setText("");
            diameterLine->setText("");
            return;
        }
        auto item = list->selectedItems().at(0);
        string line = item->text().toStdString();
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        int code = stoi(token);
        Planet planet = service.getPlanet(code);
        codeLine->setText(QString::fromStdString(to_string(planet.getCode())));
        nameLine->setText(QString::fromStdString(planet.getName()));
        solarSystemLine->setText(QString::fromStdString(planet.getSolarSystem()));
        massLine->setText(QString::fromStdString(to_string(planet.getMass())));
        diameterLine->setText(QString::fromStdString(to_string(planet.getDiameter())));
    });

    QObject::connect(sortByNameButton, &QPushButton::clicked, [&]() {
        loadData(service.sortByName());
    });

    QObject::connect(sortByMassButton, &QPushButton::clicked, [&]() {
        loadData(service.sortByMass());
    });

    QObject::connect(sortByDiameterButton, &QPushButton::clicked, [&]() {
        loadData(service.sortByDiameter());
    });
}

void GUI::initGUI() {
    auto mainLayout = new QHBoxLayout();
    auto firstRow = new QVBoxLayout();
    auto linesLayout = new QHBoxLayout();
    linesLayout->addWidget(codeLine);
    linesLayout->addWidget(nameLine);
    linesLayout->addWidget(solarSystemLine);
    linesLayout->addWidget(massLine);
    linesLayout->addWidget(diameterLine);
    firstRow->addWidget(list);
    firstRow->addLayout(linesLayout);
    mainLayout->addLayout(firstRow);

    auto secondRow = new QHBoxLayout();
    secondRow->addWidget(sortByMassButton);
    secondRow->addWidget(sortByDiameterButton);
    secondRow->addWidget(sortByNameButton);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    setLayout(mainLayout);
}

void GUI::loadData(vector<Planet> planets) {
    list->clear();
    for (auto &planet: planets) {
        string lineText = to_string(planet.getCode()) + " " + planet.getName();
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(lineText));
        //Set font size
        if (planet.getMass() <= 10)
            item->setFont(QFont("Times", 12));
        else if (planet.getMass() <= 100)
            item->setFont(QFont("Times", 16));
        else if (planet.getMass() <= 1000)
            item->setFont(QFont("Times", 20));
        else
            item->setFont(QFont("Times", 24));
        list->addItem(item);
    }
    generateButtons();
}

void GUI::generateButtons() {
    auto buttonElements = service.getPlanetBySolarSystem();
    for (auto button : buttons)
        delete button;
    buttons.clear();
    for (auto &buttonElement : buttonElements) {
        auto button = new QPushButton(QString::fromStdString(buttonElement.first));
        vector<Planet> planets = buttonElement.second;
        string message;
        for (auto &planet : planets)
            message += planet.getName() + ",";
        message[message.size() - 1] = '\0';
        buttons.push_back(button);
        QObject::connect(button, &QPushButton::clicked, [&, buttonElement, message]() {
            QMessageBox::information(this, QString::fromStdString(buttonElement.first), QString::fromStdString(message));
        });
    }
    for (auto button : buttons)
        thirdRow->addWidget(button);
}
