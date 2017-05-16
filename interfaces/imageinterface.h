#ifndef IMAGEINTERFACE_H
#define IMAGEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QObject>
#include <QMessageBox>
#include <QFileDialog>
#include <QCheckBox>
#include <QStyle>


#include "notes/image.h" // inclusion récursif.?

class Image;

class ImageInterface: public QWidget {
    Q_OBJECT

    Image* image;
    QImage* imageToRegister;
    QString* nameFileImage;
    QLabel* imageLabel;
    QLineEdit* titleEdit;
    QTextEdit* descriptionEdit;
    QFormLayout* layout;
    QVBoxLayout *mainLayout;
    QHBoxLayout* boutonLayout;
    QPushButton* generate;
    QPushButton* bAddImage;
    QCheckBox* fitCheckBox;

    //QPushButton* bDeleteImage;
    //bool deletedImage;

public:
    ImageInterface(Image* im, QWidget *parent = 0);
    void setNameFileImage(QString nameImage);

public slots :
    void openImage();
    void fitToWindow();
    void save();
    //void deleteImage();
};

#endif // IMAGEINTERFACE_H