#ifndef UPDATER_H
#define UPDATER_H

#include <QDialog>

namespace Ui {
class Updater;
}

class Updater : public QDialog
{
    Q_OBJECT

public:
    explicit Updater(QWidget *parent = nullptr);
    ~Updater();

private:
    Ui::Updater *ui;
};

#endif // UPDATER_H
