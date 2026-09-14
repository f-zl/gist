#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
struct Widget : QWidget {
  QVBoxLayout lout{this};
  QLabel lb{QStringLiteral("0")};
  QPushButton btn{QStringLiteral("+1")};
  unsigned count = 0;
  Widget() {
    lout.addWidget(&lb);
    lout.addWidget(&btn);
    connect(&btn, &QPushButton::clicked,
            [this] { lb.setText(QString::number(++count)); });
  }
};
int main(int argc, char **argv) {
  QApplication a{argc, argv};
  Widget w;
  w.show();
  return a.exec();
}
