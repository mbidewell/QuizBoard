#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::map<QString, QString> questions;
    std::vector<QString> categories;

    void editCategory(int idx);

private slots:
    void editQuestion();
    void showJson();
    void category1Edit(){editCategory(0);};
    void category2Edit(){editCategory(1);};
    void category3Edit(){editCategory(2);};
    void category4Edit(){editCategory(3);};
    void category5Edit(){editCategory(4);};
    void category6Edit(){editCategory(5);};
};

#endif // MAINWINDOW_H
