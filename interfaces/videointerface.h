#ifndef VIDEOINTERFACE_H
#define VIDEOINTERFACE_H


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
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QMovie>
#include <QToolButton>
#include <QStyle>
#include <QComboBox>
#include <QVector>

#include "notes/video.h"
#include "noteinterface.h"

class Video;

class VideoInterface : public NoteInterface {
    Q_OBJECT
    const Video* video;
    QMovie* videoToRegister;
    QGraphicsVideoItem* item;
    QString* nameFileVideo;

    QGraphicsView* graphicsView;
    QGraphicsScene* scene;

    QLineEdit* titleEdit;
    QTextEdit* descriptionEdit;
    QLineEdit* idEdit;



    QFormLayout* layout;
    QVBoxLayout* mainLayout;
    QHBoxLayout *layoutVideo;
    QHBoxLayout* boutonLayout;
    QHBoxLayout* boutonLayout2;

    QPushButton* generate;
    QToolButton* stopButton;
    QToolButton* openButton;
    QToolButton* playButton; //    QPushButton* playButton;
    QToolButton* pauseButton;


    QMediaPlayer* player;
    bool initVideo;

    /**< la partie choisir et charger les versions */
    QFormLayout* boxLayout;
    QComboBox * versions;
    QPushButton* choisir;
    int Id;
    std::vector <int> a;

    QPushButton* activer;/**< archive->active */
    QPushButton* supprimer;/**< supprimer */

public:
    VideoInterface(const Video& vid, QWidget *parent = 0);
    VideoInterface(const Video& vid, int i, QWidget *parent = 0);/**< l'interface pour les notes non éditable */
    void updateButtons();
    void parcourir();/**< parcourir les versions*/

public slots:
    void openVideo();
    void playVideo();
    void stopVideo();
    void pauseVideo();
    void save();
    void charger();/**< charger la version*/
    void enregistrerid(int i);/**< garder id présent*/
};

#endif // VIDEOINTERFACE_H
