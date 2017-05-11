#ifndef ARTICLE_H
#define ARTICLE_H


#include "note.h"

class Article: public Note{
    QString text;
public:
    Article(QUuid identifier);
    void setText(const QString& texte);
    const QString& getText() const;
};

#endif // ARTICLE_H
