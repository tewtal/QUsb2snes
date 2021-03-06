#ifndef DIRCHANGEDIALOG_H
#define DIRCHANGEDIALOG_H

#include <QDialog>
#include "usb2snes.h"
#include "usb2snesfilemodel.h"

namespace Ui {
class DirChangeDialog;
}

class DirChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DirChangeDialog(USB2snes* usb, QWidget *parent = nullptr);
    ~DirChangeDialog();
    QString getDir();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::DirChangeDialog *ui;
    USB2snes*   usb2snes;
    Usb2SnesFileModel*  uModel;
};

#endif // DIRCHANGEDIALOG_H
