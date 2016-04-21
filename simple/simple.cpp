#include "simple.h"

Simple::Simple(QWidget *parent) : QWidget(parent) {
	
	
   QPushButton *plsBtn = new QPushButton("+", this);
   QPushButton *minBtn = new QPushButton("-", this);
   lbl = new QLabel("0", this);

   QPushButton *quitBtn = new QPushButton("Quit", this);
   quitBtn->setGeometry(50, 40, 75, 30);

   connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
  connect(plsBtn, &QPushButton::clicked, this, &Simple::OnPlus);
  connect(minBtn, &QPushButton::clicked, this, &Simple::OnMinus);
    
  QFrame *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  QFrame *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  QFrame *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  QGridLayout *grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 0, 1);
  grid->addWidget(frame3, 0, 2);
  grid->addWidget(plsBtn, 1, 0);
  grid->addWidget(minBtn, 1, 1);
  grid->addWidget(lbl, 1, 2);
  grid->addWidget(quitBtn, 2, 2);

  setLayout(grid);
 
}

void Simple::OnPlus() {
    
  int val = lbl->text().toInt();
  val++;
  lbl->setText(QString::number(val));
}

void Simple::OnMinus() {
    
  int val = lbl->text().toInt();
  val--;
  lbl->setText(QString::number(val));
}

int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);

    Simple window;

    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.setToolTip("Simple example");
    window.setWindowIcon(QIcon("Qt.png"));
    window.show();

    return app.exec();
}
