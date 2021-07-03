#ifndef REPORTCREATOR_H
#define REPORTCREATOR_H
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>

class reportCreator
{
public:
    reportCreator();
    // working with report methods
    void setTemplate();

    void addHeader();
    void addTask(const QString &pathToTask);
    void addLog(const QString &pathToLog);
    void addPicture(const QString &pathToPicture, const QString &nameOfPicture);
    void clearReport();


    void printReport(const QString &pathToPdf);
private:
    QTextDocument *currentReport;
    QString html;
};



#endif // REPORTCREATOR_H
