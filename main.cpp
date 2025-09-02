#include "namepicker.hpp"
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("点名器");

  // 文本框
  QTextEdit *textBox = new QTextEdit;
  textBox->setReadOnly(true);

  // 按钮
  QPushButton *btnPick = new QPushButton("随机点名（允许重复）");
  QPushButton *btnPickNoRecent = new QPushButton("随机点名（排除最近）");

  // NamePicker 实例
  NamePicker picker;

  // 按钮事件
  QObject::connect(btnPick, &QPushButton::clicked, [&]() {
    textBox->setText(QString::fromStdString(picker.pick()));
  });

  QObject::connect(btnPickNoRecent, &QPushButton::clicked, [&]() {
    textBox->setText(QString::fromStdString(picker.pick_no_recent()));
  });

  // 布局
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(textBox);
  layout->addWidget(btnPick);
  layout->addWidget(btnPickNoRecent);
  window.setLayout(layout);

  window.resize(400, 300);
  window.show();

  return app.exec();
}
