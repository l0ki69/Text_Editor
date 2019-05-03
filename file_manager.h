#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <QFile>
#include <QTextStream>


class File_Manager
{
public:
    File_Manager();
    ~File_Manager();

    void createFile( QString &filepath);
    void saveFile(QString &filepath, QString &text);
    QString openFile(QString filepath);

    QString fileName;
    QString currentPath;
};

#endif // FILE_MANAGER_H
