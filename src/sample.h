#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>

class sample : public QObject
{
    Q_OBJECT
public:
    explicit sample(QObject *parent = nullptr);

signals:

};

#endif // SAMPLE_H
