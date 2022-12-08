#include "gamewindow.h"

#include <ctime>
#include <iostream>
#include <random>

#include "mainwindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : FrameLessWindow(parent), ui(new Ui::GameWindow) {
  ui->setupUi(this);
  // 固定窗口大小
  this->setFixedSize(800, 600);
  // 去除自带的边框
  this->setWindowFlag(Qt::FramelessWindowHint);
  // 创建窗口
  hypercube_ = new Hypercube::Hypercube(this);
  hypercube_->setFixedSize(562, 562);
  hypercube_->setGeometry(19, 19, hypercube_->width(), hypercube_->height());

  board = new Board();
  board->SetHypercube(hypercube_);

  // ----- demo begin -----
  QTimer *timer_init_hypercube = new QTimer(this);
  connect(timer_init_hypercube, &QTimer::timeout, [&]() {
    static int i = 0;
    i++;
    if (i == 5) {
      board->InitHypercube();
    }
  });
  timer_init_hypercube->start(100);
  // ----- demo end -----
  std::cout << "qwq" << std::endl;
}

void GameWindow::mousePressEvent(QMouseEvent *event) {
  int x = event->x();
  int y = event->y();
  std::cout << "mouse cliked on:" << x << " " << y << std::endl;
}

GameWindow::~GameWindow() { delete ui; }

void GameWindow::on_btnReturn_clicked() {
  MainWindow *mw = dynamic_cast<MainWindow *>(this->parent());
  mw->show();
  delay(20);
  this->close();
}
