#include "mainwindow.h"
#include <QApplication>
#include <QProgressBar>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#define diashow 0
#define loadimag 0
#define all 0

int main(int argc, char *argv[])
{
    //QApplication::addLibraryPath("qjpeg");

    QApplication a(argc, argv);
    MainWindow w;
     a.setAttribute(Qt::AA_SynthesizeTouchForUnhandledMouseEvents,true);//未被接收的鼠标事件转触摸事件

#if all

#if diashow
    QDialog *Mydialog=new QDialog;

    //阻塞窗口关闭后往下执行
    if(Mydialog->exec() == QDialog::Accepted)
    {
        //my1->show();
        //qDebug()<<" dialog  exec"<<endl;
    }
    else
    {

        qDebug()<<"quit dialog"<<endl;
    }


#else
//        QPixmap pixmap;
//        bool fx=pixmap.load(qApp->applicationDirPath()+"/timg.jpg");
//        w.resize(pixmap.size());
//        qDebug()<<"pixmap.load "<<fx<<endl;

    //SplashScreen程序动画
    QPixmap image(qApp->applicationDirPath()+"/timg.jpg");
    QSplashScreen SplashScreen;
    SplashScreen.setPixmap(image);
    SplashScreen.show();

    SplashScreen.showMessage("chex", Qt::AlignCenter, Qt::red);
    /*
        int delayTime = 5;
        QElapsedTimer timer;
        timer.start();
        while(timer.elapsed() < (delayTime * 1000))
        {
             app.processEvents();
        }
    */
#endif


#if 1
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        a.processEvents();
    } while (n.msecsTo(now)<=2);//为需要延时的时间
#endif


#if loadimag
        //加载背景图片
       QFrame *frame = new QFrame;//框架
       //frame->resize(400,700);
       //QPixmap pixmap(qApp->applicationDirPath()+"/timg.jpg");

       QImage image2;
       image2.load(qApp->applicationDirPath()+"/timg.jpg");

       frame->resize(image2.width(),image2.height());
       QPixmap pixmap = QPixmap::fromImage(image2.scaled(image2.width(),
                                                        image2.height(),
                                                        Qt::IgnoreAspectRatio) );
       QPalette   palette;
       palette.setBrush(frame->backgroundRole(),QBrush(pixmap));
       frame->setPalette(palette);
       //frame->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
       frame->setAutoFillBackground(false);//设置自动填充背景
       //frame->show();
       w.setPalette(palette);
#endif

    QLabel *lable =new QLabel();
    lable->setText("show 哈啰");

    QCheckBox *chebox=new QCheckBox("enble");

 // QObject::connect(chebox,SIGNAL(clicked(bool)),NULL,SLOT(test()));

    QObject::connect(chebox,SIGNAL(QCheckBox::click()),chebox,SLOT(test()));


    QHBoxLayout *qhboxlayout=new QHBoxLayout();

    qhboxlayout->addWidget(chebox);
    qhboxlayout->addWidget(lable);

    //Progressbar
    QProgressBar *m_pConnectProBar=new QProgressBar;
    m_pConnectProBar->setRange(0,1000); //设置进度条最小值和最大值(取值范围)
    m_pConnectProBar->setValue(50);  //设置当前的运行值
    m_pConnectProBar->reset(); //让进度条重新回到开始
    m_pConnectProBar->setOrientation(Qt::Horizontal);  //水平方向

    for(int i=0;i<1000;i++)
        {
            for(int j=0;j<1000;j++);
            m_pConnectProBar->setValue(i);
            qApp->processEvents();  //提交事件
     }

     qhboxlayout->addWidget(m_pConnectProBar);

    //w.setLayout(qhboxlayout);
   //qhbixlay qhboxlayout=new


    QWidget *widget = new QWidget();
     w.setCentralWidget(widget);
    widget->setLayout(qhboxlayout);

    w.resize(800,480);
    w.show();
    //SplashScreen.finish(&w);

    QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
    }
    else
    {
        qDebug()<<"clicked no\n";

    }
#else
        //w.show();


        QGraphicsScene *scene = new QGraphicsScene;  //场景
        //QGraphicsRectItem *item = new QGraphicsRectItem(100,100,30,60);  //矩形项

        QGraphicsRectItem *rect = scene->addRect(QRectF(0, 0, 100, 100));
               // addRect(QRectF(0, 0, 100, 100));
        //QGraphicsItem *item = scene->itemAt(50,50);

         QGraphicsEllipseItem *ellipseItem= new QGraphicsEllipseItem(0,0,80,80);
        scene->addItem(rect);  //项添加到场景
         scene->addItem(ellipseItem);
        QGraphicsView *view = new QGraphicsView; //视图
        view->setScene(scene);  //视图关联场景
        view->show();  //显示视图

        w.show();


#endif
      // int radius=10;
     // QRect rect(-radius, -radius, radius * 2, radius * 2);
        //以下两种方法二选一,其实绘制360度的圆弧=绘制无背景的圆形
        //w.DrawChildren(rect, 0, 360 * 16);
        //w.drawEllipse(rect);

    a.exec();
    qDebug()<<"program is quit"<<endl;
    return 0;
}

void test()
{
    qDebug()<<"c11 1232132\n"<<endl;

}
