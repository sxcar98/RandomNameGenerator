#include "randomnamegenerator.hpp"
#include <QApplication>
#include <QFont>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class NamePicker : public QWidget {
  Q_OBJECT

public:
  NamePicker(QWidget *parent = nullptr) : QWidget(parent) {
    setWindowTitle("点名器");
    resize(800, 500);

    // 字体
    QFont font("Microsoft YaHei", 12);

    // ====== 左边：随机点名区 ======
    auto *genGroup = new QGroupBox("随机点名");
    auto *genLayout = new QVBoxLayout;
    btnGen = new QPushButton("随机点名");
    btnGen->setFont(font);
    txtGen = new QTextEdit;
    txtGen->setReadOnly(true);
    txtGen->setFont(font);
    genLayout->addWidget(btnGen);
    genLayout->addWidget(txtGen);
    genGroup->setLayout(genLayout);

    // ====== 右边：不重复点名区 ======
    auto *noRecentGroup = new QGroupBox("不重复点名");
    auto *noRecentLayout = new QVBoxLayout;
    btnNoRecent = new QPushButton("不重复点名");
    btnNoRecent->setFont(font);
    txtNoRecent = new QTextEdit;
    txtNoRecent->setReadOnly(true);
    txtNoRecent->setFont(font);
    noRecentLayout->addWidget(btnNoRecent);
    noRecentLayout->addWidget(txtNoRecent);
    noRecentGroup->setLayout(noRecentLayout);

    // ====== 主布局 ======
    auto *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(genGroup);
    mainLayout->addWidget(noRecentGroup);
    setLayout(mainLayout);

    // 连接信号与槽
    connect(btnGen, &QPushButton::clicked, this, &NamePicker::onGenClicked);
    connect(btnNoRecent, &QPushButton::clicked, this, &NamePicker::onNoRecentClicked);
  }

private slots:
  void onGenClicked() {
    QString name = QString::fromStdString(rng.gen());
    txtGen->append(name);
  }

  void onNoRecentClicked() {
    try {
      QString name = QString::fromStdString(rng.gen_no_recent());
      txtNoRecent->append(name);
    } catch (const std::exception &e) {
      txtNoRecent->append("⚠️ 没有可选的名字了！");
    }
  }

private:
  QPushButton *btnGen;
  QPushButton *btnNoRecent;
  QTextEdit *txtGen;
  QTextEdit *txtNoRecent;
  RandomNameGenerator rng;
};

#include "main.moc"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  NamePicker picker;
  picker.show();
  return app.exec();
}
