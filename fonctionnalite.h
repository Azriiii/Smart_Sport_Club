#ifndef FONCTIONNALITE_H
#define FONCTIONNALITE_H

#include <QDialog>

namespace Ui {
class fonctionnalite;
}

class fonctionnalite : public QDialog
{
    Q_OBJECT

public:
    explicit fonctionnalite(QWidget *parent = nullptr);
    ~fonctionnalite();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fonctionnalite *ui;
};

#endif // FONCTIONNALITE_H
