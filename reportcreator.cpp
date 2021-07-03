#include "reportcreator.h"

reportCreator::reportCreator()
{
    currentReport = new QTextDocument;

}

void reportCreator::setTemplate()
{
    currentReport->setHtml(html);
}

void reportCreator::addHeader()
{
   QDate currDate = QDate::currentDate();
   QTime currTime = QTime::currentTime();
   QString toAdd;
   toAdd.append("<p align = \"left\">"+currDate.toString("dd/MM/yy")+"</p>");
   toAdd.append("<p align = \"left\">"+currTime.toString()+"</p>");
   toAdd.append("<h1 align = \"center\">Отчёт</h1>");
   /*QString toAdd("<p>current date</p>"
                 "<p>current time&nbsp;</p>"
                 "<p style=\"text-align: center;\">Отчет</p>");*/
   html += toAdd;
}

void reportCreator::addTask(const QString &pathToTask)
{
    QString toAdd("<p> Задание </p><p>");
    QFile file(pathToTask);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
    QTextStream in(&file);
    QString line;
    while(!in.atEnd())
    {
        line = in.readLine();
        toAdd.append(line);

    }
    toAdd.append("</p>");
    html += toAdd;
    }

}

void reportCreator::addLog(const QString &pathToLog)
{
    QString toAdd("<p> Результаты </p><table border = \"2\">");
    QFile file(pathToLog);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
    QTextStream in(&file);
    // создание заголовков
    QString line = in.readLine();
    toAdd.append("<tr>");
    foreach(const QString &lst1, line.split(";"))
        toAdd.append("<th>"+lst1+"</th>");
    toAdd.append("</tr>");
    //заполнение таблицы
    while(!in.atEnd()) {

        line = in.readLine();
        toAdd.append("<tr>");
        foreach(const QString &lst1, line.split(";"))
            toAdd.append("<td>"+lst1+"</td>");
        toAdd.append("</tr>");


    }
    toAdd.append("</table>");
    html += toAdd;
    }
}

void reportCreator::addPicture(const QString &pathToPicture)
{
    QString toAdd("<p>График картинка какого-то результата</p>");
    toAdd.append("<img alt = \"Текст картинки\" allign = \"left\" hspace =\"100\" src =\"" + pathToPicture + "\" width = \"400\" height = \"400\"");
    html += toAdd;
}

void reportCreator::clearReport()
{
    html.clear();
}

void reportCreator::printReport(const QString &pathToPdf)
{
    QPrinter printer;
    printer.setOutputFileName(pathToPdf);
    printer.setOutputFormat(QPrinter::PdfFormat);
    currentReport->print(&printer);
    //QImage img("C:/Users/bsm09/Documents/ReportGenerator/test.jpg");
   // QPainter painter;
    //painter.begin( &printer );
   // painter.drawImage( 0, 0, img);
   // printer.newPage();
}
