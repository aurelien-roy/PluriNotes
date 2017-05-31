#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H

#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QVector>

#include "noteinterface.h"
#include "notes/task.h" // inclusion récursif.?
class Task;
class GeneralInterface;

class TaskInterface: public NoteInterface {
    Q_OBJECT
    const Task* task;
    QLineEdit* titleEdit;
    QTextEdit* actionEdit;
    QLineEdit* idEdit;
    QLineEdit* dateEdit;
    QComboBox* statusCombo;
    QComboBox* priorityCombo;
    QFormLayout* layout;


    QLineEdit* priorityEdit;
    QLineEdit* statusEdit;
public:
    TaskInterface(const Task& t, QWidget *parent = 0);
    TaskInterface(const Task& t, int i, QWidget *parent = 0);/**< l'interface pour les notes non éditable */

    const Note& toNote();
public slots:
};

#endif // TASKINTERFACE_H

