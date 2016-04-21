#pragma once

#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>


class Simple : public QWidget {
    
  Q_OBJECT

  public:
    Simple(QWidget *parent = 0);

  private slots:
    void OnPlus();
    void OnMinus();

  private:
    QLabel *lbl;

};
