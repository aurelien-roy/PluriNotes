#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QtWidgets>
#include "mainframe.h"
#include "notesmanager.h"
#include "interfaces/relations/relateddockview.h"
#include "interfaces/versions/versionsdockview.h"
#include "relations/relationsmanager.h"
#include "memento.h"


class MainWindow : public QMainWindow
{
    Mainframe* mf;
    RelatedDockView* relationsView;
    QDockWidget* relationsDock;

    VersionsDockView* versionsView;
    QDockWidget* versionsDock;

    MementoCaretaker* memento;

    //menu
    QMenu* menuFichier;
    QMenu* menuEdition;
    QMenu* menuAffichage;
    QAction* actionRelation;

    void initMenu();
    void initMemento();

    Q_OBJECT

public:
    explicit MainWindow(NotesManager& nm, RelationsManager<NoteHolder>& rm, MementoCaretaker& mement, Database& db, QWidget *parent = 0);

    RelatedDockView* getRelatedDockView() { return relationsView; }
signals:
    void undo();
    void redo();
public slots:

};

#endif // MAINWINDOW_H
