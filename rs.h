#ifndef RS_H
#define RS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>

class rs : public QDialog
{
    Q_OBJECT

public:
    rs(QWidget *parent = 0);
    ~rs();
private slots:
    void show_matrix();
    void norma();
    void swap_matrix();
    void save_matrix();
private:
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    float **mas;

};

#endif // RS_H
