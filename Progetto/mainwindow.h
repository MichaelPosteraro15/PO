#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "GestoreProgetto.h"

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //METODI PER SPOSTARMI TRA LE PAGINE

    void on_Home_clicked();
    void on_OperazioniAutore_clicked();
    void on_OperazioniConferenza_clicked();
    void on_OperazioniRivista_clicked();
    void on_OperazioniArticolo_clicked();

    void on_OperazioniB_clicked();
    void on_OperazioniC_clicked();
    void on_OperazioniD_clicked();
    void on_OperazioniE_clicked();



    //METODI A15

    //metodi senza bottone
    void AggiungiInListaAutori(string);
    bool InserisciAutore(string&, string&, string&);
    void PulisciPaginaAutore();

    //metodi con bottone o doubleclicked
    void on_AggiungiAfferenza_clicked();
    void on_EliminaAfferenza_clicked();

    void on_SalvaAutore_clicked();
    void on_ListaAutori_itemDoubleClicked(QListWidgetItem *item);

    //METODI A26

    //metodi senza bottone
    void AggiungiInListaConferenze(string);
    bool InserisciConferenza(string&, string&, Data&, string&, unsigned&);
    void PulisciPaginaConferenza();

    //metodi con bottone e doubleclicked
    void on_AggiungiOrganizzatore_clicked();
    void on_EliminaOrganizzatore_clicked();

    void on_SalvaConferenza_clicked();
    void on_ListaConferenze_itemDoubleClicked(QListWidgetItem *item);

    //METODI A37

    //metodi senza bottone
    void AggiungiInListaRiviste(string);
    bool InserisciRivista(string&, string&, Data&, string&, unsigned&);
    void PulisciPaginaRivista();

    //metodi con bottone e doubleclicked
    void on_SalvaRivista_clicked();
    void on_ListaRiviste_itemDoubleClicked(QListWidgetItem *item);

    //METODI 48

    //metodi senza bottone
    void AggiungiInListaArticoli(string);
    bool InserisciArticolo(string&, string&, unsigned&, double&, MezzoDivulgativo&);
    void PulisciPaginaArticolo();

    //metodi con bottone e doubleckicked
    void on_AggiungiAutoreArticolo_clicked();
    void on_AggiungiKeyword_clicked();
    void on_AggiungiArticoloCorrelato_clicked();

    void on_EliminaAutoreArticolo_clicked();
    void on_EliminaKeyword_clicked();
    void on_EliminaArticoloCorrelato_clicked();

    void on_SalvaArticolo_clicked();
    void on_ListaArticoli_itemDoubleClicked(QListWidgetItem *item);

    //SEZIONE B
    void on_ListaArticoliAutore_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaArticoliAutore(string);
    void on_CercaArticoliAutore_clicked();

    void on_ListaArticoliRivista_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaArticoliRivista(string, string, const Data&);
    void on_CercaArticoliRivista_clicked();

    void on_ListaArticoliConferenza_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaArticoliConferenza(string, string, const Data&);
    void on_CercaArticoliConferenza_clicked();

    //SEZIONE C

    void on_ListaPrezziArticoliAutore_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaPrezziArticoliAutore(const list<Articolo>&);
    void on_CercaArticoliPrezzo_clicked();

    //SEZIONE D

    void on_ListaArticoliRivistaOrdinati_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaArticoliRivistaOrdinati(string, string, const Data&);
    void on_VisualizzaArticoliRivistaOrdinati_clicked();

    void on_ListaArticoliConferenzaOrdinati_itemDoubleClicked(QListWidgetItem *item);
    void AggiungiInListaArticoliConferenzaOrdinati(string, string, const Data&);
    void on_VisualizzaArticoliConferenzaOrdinati_clicked();

    //SEZIONE E

    void AggiungiInListaRivisteNoAutori(string);
    void on_VisualizzaRivisteNoAutore_clicked();

    void on_ListaRivisteNoAutore_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    GestoreProgetto g;
};
#endif // MAINWINDOW_H
