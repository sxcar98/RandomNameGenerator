#include "randomnamegenerator.hpp"
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.setWindowTitle("点名器");
  QTextEdit *textBox = new QTextEdit;
  textBox->setReadOnly(true);
  QPushButton *btnPick = new QPushButton("随机点名（允许重复）");
  QPushButton *btnPickNoRecent = new QPushButton("随机点名（排除最近）");
  RandomNameGenerator gen;
  QObject::connect(btnPick, &QPushButton::clicked, [&]() {
    textBox->setText(QString::fromStdString(gen.gen()));
  });
  QObject::connect(btnPickNoRecent, &QPushButton::clicked, [&]() {
    textBox->setText(QString::fromStdString(gen.gen_no_recent()));
  });
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(textBox);
  layout->addWidget(btnPick);
  layout->addWidget(btnPickNoRecent);
  window.setLayout(layout);
  window.resize(400, 300);
  window.show();
  return app.exec();
}
