#include "file_manager.h"

File_Manager::File_Manager()
{
    fileName = "New_File";
}

File_Manager::~File_Manager()
{

}

QString File_Manager::openFile(QString filepath)
{
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::ReadOnly);
    QString text = fstream.readAll();
    fileName = file.fileName();
    file.close();
    return text;
}

void File_Manager::createFile( QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    fileName = file.fileName();
    file.close();
}

void File_Manager::saveFile(QString &filepath, QString& text)
{
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::WriteOnly);
    fileName = file.fileName();
    fstream << text;
    file.flush();
    file.close();
}
