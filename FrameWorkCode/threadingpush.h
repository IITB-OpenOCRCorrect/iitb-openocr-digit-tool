#ifndef THREADINGPUSH_H
#define THREADINGPUSH_H

#include <QObject>
#include <git2.h>
class threadingPush : public QObject
{
    Q_OBJECT
public:
    explicit threadingPush(QObject *parent = nullptr);
    int error;
signals:
    void finishedPush();
public slots:
    void ControlPush(QString branchName,git_repository *repo,
                     int login_tries,bool is_cred_cached,
                     std::string mEmail,std::string mName,
                     std::string user,std::string pass);
};

#endif // THREADINGPUSH_H
