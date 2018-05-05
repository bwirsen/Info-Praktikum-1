#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "dijkstradialog.h"
#include "externmap.h"
#include "mapiofileinput.h"

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QVector>
#include <QCheckBox>
#include <QWidget>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //documentation for most of the button inside the code or as a hover text on the button itself
    /**
     * @brief on_pushButton_teste_was_clicked
     */
    void on_pushButton_teste_was_clicked();

    /**
     * @brief on_actionExit_triggered
     */
    void on_actionExit_triggered();

    /**
     * @brief on_actionClear_Scene_triggered
     */
    void on_actionClear_Scene_triggered();

    /**
     * @brief on_actionAbout_triggered
     */
    void on_actionAbout_triggered();

    /**
     * @brief on_button_test_draw_city_clicked
     */
    void on_button_test_draw_city_clicked();

    /**
     * @brief on_pushButton_test_map_add_draw_clicked
     */
    void on_pushButton_test_map_add_draw_clicked();

    /**
     * @brief on_pushButton_test_draw_street_clicked
     */
    void on_pushButton_test_draw_street_clicked();

    /**
     * @brief on_pushButton_test_add_street_clicked
     */
    void on_pushButton_test_add_street_clicked();

    /**
     * @brief on_checkBox_hide_show_clicked
     */
    void on_checkBox_hide_show_clicked();

    /**
     * @brief on_pushButton_add_city_clicked
     */
    void on_pushButton_add_city_clicked();

    /**
     * @brief MainWindow::on_pushButton_fill_map_clicked
     * Clears the map to avoid "over-painting" and calls the abstract method fillMap()
     * of the actual saved MapIo pointer on the subclass.
     */
    void on_pushButton_fill_map_clicked();

    /**
     * @brief on_pushButton_test_abstract_map_clicked
     */
    void on_pushButton_test_abstract_map_clicked();

    /**
     * @brief on_pushButton_test_dijkstra_clicked
     */
    void on_pushButton_test_dijkstra_clicked();

    /**
     * @brief on_pushButton_free_search_clicked
     */
    void on_pushButton_free_search_clicked();

    /**
     * @brief on_pushButton_add_extern_map_clicked
     */
    void on_pushButton_add_extern_map_clicked();

    /**
     * @brief on_pushButton_add_street_clicked
     */
    void on_pushButton_add_street_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapiofileinput;
};

#endif // MAINWINDOW_H
