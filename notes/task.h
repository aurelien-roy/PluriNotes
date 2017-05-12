#ifndef TASK_H
#define TASK_H


#include "note.h"

typedef enum {en_attente, en_cours,terminee} Status;// en_attente=0, en_cours=1, terminee=2

class Task: public Note {
    QString actionToBeDone;
    Status status; // enumeration
    unsigned int priority; //{0,1,2,3,4,5}  0:pas de priorité; 5: très élevé :facultatif
    QDateTime expired; // facultatif, date échouante

public:
    Task(QUuid identifier);

    const QString& getActionToBeDone() const;
    QString getStatus() const;
    Status getStatus_re() const;
    unsigned int getPriority() const;
    const QDateTime& getExpired() const;

    void setActionToBeDone(const QString& a);
    void setPriority(unsigned int p);
    void setStatus(Status s);
    void setExpired(const QDateTime exp);
    Task(const Task& t):Note(t),actionToBeDone(),status(t.getStatus_re()),priority(t.getPriority()),expired(getExpired()){}
    Note* save();
    void restore(Note* n);
};

#endif // TASK_H
