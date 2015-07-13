#ifndef EDITQUESTION_H
#define EDITQUESTION_H

#include <QDialog>
#include <map>

namespace Ui {
class EditQuestion;
}

class EditQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit EditQuestion(QString questId, QWidget *parent = 0);
    ~EditQuestion();

    QString getText();
    void setText(const QString& text);
    void setReadOnly(bool readOnly);

private:
    Ui::EditQuestion *ui;

};

#endif // EDITQUESTION_H
