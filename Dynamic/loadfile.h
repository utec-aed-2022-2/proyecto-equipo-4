#ifndef LOADFILE_H
#define LOADFILE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QWidget; }
QT_END_NAMESPACE


class LoadFile : public QWidget
{
    Q_OBJECT
public:
    explicit LoadFile(QWidget *parent = nullptr);

signals:
private:
    Ui::QWidget* ui;
};

#endif // LOADFILE_H
