#ifndef TASK_H
#define TASK_H


#include "notes/note.h"
#include "interfaces/taskinterface.h"

class TaskInterface;

typedef enum {en_attente, en_cours,terminee} Status;// en_attente=0, en_cours=1, terminee=2

class Task: public Note {
    QString actionToBeDone;
    Status status; // enumeration
    unsigned int priority; //{0,1,2,3,4,5}  0:pas de priorité; 5: très élevé :facultatif
    QDateTime expired; // facultatif, date échouante
    static const QString type;

public:
    Task(QUuid identifier);
    //Task(const Task& t):Note(t),actionToBeDone(),status(t.getStatus_re()),priority(t.getPriority()),expired(t.getExpired()){}

    const QString& getActionToBeDone() const;
    QString getStatus() const;
    unsigned int getStatusInt() const;
    Status getStatus_re() const;
    unsigned int getPriority() const;
    const QDateTime& getExpired() const;

    void setActionToBeDone(const QString& a);
    void setPriority(unsigned int p);
    void setStatus(Status s);
    void setExpired(const QDateTime exp);

    TaskInterface* getInterface();


    Note* save();
    void restore(Note* n);

    const QString& getType() const;
};

#endif // TASK_H
