#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QSplashScreen>
#include <QDateTime>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QCheckBox>

#include <QTimer>
#include <QDateTime>


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLabel *lable;
    QHBoxLayout *qhboxlayout;
    QCheckBox *chebox;

    void Test();

private:
    Ui::MainWindow *ui;



protected:
    //鼠标键盘事件
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void wheelEvent(QWheelEvent *);

    //void mouseMoveEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *);

    //双击
    //void mouseDoubleClickEvent(QMouseEvent *event);
    //void mouseDoubleClickEvent(QMouseEvent *event);

    void timerEvent(QTimerEvent *);


signals:
    void mysignal(int);

public slots:
         void slotTest();
private slots:
    void on_checkBox_clicked();

public:
    int id1, id2, id3;

private slots:
    void timerUpdate();


};

#endif // MAINWINDOW_H
