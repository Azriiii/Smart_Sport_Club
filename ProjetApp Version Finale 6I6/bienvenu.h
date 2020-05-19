#ifndef BIENVENU_H
#define BIENVENU_H

#include <QMainWindow>

namespace Ui {
class bienvenu;
}

class bienvenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit bienvenu(QWidget *parent = nullptr);
    ~bienvenu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::bienvenu *ui;
};

#endif // BIENVENU_H
