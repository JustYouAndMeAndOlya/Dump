#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <math.h>
using namespace std;
int m=6;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ifstream fin;
    mas = new float*[m];
    for (int i=0;i<m;i++)
        mas[i]=new float[m];

        fin.open("C:/Users/Tom/Documents/pr/date.txt");
        for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                {
                    fin >> mas[i][j];
                }
        fin.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    for (int i = 0; i < m; i++)
                delete[] mas[i];
}

void MainWindow::on_pushButton_5_clicked()//show matrix
{
    /*int norma =4;
    QString str = "NORMA MATRIX IS:";
    QString st;
    st=QString::number(norma);
    ui->textBrowser->setText(str+st);*/
    QFile file("C:\\Users\\Tom\\Documents\\pr\\date.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_4_clicked()//norma matrix
{

    float *tempmas = new float[m];
    float norma = 0;
    for (int i = 0; i < m; i++)
    {
        tempmas[i] = 0;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            tempmas[i] += abs(mas[i][j]);


    for (int i = 0; i < m; i++)
    {
        for (int j = i+1; j < m;j++)
        {
            if (tempmas[i] > tempmas[j])
                norma = tempmas[i];
            if(tempmas[i] < tempmas[j])
                norma = tempmas[j];
        }

    }
for(int ii=0;ii< m;ii++)
    if(norma<tempmas[ii])
        norma=tempmas[ii];
    QString str = tr("Норма матрицы равна:");
    QString st;
    st=QString::number(norma);
    ui->textBrowser_3->setText(str+st);
    delete[]tempmas;

}

void MainWindow::on_pushButton_3_clicked()//swap raw matrix
{
    ofstream fout;
    float *haraktstolbS = new float[m];
                for (int count = 0; count < m; count++)
                    haraktstolbS[count] = 0;

                for (int j = 0; j < m; j++)
                {
                    int i = 0;
                    int nomer = 1;
                    while (nomer<m)
                    {
                        //if (mas[2 * i + 1][j] < 0)
                            haraktstolbS[j] += mas[2 * i + 1][j];
                        i++;
                        nomer = 2 * i + 1;
                    }

                }
            for (int iu=0;iu<m;iu++)
                cout<<haraktstolbS[iu]<<endl;

                for (int i = 0; i < m; i++)
                {
                    for (int j = i+1; j < m; j++)
                    {
                        if (haraktstolbS[i] > haraktstolbS[j])
                         {
                            swap(haraktstolbS[i],haraktstolbS[j]);
                            for (int ii = 0; ii < m; ii++)

                                swap(mas[ii][i], mas[ii][j]);

                        }

                    }
                }

                fout.open("C:/Users/Tom/Documents/pr/1.txt");
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < m; j++)
                    {

                        if (j == m - 1)
                            fout << " " << mas[i][j] << endl;
                        else
                            fout << " " << mas[i][j];
                    }
                fout.close();
    QFile file("C:\\Users\\Tom\\Documents\\pr\\1.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser_2->setText(in.readAll());
          delete[]haraktstolbS;

}

void MainWindow::on_pushButton_2_clicked()//уменьшение размерности матрицы
{
    int n;
    n=m-1;
    ofstream fout;
    fout.open("C:/Users/Tom/Documents/pr/zapismatr.txt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {

            if (j == n - 1)
                fout << " " << mas[i][j] << endl;
            else
                fout << " " << mas[i][j];
        }
    fout.close();
    QFile file("C:\\Users\\Tom\\Documents\\pr\\zapismatr.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());

}

void MainWindow::on_pushButton_6_clicked()//увеличение размерности матрицы
{
    int n;
    n=m+1;

   float **arr= new float*[n];
    for(int i=0;i<n;i++)
        arr[i]=new float[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if((j<m)&&(i<m))
                arr[i][j] = mas[i][j];
            if((j==n-1)&&(i<m))
                arr[i][j]=-1;
            if((j==n-1)&&(i==n-1))
                arr[i][j] = 1;
            if((i==n-1)&&(j<m))
            {
                if(j/2==0)
                    arr[i][j]=0;
                else
                    arr[i][j]=1;
            }
        }

    ofstream fout;
    fout.open("C:/Users/Tom/Documents/pr/zapismatr.txt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {

            if (j == n - 1)
                fout << " " << arr[i][j] << endl;
            else
                fout << " " << arr[i][j];
        }
    fout.close();
    QFile file("C:\\Users\\Tom\\Documents\\pr\\zapismatr.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}
