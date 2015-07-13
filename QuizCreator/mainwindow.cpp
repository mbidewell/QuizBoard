#include <cstddef>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialog.h"
#include "editquestion.h"
#include "editcategory.h"
#include "ostream"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    categories(6)
{
    ui->setupUi(this);
    connect(ui->c1_100, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c1_200, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c1_300, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c1_400, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c1_500, SIGNAL (clicked()), this, SLOT (editQuestion()));

    connect(ui->c2_100, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c2_200, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c2_300, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c2_400, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c2_500, SIGNAL (clicked()), this, SLOT (editQuestion()));

    connect(ui->c3_100, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c3_200, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c3_300, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c3_400, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c3_500, SIGNAL (clicked()), this, SLOT (editQuestion()));

    connect(ui->c4_100, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c4_200, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c4_300, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c4_400, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c4_500, SIGNAL (clicked()), this, SLOT (editQuestion()));

    connect(ui->c5_100, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c5_200, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c5_300, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c5_400, SIGNAL (clicked()), this, SLOT (editQuestion()));
    connect(ui->c5_500, SIGNAL (clicked()), this, SLOT (editQuestion()));

    connect(ui->c6_100, &QPushButton::clicked, this, &MainWindow::editQuestion );
    connect(ui->c6_200, &QPushButton::clicked, this, &MainWindow::editQuestion );
    connect(ui->c6_300, &QPushButton::clicked, this, &MainWindow::editQuestion );
    connect(ui->c6_400, &QPushButton::clicked, this, &MainWindow::editQuestion );
    connect(ui->c6_500, &QPushButton::clicked, this, &MainWindow::editQuestion );


    connect(ui->category_1, SIGNAL (clicked()), this, SLOT (category1Edit()) );
    connect(ui->category_2, SIGNAL (clicked()), this, SLOT (category2Edit()) );
    connect(ui->category_3, SIGNAL (clicked()), this, SLOT (category3Edit()) );
    connect(ui->category_4, SIGNAL (clicked()), this, SLOT (category4Edit()) );
    connect(ui->category_5, SIGNAL (clicked()), this, SLOT (category5Edit()) );
    connect(ui->category_6, SIGNAL (clicked()), this, SLOT (category6Edit()) );

    connect(ui->showJson, &QPushButton::clicked, this, &MainWindow::showJson );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editQuestion()
{
    QObject *sender = QObject::sender();
    if(sender != NULL)
    {
        QString id = sender->objectName();
        EditQuestion *dialog = new EditQuestion(id, this);
        dialog->setText(questions[id]);
        int result = dialog->exec();

        if(result == QDialog::Accepted)
        {
            questions[id] = dialog->getText();
        }

        delete dialog;
    }

}

void MainWindow::editCategory(int idx)
{
    EditCategory *dialog = new EditCategory(this);
    dialog->setText(categories[idx]);
    int result = dialog->exec();

    if(result == QDialog::Accepted)
    {
        categories[idx] = dialog->getText();
    }

    delete dialog;
}

void MainWindow::showJson()
{
    ptree root;
    ptree cats;
    ptree quests;
    std::ostringstream os;

    for(std::vector<QString>::iterator it = categories.begin(); it != categories.end(); it++) {
        cats.push_back(std::make_pair("", it->toStdString()));
    }
    root.add_child("categories", cats);

    for(std::map<QString, QString>::iterator it = questions.begin(); it != questions.end(); it++) {
        quests.add_child(it->first.toStdString(), ptree(it->second.toStdString()));
    }
    root.add_child("questions", quests);

    write_json(os, root);
    EditQuestion *dialog = new EditQuestion("Quiz", this);
    QString json = QString(os.str().c_str());
    dialog->setText(json);
    dialog->setReadOnly(true);
    dialog->exec();

    delete dialog;
}
