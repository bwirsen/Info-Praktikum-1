#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "dialogstreet.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mapiofileinput(new MapIoNrw())
{
    //hide all unused buttons per default
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->pushButton_teste_was->hide();
    ui->pushButton_test_add_street->hide();
    ui->pushButton_test_draw_street->hide();
    ui->button_test_draw_city->hide();
    ui->pushButton_test_map_add_draw->hide();
    ui->pushButton_test_dijkstra->hide();
    ui->pushButton_test_abstract_map->hide();
    ui->label_eingabe->hide();
    ui->lineEdit_teste_was->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug()<<"Button erfolgreich betätigt!";

    //Eingabe speichern
    QString eingabe = ui->lineEdit_teste_was->text();
    QString text;
    //Prüfen, ob die Eingabe eine Zahl ist
    bool ok = false;
    double eingabe_zahl = eingabe.toDouble(&ok); //falls es eine Zahl ist, wird ok true

    if(ok)
    {
        text = QString("Ihr Eingabe ist eine Zahl lautet nach Addition mit 4: %1. ").arg(eingabe_zahl+4);
    }
    else
    {
        text = QString("Ihr Eingabe lautet: %1.").arg(eingabe);
    }

    //MessageBox erstellen
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();

    //zufälliges Rechteck zeichnen
    int xPos = qrand()*9/RAND_MAX;
    int yPos = qrand()*9/RAND_MAX;

    scene.addRect(xPos,yPos,50,50, QPen(Qt::red));
    scene.addRect(100,87,100,100, QPen(Qt::yellow));
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox about;
    about.about(this, "About Streetplanner", "Streetplanner V9: Info Praktikum 1 RWTH von Bjarne Wirsen");
}

void MainWindow::on_button_test_draw_city_clicked()
{
    City city1("city1", 10, 20);
    City city2("city2", 300, 40);

    city1.draw(scene);
    city2.draw(scene);
}

void MainWindow::on_pushButton_test_map_add_draw_clicked()
{  
    City aachen("Aachen", 10, 20);
    City koeln("Koeln", 100, 50);
    City hamm("Hamm", 150, 200);
    City bochum("Bochum", 50, 100);
    map.addCity(&aachen);
    map.addCity(&koeln);
    Street street1(&aachen, &koeln);

    bool result = map.addStreet(&street1);
    if (result)
    {
        qDebug() << "Aachen - Köln added";
    }
    else
    {
        qDebug() << "Aachen - Köln not added";
    }

    Street street2(&hamm, &bochum);
    result = map.addStreet(&street2);
    if (result)
    {
        qDebug() << "Hamm - Bochum added";
    }
    else
    {
        qDebug() << "Hamm - Bochum not added";
    }

    Street street3(&hamm, &aachen);
    result = map.addStreet(&street3);
    if (result)
    {
        qDebug() << "Hamm - Aachen added";
    }
    else
    {
        qDebug() << "Hamm - Aachen not added";
    }
    map.draw(scene);
}

void MainWindow::on_pushButton_test_draw_street_clicked()
{
    City aachen("Aachen", 10, 20);
    City koeln("Koeln", 100, 50);
    Street street1(&aachen, &koeln);
    street1.draw(scene);
}

void MainWindow::on_pushButton_test_add_street_clicked()
{
    City aachen("Aachen", 10, 20);
    City koeln("Koeln", 100, 50);
    City hamm("Hamm", 150, 200);
    City bochum("Bochum", 50, 100);
    map.addCity(&aachen);
    map.addCity(&koeln);
    Street street1(&aachen, &koeln);

    bool result = map.addStreet(&street1);
    if (result)
    {
        qDebug() << "Aachen - Köln added";
    }
    else
    {
        qDebug() << "Aachen - Köln not added";
    }

    Street street2(&hamm, &bochum);
    result = map.addStreet(&street2);
    if (result)
    {
        qDebug() << "Hamm - Bochum added";
    }
    else
    {
        qDebug() << "Hamm - Bochum not added";
    }

    Street street3(&hamm, &aachen);
    result = map.addStreet(&street3);
    if (result)
    {
        qDebug() << "Hamm - Aachen added";
    }
    else
    {
        qDebug() << "Hamm - Aachen not added";
    }


}

void MainWindow::on_checkBox_hide_show_clicked()
{
   bool check = ui->checkBox_hide_show->isChecked();

   if(!check)
   {
       ui->pushButton_teste_was->hide();
       ui->pushButton_test_add_street->hide();
       ui->pushButton_test_draw_street->hide();
       ui->button_test_draw_city->hide();
       ui->pushButton_test_map_add_draw->hide();
       ui->pushButton_test_dijkstra->hide();
       ui->pushButton_test_abstract_map->hide();
       ui->label_eingabe->hide();
       ui->lineEdit_teste_was->hide();
   }

   else
   {
       ui->pushButton_teste_was->show();
       ui->pushButton_test_add_street->show();
       ui->pushButton_test_draw_street->show();
       ui->pushButton_test_map_add_draw->show();
       ui->button_test_draw_city->show();
       ui->pushButton_test_dijkstra->show();
       ui->pushButton_test_abstract_map->show();
       ui->label_eingabe->show();
       ui->lineEdit_teste_was->show();
   }
}

void MainWindow::on_pushButton_add_city_clicked()
{
    // creates a new instance of a Dialog and executes
    Dialog* addCityRequest = new Dialog();
    addCityRequest->exec();

    /*qDebug()<<addCityRequest->result();*/

    //if the Dialog was accepted
    if(addCityRequest->result())
    {
        //create a new city and add it to the list in map and draw the new scene
        City* newCity = addCityRequest->createCity();
        map.addCity(newCity);
        scene.clear();
        map.draw(scene);
    }
}

void MainWindow::on_pushButton_fill_map_clicked()
{
    map.clearMap();
    mapiofileinput->fillMap(map);
    scene.clear();
    map.draw(scene);
}

void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    City *a = new City("a", 0, 0);
        City *b = new City("b", 0, 100);
        City *c = new City("c", 100, 300);
        Street *s = new Street(a, b);
        Street *s2 = new Street(b, c);


        qDebug() << "MapTest: Start Test of the Map";
        {
            qDebug() << "MapTest: adding wrong street";
            bool t1 = map.addStreet(s);
            if (t1) {
                qDebug() << "-Error: Street should not bee added, if cities have not been added.";
            }
        }

        {
            qDebug() << "MapTest: adding correct street";
            map.addCity(a);
            map.addCity(b);
            bool t1 = map.addStreet(s);
            if (!t1) {
                qDebug() << "-Error: It should be possible to add this street.";
            }

        }

        {
            qDebug() << "MapTest: find city";
            City* city = map.find_city("a");
            if (city != a)
                qDebug() << "-Error: City a could not be found.";

            city = map.find_city("b");
            if (city != b)
                qDebug() << "-Error: City b could not be found.";

            city = map.find_city("c");
            if (city != NULL)
                qDebug() << "-Error: If city could not be found 0 should be returned.";
        }

        map.addCity(c);
        map.addStreet(s2);

        {
            qDebug() << "MapTest: get_opposite_city";
            const City *city = map.get_opposite_city(s, a);
            if (city != b)
                qDebug() << "-Error: Opposite city should be b.";

            city = map.get_opposite_city(s, c);
            if (city != 0)
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
        }

        {
            qDebug() << "MapTest: street_length";
            double l = map.get_length(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
                qDebug() << "-Error: Street Length is not equal to the expected.";

        }

        {
            qDebug() << "MapTest: get_street_list";
            std::vector<Street*> streetList1 = map.get_street_list(a);
            std::vector<Street*> streetList2 = map.get_street_list(b);
            if (streetList1.size() != 1) {
                qDebug() << "-Error: One street should be found for city a.";
            }
            else if (*streetList1.begin() != s) {
                    qDebug() << "-Error: The wrong street has been found for city a.";
            }

            if (streetList2.size() != 2)
                qDebug() << "-Error: Two streets should be found for city b.";
        }

        qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    std::vector<Street*> shortestPath = Dijkstra::search(map, "Düsseldorf", "Bonn");
    int i=1;
    for(std::vector<Street*>::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it)
    {
        qDebug() << i << ".";
        qDebug() <<"Nehmen Sie die Straße " << (*it)->getCity1()->get_name() << " <--> " << (*it)->getCity2()->get_name();

        (*it)->drawRed(scene);


        i++;
    }


}

void MainWindow::on_pushButton_free_search_clicked()
{
    //new instance of the dijkstradialog and exec
    dijkstradialog*  freeSearchRequest = new dijkstradialog();
    freeSearchRequest->exec();

    //if result 1
    if(freeSearchRequest->result())
    {
        //call member function of dijkstradialog to receive to list of the best streets...
        std::vector<Street*> shortestPath = freeSearchRequest->freeSearch(map);
        int i=1;

        //... and paint them red
        for(std::vector<Street*>::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it)
        {
            qDebug() << i<< ".";
            qDebug() <<"Nehmen Sie die Straße " << (*it)->getCity1()->get_name() << " <--> " << (*it)->getCity2()->get_name();
            (*it)->drawRed(scene);
            i++;
        }
    }
}

void MainWindow::on_pushButton_add_extern_map_clicked()
{
    //analog to the other dialogs
    ExternMap* externMapRequest = new ExternMap();
    externMapRequest->exec();

    if (externMapRequest->result())
    {
        qDebug() << externMapRequest->getPathToCityMap();
        qDebug() << externMapRequest->getPathToStreetMap();
        //new instance of MapIoFileinput and save the pointer to it in mapiofileinput - mainwindow membervar
        mapiofileinput = new MapIoFileinput(externMapRequest->getPathToCityMap(), externMapRequest->getPathToStreetMap());

    }
}

void MainWindow::on_pushButton_add_street_clicked()
{
    //analogical to other dialogs
    DialogStreet* addStreetRequest = new DialogStreet();
    addStreetRequest->exec();

    if(addStreetRequest->result())
    {
        //analogical to addcity
        Street* newStreet = addStreetRequest->createStreet(map);
        map.addStreet(newStreet);
        scene.clear();
        map.draw(scene);
    }
}
