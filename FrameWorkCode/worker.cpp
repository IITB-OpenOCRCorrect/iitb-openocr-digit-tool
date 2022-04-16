#include "worker.h"
#include "slpNPatternDict.h"
#include "editdistance.h"

/*!
 * \class Worker
 * \brief This class is used to execute Save Function of MainWindow class in a multithreaded fashion.
 * \
 */


Worker::Worker(QObject *parent,
               Project* mProject,
               QString gCurrentPageName,
               QString gCurrentDirName,
               QString gDirTwoLevelUp,
               QString s1,
               QString s2,
               std::map<std::string, std::string> CPair_editDis,
               std::map<string, set<string> >* CPairs,
               map<QString, QString> filestructure_fw
               ) : QObject(parent)
{
    this->CPairs = CPairs;
    this->mProject = mProject;
    this->s1 = s1;
    this->s2 = s2;
    this->CPair_editDis = CPair_editDis;
    this->gCurrentPageName = gCurrentPageName;
    this->gCurrentDirName = gCurrentDirName;
    this->gDirTwoLevelUp = gDirTwoLevelUp;
    this->filestructure_fw = filestructure_fw;
}

/*!
 * \fn Worker::doSaveBackend()
 * \brief This function calls SaveFile_Backend functions and emits finished() whenever the function completes
 *        executing.
 * \sa SaveFile_Backend()
 */
void Worker::doSaveBackend()
{
    qDebug() << "Started Backend Task";
    slpNPatternDict slnp;
    QVector <QString> changedWords;
    QString tempPageName = gCurrentPageName;

    //! Selecting the location where file is to be saved
    QString changefiledir = filestructure_fw[gCurrentDirName];
    QString localFilename = gDirTwoLevelUp + "/" +changefiledir +"/" + tempPageName;

    localFilename.replace(".txt",".html");

    QFile sFile(localFilename);
    edit_Distance ed;
    changedWords = ed.editDistance(s1, s2);             // Update CPair by editdistance
    QVectorIterator<QString> i(changedWords);
    while (i.hasNext())
        qDebug() << i.next()<<endl;

    //! Do commit when there are some changes in previous and new html file on the basis of editdistance.
    if(changedWords.size())
    {
        if((*mProject).get_version().toInt())     //Check version number
        {
            QString commit_msg = "Corrector Turned in Version: " + (*mProject).get_version();
            //!Check commit condition
            if(!(*mProject).commit(commit_msg.toStdString()))
            {
                //cout<<"Commit Unsuccessful"<<endl;
                return;
            }
            else
            {
                (*mProject).commit(commit_msg.toStdString());
                //cout<<"Commit Successful"<<endl;
            }
        }
    }

    //CPair.insert(CPair_editDis.begin(), CPair_editDis.end());
    //! Enters entries in CPairs through CPair_editDis; allows multiple entries for a incorrent word entry
    for(auto &elem : CPair_editDis)
    {
       std::cerr << elem.first << " " << elem.second << "\n";
       std::cerr << slnp.toslp1(elem.first) << " " << slnp.toslp1(elem.second) << "\n";
       //CPair.insert(make_pair(toslp1(elem.first), toslp1(elem.second)));
       if ( (*CPairs).find(slnp.toslp1(elem.first)) != (*CPairs).end())
       {
           std::set< std::string>& s_ref = (*CPairs)[slnp.toslp1(elem.first)];
           s_ref.insert(slnp.toslp1(elem.second));
       }
       else
       {
           (*CPairs)[slnp.toslp1(elem.first)].insert(slnp.toslp1(elem.second));
       }
    }

    //! Reflecting CPairs entries in the file /Dicts/CPair; Making it dynamic
    QString filename12 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "CPair";
    QFile file12(filename12);
    QStringList split1;
    if(!file12.exists())
    {
       qDebug() << "No exist file "<<filename12;
    }
    else
    {
       qDebug() << filename12<<"exists";
       /*QFile *f = new QFile(filename12);
       f->open(QIODevice::ReadOnly);
       QTextStream in(f);
       in.setCodec("UTF-8");
       QString s1 = in.readAll();
       f->close();
       qDebug ()<<"File is here:::"<<s1[0];*/
       QFile myfile(filename12);
       myfile.open(QIODevice::ReadOnly | QIODevice::Text);
       QTextStream out1(&myfile);
       out1.setCodec("UTF-8");
       QString text;
       while(!out1.atEnd())
           {
               text = out1.readLine();
               //split1.append(text.split('\t').first());
               split1.append(text.split('\t'));
           }
           myfile.close();
       qDebug ()<<"List:::"<<split1<<split1.size();
    }

    //! Insert entries in Correct Formatting Hello (/t) hi,(comma)hiii
    if (file12.open(QIODevice::ReadWrite  | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream out(&file12);
        out.setCodec("UTF-8");
        map<string, set<string>>::iterator itr;
        set<string>::iterator set_it;
        int flag = 0;

        for (itr = (*CPairs).begin(); itr != (*CPairs).end(); ++itr)
        {
            for(int i =0;i<split1.size();i+=2){
                if(QString::fromStdString(slnp.toDev(itr->first)) == split1[i]){
                    flag = 1;
                break;}
                }
            if(flag == 0){

            /*out <<  QString::fromStdString(slnp.toDev(itr->first)) << '\t';
            for (set_it = itr->second.begin(); set_it != itr->second.end(); ++set_it)
            {
                if(set_it != prev(itr->second.end()))
                {
                    out << QString::fromStdString(slnp.toDev(*set_it)) << ",";
                }
                else {
                    out << QString::fromStdString(slnp.toDev(*set_it));
                }

            }
            out <<"\n";*/
                split1.append(QString::fromStdString(slnp.toDev(itr->first)));
                //split1.append('\t');
                set_it = itr->second.begin();
                {
                    split1.append(QString::fromStdString(slnp.toDev(*set_it)));

                }
            }

            flag = 0;
        }
        //Add entries to cpair file {hi \t hello \n}
        //file12.resize(0);
        for(int i=0;i<split1.size()-1;i+=2){
          out <<  split1[i] << '\t'<<split1[i+1]<<"\n";
        }
         file12.close();
    }
    qDebug() << "Completed Backend Task";
    emit finished();
}


