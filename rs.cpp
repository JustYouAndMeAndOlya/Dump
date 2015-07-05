#include "rs.h"
#include <QtGui>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>
#include <fstream>
#include <QFile>
using namespace std;

int const size=4;
int n=4,m=4;


rs::rs(QWidget *parent)
    : QDialog(parent)
{
    ifstream fin;
    fin.open("D:/demo/untitled4/1.txt");
    mas = new float*[n];
    for(int i=0;i<m;i++)
        mas[i]=new float[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            fin >> mas[i][j];
        }

    btn1 = new QPushButton(tr("Show Matrix"));
    btn2 = new QPushButton(tr("Norma Matrix"));
    btn3 = new QPushButton(tr("Swap Matrix"));
    btn4 = new QPushButton(tr("Save Matrix"));

    connect(btn1,SIGNAL(clicked()),this,SLOT(show_matrix()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(norma()));
    connect(btn3,SIGNAL(clicked()),this,SLOT(swap_matrix()));
    connect(btn4,SIGNAL(clicked()),this,SLOT(save_matrix()));

    QVBoxLayout *leftLay = new QVBoxLayout;
    leftLay->addWidget(btn1);
    leftLay->addWidget(btn2);
    leftLay->addWidget(btn3);
    leftLay->addWidget(btn4);
    leftLay->addStretch();

    QHBoxLayout *mainLay= new QHBoxLayout;
    mainLay->addLayout(leftLay);
    setLayout(mainLay);
    setWindowTitle(tr("MATRIX"));
    fin.close();
}

void rs::norma()
{
    ofstream fout;
    fout.open("D:/demo/untitled4/2.txt");
    float *tempmas = new float[n];
    float norma = 0;
    for (int i = 0; i < n; i++)
    {
        tempmas[i] = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tempmas[i] += abs(mas[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n;j++)
            if (tempmas[i] >= tempmas[j])
                norma = tempmas[i];
            else
                norma = tempmas[j];

    }
    cout << endl;

    QString st;
    st=QString::number(norma);
    QMessageBox::information(this, tr("Норма матрицы"),st,tr("Ok"));
    fout<< " Норма матрицы = " <<endl;
    fout<<norma;
    //cout << "norma = " << norma << endl;
    fout.close();
    delete[]tempmas;

}

void rs::show_matrix()
{

    QMessageBox::information(this, tr(" Вывод матрицы "), tr("см на консоль приложения"),tr("Ok"));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1)
                cout << " " << mas[i][j] << endl;
            else
                cout << " " << mas[i][j];
       }
    cout<<endl;

}

void rs::swap_matrix()
{
    QMessageBox::information(this, tr("Перестановка столбцов матрицы"), tr("см консоль приложения"),tr("Ok"));
    float *haraktstolbS = new float[n];
            for (int count = 0; count < n; count++)
                haraktstolbS[count] = 0;

            for (int j = 0; j < n; j++)
            {
                int i = 0;
                int nomer = 1;
                while (nomer<n)
                {
                    if (mas[2 * i + 1][j] < 0)
                        haraktstolbS[j] += mas[2 * i + 1][j];
                    i++;
                    nomer = 2 * i + 1;
                }

            }
            // вывод характеристик столбцов
            /*for (int count = 0; count < n; count++)
                cout << " " << haraktstolbS[count];
            cout << endl;
            cout << endl;*/
            //перестановка столбцов
            for (int i = 0; i < n; i++)
            {
                for (int j = i+1; j < n; j++)
                {
                    if (haraktstolbS[i]>haraktstolbS[j])
                    for (int ii = 0; ii < n; ii++)
                        swap(mas[ii][i], mas[ii][j]);
                }
            }
            // вывод матрицы
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {

                    if (j == m - 1)
                        cout << " " << mas[i][j] << endl;
                    else
                        cout << " " << mas[i][j];
                }
            cout << endl;
            delete[]haraktstolbS;

}
void rs::save_matrix()
{
    QMessageBox::information(this, tr("Сохранение матрицы в файл"), tr("см 2.txt"),tr("Ok"));
    ofstream fout;
    fout.open("D:/demo/untitled4/2.txt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {

            if (j == m - 1)
                fout << " " << mas[i][j] << endl;
            else
                fout << " " << mas[i][j];
        }
    fout<<"Матрица после перестановки столбцов";
    fout<<endl;
    fout.close();
}

rs::~rs()
{
    for (int i = 0; i < n; i++)
            delete[] mas[i];

}
