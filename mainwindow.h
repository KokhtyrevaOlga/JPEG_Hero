#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include_libs.h"
#include "clusterdlg.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void get_app_path(QString path)
    {
        appPath = path;
    }

private:
    QString appPath,
            tmpPath,
            backupPath,
            tempFilePath;
    QString file_types;
    Ui::MainWindow *ui;
    QPixmap *img;
    QString *imgPath; //current img path
    QLabel *imgLabel; //ImgView
    bool img_fits_wnd,
         img_autoupdate;
    int LISTVIEW_WIDTH;
    QLabel *status_lbl;
    QSet<unsigned int>  *itemSet,
                        *delClusters; // numbers of cluster to remove (disable)
    QList<QListWidgetItem*> *itemList; // checkboxes in ListView
    int fileClusters; //total clusters ammount
    QList<QByteArray> *clusters_list; //clusters list with CLUSTER_SIZE bytes element size

    int countClusters();    
    QList<unsigned int> parse_clusters_str(QString str);


private slots:
    void open_file();
    void fit_size();
    void autoupdate();
    void wnd_resize();
    void save_file();
    void save_file_as();
    void update_view();
    void update_file();
    void resotre_file();
    void cluster_clicked(QListWidgetItem *);
    void add_cluster();
    void remove_cluster();
    void add_to_list(QString&);
    void remove_from_list(QString&);


signals:
    void sig_update_file();
    void sig_update_view();


};

#endif // MAINWINDOW_H
