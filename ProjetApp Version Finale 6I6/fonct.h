#ifndef FONCTIONANALITE_H
#define FONCTIONANALITE_H

#include <QDialog>

namespace Ui {
class fonct;
}

class fonct : public QDialog
{
    Q_OBJECT

public:
    explicit fonct(QWidget *parent = nullptr);
    ~fonct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fonct *ui;
};

#endif // FONCTIONANALITE_H
