#include "editquestion.h"
#include "ui_editquestion.h"

EditQuestion::EditQuestion(QString questId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditQuestion)
{
    ui->setupUi(this);
    this->setWindowTitle(questId);
}

EditQuestion::~EditQuestion()
{
    delete ui;
}

QString EditQuestion::getText()
{
    return ui->questText->toPlainText();
}

void EditQuestion::setText(const QString& text)
{
    ui->questText->setPlainText(text);
}
void EditQuestion::setReadOnly(bool readOnly)
{
    ui->questText->setReadOnly(readOnly);
}
