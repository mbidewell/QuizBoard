#ifndef EDITCATEGORY_H
#define EDITCATEGORY_H

#include <QDialog>

namespace Ui {
class EditCategory;
}

class EditCategory : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategory(QWidget *parent = 0);
    ~EditCategory();

    QString getText();
    void setText(const QString& text);

private:
    Ui::EditCategory *ui;
};

#endif // EDITCATEGORY_H
