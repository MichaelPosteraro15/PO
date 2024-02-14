#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//METODI PER SPOSTARMI TRA LE PAGINE

void MainWindow::on_Home_clicked(){
    ui->Pagine->setCurrentWidget(ui->HOME);
}

void MainWindow::on_OperazioniAutore_clicked(){
    ui->Pagine->setCurrentWidget(ui->A15);
}

void MainWindow::on_OperazioniConferenza_clicked(){
    ui->Pagine->setCurrentWidget(ui->A26);
}

void MainWindow::on_OperazioniRivista_clicked(){
    ui->Pagine->setCurrentWidget(ui->A37);
}

void MainWindow::on_OperazioniArticolo_clicked(){
    ui->Pagine->setCurrentWidget(ui->A48);
}

void MainWindow::on_OperazioniB_clicked(){
    ui->Pagine->setCurrentWidget(ui->SEZIONEB);
}

void MainWindow::on_OperazioniC_clicked(){
    ui->Pagine->setCurrentWidget(ui->SEZIONEC);
}

void MainWindow::on_OperazioniD_clicked(){
    ui->Pagine->setCurrentWidget(ui->SEZIONED);
}

void MainWindow::on_OperazioniE_clicked(){
    ui->Pagine->setCurrentWidget(ui->SEZIONEE);
}

//METODI PER LA PAGINA A15

void MainWindow::on_AggiungiAfferenza_clicked(){
    QString afferenza = ui->InserisciAfferenza->text();
    if(!afferenza.isEmpty()){ ui->ListaAfferenze->addItem(afferenza); }

    ui->InserisciAfferenza->clear();
}

void MainWindow::on_EliminaAfferenza_clicked(){
    QListWidgetItem* afferenza = ui->ListaAfferenze->takeItem(ui->ListaAfferenze->currentRow());
    delete afferenza;
}

void MainWindow::AggiungiInListaAutori(string identificativo){
    stringstream stream;
    stream << identificativo;                                          //inserisco nello stream l'id
    ui->ListaAutori->addItem(QString::fromStdString(stream.str()));    //lo aggiungo alla lista di autori
}

bool MainWindow::InserisciAutore(string& identificativo, string& nome, string& cognome){
    identificativo = (ui->InserisciIdentificativo->text()).toStdString();
    nome = (ui->InserisciNome->text()).toStdString();
    cognome = (ui->InserisciCognome->text()).toStdString();

    if(identificativo.empty() || nome.empty() || cognome.empty()){ return false; }
    return true;
}

void MainWindow::PulisciPaginaAutore(){
    ui->InserisciIdentificativo->clear();
    ui->InserisciNome->clear();
    ui->InserisciCognome->clear();
    ui->ListaAfferenze->clear();
}

void MainWindow::on_SalvaAutore_clicked(){
    string identificativo, nome, cognome;
    if(!InserisciAutore(identificativo, nome, cognome)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Campo Vuoto", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    list<string> afferenze;
    for(int i = 0; i < ui->ListaAfferenze->count(); i++){
        QListWidgetItem *item = ui->ListaAfferenze->item(i);           //puntatore item all'i-esima riga (item(i) = riga)
        string afferenza = (item->text()).toStdString();               //prendo il testo nell'item e lo converto in string (Partendo da QString)
        afferenze.push_back(afferenza);
    }

    PulisciPaginaAutore();

    if(!g.aggiungi_autore(identificativo, nome, cognome, afferenze)){  //se l'autore non é inserito return false
        QMessageBox message(QMessageBox::Critical,"Errore", "Identificativo esistente", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    AggiungiInListaAutori(identificativo);
}

void MainWindow::on_ListaAutori_itemDoubleClicked(QListWidgetItem *item)
{
    string identificativo = (item->text()).toStdString();

    for(auto autore: g.lista_autori()){
        stringstream stream;
        stream << autore;

        if(identificativo == autore.get_identificativo()){
           ui->AutoreConsiderato->setPlainText(QString::fromStdString(stream.str()));
        }
    }
}

//METODI PER LA PAGINA A26

void MainWindow::on_AggiungiOrganizzatore_clicked(){
    QString organizzatore = ui->InserisciOrganizzatore->text();
    if(!organizzatore.isEmpty()){ ui->ListaOrganizzatori->addItem(organizzatore); }

    ui->InserisciOrganizzatore->clear();
}

void MainWindow::on_EliminaOrganizzatore_clicked(){
    QListWidgetItem* organizzatore = ui->ListaOrganizzatori->takeItem(ui->ListaOrganizzatori->currentRow());
    delete organizzatore;
}

void MainWindow::AggiungiInListaConferenze(string nome){
    stringstream stream;
    stream << nome;
    ui->ListaConferenze->addItem(QString::fromStdString(stream.str()));
}

bool MainWindow::InserisciConferenza(string& nome, string& acronimo, Data& data, string& luogo, unsigned& partecipanti){
    nome = (ui->InserisciNomeConferenza->text()).toStdString();
    acronimo = (ui->InserisciAcronimoConferenza->text()).toStdString();
    luogo = (ui->InserisciLuogo->text()).toStdString();
    partecipanti = ui->InserisciPartecipantiConferenza->value();

    QDate qdata = ui->InserisciDataConferenza->date();
    data.set_Data(qdata.day(), qdata.month(), qdata.year());

    if(nome.empty() || acronimo.empty() || luogo.empty()){ return false; }
    return true;
}

void MainWindow::PulisciPaginaConferenza(){
    ui->InserisciNomeConferenza->clear();
    ui->InserisciAcronimoConferenza->clear();
    ui->InserisciDataConferenza->clear();
    ui->InserisciLuogo->clear();
    ui->ListaOrganizzatori->clear();
    ui->InserisciPartecipantiConferenza->clear();
}

void MainWindow::on_SalvaConferenza_clicked(){
    string nome, acronimo, luogo; Data data; unsigned partecipanti;
    if(!InserisciConferenza(nome, acronimo, data, luogo, partecipanti)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Campo Vuoto", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    list<string> organizzatori;
    for(int i = 0; i < ui->ListaOrganizzatori->count(); i++){
        QListWidgetItem *item = ui->ListaOrganizzatori->item(i);           //puntatore item all'i-esima riga (item(i) = riga)
        string organizzatore = (item->text()).toStdString();               //prendo il testo nell'item e lo converto in string (Partendo da QString)
        organizzatori.push_back(organizzatore);
    }

    PulisciPaginaConferenza();

    if(!g.aggiungi_conferenza(nome, acronimo, data, luogo, organizzatori, partecipanti)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Mezzo divulgativo esistente", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    AggiungiInListaConferenze(nome);
}

void MainWindow::on_ListaConferenze_itemDoubleClicked(QListWidgetItem *item){
    string nome = (item->text()).toStdString();

    for(auto conferenza: g.lista_conferenze()){
        stringstream stream;
        stream << conferenza;

        if(nome == conferenza.get_nome()){
           ui->ConferenzaConsiderata->setPlainText(QString::fromStdString(stream.str()));
        }
    }
}

// METODI PER LA PAGINA A37

void MainWindow::AggiungiInListaRiviste(string nome){
    stringstream stream;
    stream << nome;
    ui->ListaRiviste->addItem(QString::fromStdString(stream.str()));
}

bool MainWindow::InserisciRivista(string& nome, string& acronimo, Data& data, string& editore, unsigned& volume){
    nome = (ui->InserisciNomeRivista->text()).toStdString();
    acronimo = (ui->InserisciAcronimoRivista->text()).toStdString();
    editore = (ui->InserisciEditore->text()).toStdString();
    volume = (ui->InserisciVolume->value());

    QDate qdata = ui->InserisciDataRivista->date();
    data.set_Data(qdata.day(), qdata.month(), qdata.year());

    if(nome.empty() || acronimo.empty() || editore.empty()){ return false; }
    return true;
}

void MainWindow::PulisciPaginaRivista(){
    ui->InserisciNomeRivista->clear();
    ui->InserisciAcronimoRivista->clear();
    ui->InserisciDataRivista->clear();
    ui->InserisciEditore->clear();
    ui->InserisciVolume->clear();
}

void MainWindow::on_SalvaRivista_clicked(){
    string nome, acronimo, editore; Data data; unsigned volume;
    if(!InserisciRivista(nome, acronimo, data, editore, volume)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Campo Vuoto", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    PulisciPaginaRivista();

    if(!g.aggiungi_rivista(nome, acronimo, data, editore, volume)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Mezzo divulgativo esistente", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    AggiungiInListaRiviste(nome);
}

void MainWindow::on_ListaRiviste_itemDoubleClicked(QListWidgetItem *item){
    string nome = (item->text()).toStdString();

    for(auto rivista: g.lista_riviste()){
        stringstream stream;
        stream << rivista;

        if(nome == rivista.get_nome()){
           ui->RivistaConsiderata->setPlainText(QString::fromStdString(stream.str()));
        }
    }
}

// METODI PER LA PAGINA A48

void MainWindow::AggiungiInListaArticoli(string identificativo){
    stringstream stream;
    stream << identificativo;
    ui->ListaArticoli->addItem(QString::fromStdString(stream.str()));
}

bool MainWindow::InserisciArticolo(string& identificativo, string& titolo, unsigned& pagine, double& prezzo, MezzoDivulgativo& mezzo){
    identificativo = (ui->InserisciIdentificativoArticolo->text()).toStdString();
    titolo = (ui->InserisciTitolo->text()).toStdString();
    pagine = ui->InserisciPagine->value();
    prezzo = ui->InserisciPrezzo->value();

    string nomeMezzo = (ui->InserisciNomeMezzo->text()).toStdString();
    string acronimoMezzo = (ui->InserisciAcronimoMezzo->text()).toStdString();
    Data data;

    QDate qdata = ui->InserisciDataMezzo->date();
    data.set_Data(qdata.day(), qdata.month(), qdata.year());

    MezzoDivulgativo nuovo(nomeMezzo, acronimoMezzo, data);
    mezzo = nuovo;

    if(identificativo.empty() || titolo.empty()){ return false; }
    return true;
}

void MainWindow::PulisciPaginaArticolo(){
    ui->InserisciIdentificativoArticolo->clear();
    ui->InserisciTitolo->clear();
    ui->InserisciPagine->clear();
    ui->InserisciPrezzo->clear();
    ui->InserisciAutoreArticolo->clear();
    ui->InserisciKeyword->clear();
    ui->InserisciArticoloCorrelato->clear();
    ui->ListaAutoriArticolo->clear();
    ui->ListaKeywords->clear();
    ui->ListaArticoliCorrelati->clear();
    ui->InserisciNomeMezzo->clear();
    ui->InserisciAcronimoMezzo->clear();
    ui->InserisciDataMezzo->clearMask();
}

void MainWindow::on_AggiungiAutoreArticolo_clicked(){
    QString autore = ui->InserisciAutoreArticolo->text();
    if(!autore.isEmpty()){ ui->ListaAutoriArticolo->addItem(autore); }

    ui->InserisciAutoreArticolo->clear();
}

void MainWindow::on_AggiungiKeyword_clicked(){
    QString keyword = ui->InserisciKeyword->text();
    if(!keyword.isEmpty()){ ui->ListaKeywords->addItem(keyword); }

    ui->InserisciKeyword->clear();
}

void MainWindow::on_AggiungiArticoloCorrelato_clicked(){
    QString articolo = ui->InserisciArticoloCorrelato->text();
    if(!articolo.isEmpty()){ ui->ListaArticoliCorrelati->addItem(articolo); }

    ui->InserisciArticoloCorrelato->clear();
}

void MainWindow::on_EliminaAutoreArticolo_clicked(){
    QListWidgetItem* autore = ui->ListaAutoriArticolo->takeItem(ui->ListaAutoriArticolo->currentRow());
    delete autore;
}

void MainWindow::on_EliminaKeyword_clicked(){
    QListWidgetItem* keyword = ui->ListaKeywords->takeItem(ui->ListaKeywords->currentRow());
    delete keyword;
}

void MainWindow::on_EliminaArticoloCorrelato_clicked(){
    QListWidgetItem* articolo = ui->ListaArticoliCorrelati->takeItem(ui->ListaArticoliCorrelati->currentRow());
    delete articolo;
}

void MainWindow::on_SalvaArticolo_clicked(){
    string identificativo, titolo;
    list<string> autori, keywords, articoli_correlati;
    unsigned pagine; double prezzo;
    MezzoDivulgativo mezzo;

    if(!InserisciArticolo(identificativo, titolo, pagine, prezzo, mezzo)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Campo Vuoto", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    for(int i = 0; i < ui->ListaAutoriArticolo->count(); i++){
        QListWidgetItem *item = ui->ListaAutoriArticolo->item(i);
        string autore = (item->text()).toStdString();
        autori.push_back(autore);
    }

    for(int i = 0; i < ui->ListaKeywords->count(); i++){
        QListWidgetItem *item = ui->ListaKeywords->item(i);
        string keyword = (item->text()).toStdString();
        keywords.push_back(keyword);
    }

    if(ui->ListaArticoliCorrelati->count() != 0){
        for(int i = 0; i < ui->ListaArticoliCorrelati->count(); i++){
            QListWidgetItem *item = ui->ListaArticoliCorrelati->item(i);
            string articolo = (item->text()).toStdString();
            articoli_correlati.push_back(articolo);
        }
    }

    PulisciPaginaArticolo();

    if(!g.aggiungi_articolo(identificativo, titolo, pagine, autori, keywords, prezzo, articoli_correlati, &mezzo)){
        QMessageBox message(QMessageBox::Critical,"Errore", "Le cause potrebbero essere: Id esistente\nAutore o Mezzo Divulgativo Inesistente", QMessageBox::Ok, this);
        message.exec();
        return;
    }

    AggiungiInListaArticoli(identificativo);
}

void MainWindow::on_ListaArticoli_itemDoubleClicked(QListWidgetItem *item){
    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloConsiderato->setPlainText(QString::fromStdString(stream.str()));
}

//SEZIONE B

void MainWindow::on_ListaArticoliAutore_itemDoubleClicked(QListWidgetItem *item){
    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloAutoreConsiderato->clear();
    ui->ArticoloAutoreConsiderato->appendPlainText(QString::fromStdString(stream.str()));
}

void MainWindow::AggiungiInListaArticoliAutore(string identificativo){
     list<Articolo> articoli = g.articoli_autore(identificativo);

     ui->ListaArticoliAutore->clear();

     for(auto articolo: articoli){
          stringstream stream;
          stream << articolo.get_identificativo();
          ui->ListaArticoliAutore->addItem(QString::fromStdString(stream.str()));
     }
}

void MainWindow::on_CercaArticoliAutore_clicked(){
    string identificativo = (ui->IdentificativoAutore->text()).toStdString();
    ui->IdentificativoAutore->clear();

    AggiungiInListaArticoliAutore(identificativo);
}

void MainWindow::on_ListaArticoliRivista_itemDoubleClicked(QListWidgetItem *item){
    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloRivistaConsiderato->clear();
    ui->ArticoloRivistaConsiderato->appendPlainText(QString::fromStdString(stream.str()));
}

void MainWindow::AggiungiInListaArticoliRivista(string nome, string acronimo, const Data& data){
     list<Articolo> articoli = g.articoli_rivista(nome, acronimo, data);

     ui->ListaArticoliRivista->clear();

     for(auto articolo: articoli){
          stringstream stream;
          stream << articolo.get_identificativo();
          ui->ListaArticoliRivista->addItem(QString::fromStdString(stream.str()));
     }
}

void MainWindow::on_CercaArticoliRivista_clicked(){
    string nome = (ui->NomeRivista->text()).toStdString();
    string acronimo = (ui->AcronimoRivista->text()).toStdString();

    QDate qdata = ui->DataRivista->date();
    Data data(qdata.day(), qdata.month(), qdata.year());

    AggiungiInListaArticoliRivista(nome, acronimo, data);
}

void MainWindow::on_ListaArticoliConferenza_itemDoubleClicked(QListWidgetItem *item){
    string identificativo = (item->text()).toStdString();

    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloConferenzaConsiderato->clear();
    ui->ArticoloConferenzaConsiderato->appendPlainText(QString::fromStdString(stream.str()));
}

void MainWindow::AggiungiInListaArticoliConferenza(string nome, string acronimo, const Data& data){
     list<Articolo> articoli = g.articoli_conferenza(nome, acronimo, data);

     ui->ListaArticoliConferenza->clear();

     for(auto articolo: articoli){
          stringstream stream;
          stream << articolo.get_identificativo();
          ui->ListaArticoliConferenza->addItem(QString::fromStdString(stream.str()));
     }
}

void MainWindow::on_CercaArticoliConferenza_clicked(){
    string nome = (ui->NomeConferenza->text()).toStdString();
    string acronimo = (ui->AcronimoConferenza->text()).toStdString();

    QDate qdata = ui->DataConferenza->date();
    Data data(qdata.day(), qdata.month(), qdata.year());

    ui->NomeConferenza->clear();ui->AcronimoConferenza->clear();
    AggiungiInListaArticoliConferenza(nome, acronimo, data);
}

//SEZIONE C

void MainWindow::AggiungiInListaPrezziArticoliAutore(const list<Articolo>& articoli){
    ui->ListaPrezziArticoliAutore->clear();

    for(auto articolo: articoli){
        stringstream stream;
        stream << articolo.get_identificativo();
        ui->ListaPrezziArticoliAutore->addItem(QString::fromStdString(stream.str()));
    }
}

void MainWindow::on_CercaArticoliPrezzo_clicked(){
    string identificativo = (ui->IdentificativoPrezzoAutore->text()).toStdString();
    list<Articolo> articoli;

    if(ui->PrezzoBasso->isChecked()){ articoli = g.articoli_prezzobasso_autore(identificativo); }
    if(ui->PrezzoAlto->isChecked()){ articoli = g.articoli_prezzoalto_autore(identificativo); }

    ui->MediaPrezzi->setValue(g.media_articoli_autore(identificativo));
    AggiungiInListaPrezziArticoliAutore(articoli);
}

void MainWindow::on_ListaPrezziArticoliAutore_itemDoubleClicked(QListWidgetItem *item){
    ui->PrezzoArticoloAutoreConsiderato->clear();

    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->PrezzoArticoloAutoreConsiderato->appendPlainText(QString::fromStdString(stream.str()));
}

//SEZIONE D

void MainWindow::AggiungiInListaArticoliRivistaOrdinati(string nome, string acronimo, const Data& data){
    ui->ListaArticoliRivistaOrdinati->clear();

    list<Articolo> articoli = g.articoli_rivista_prezzo(nome, acronimo, data);

    for(auto articolo: articoli){
        stringstream stream;
        stream << articolo.get_identificativo();
        ui->ListaArticoliRivistaOrdinati->addItem(QString::fromStdString(stream.str()));
    }
}

void MainWindow::on_VisualizzaArticoliRivistaOrdinati_clicked(){
    string nome = (ui->NomeRivistaDaOrdinare->text()).toStdString();
    string acronimo = (ui->AcronimoRivistaDaOrdinare->text()).toStdString();

    QDate qdata = ui->DataRivistaDaOrdinare->date();
    Data data(qdata.day(), qdata.month(), qdata.year());

    ui->NomeRivistaDaOrdinare->clear();
    ui->AcronimoRivistaDaOrdinare->clear();
    ui->DataRivistaDaOrdinare->clear();

    AggiungiInListaArticoliRivistaOrdinati(nome, acronimo, data);
}

void MainWindow::on_ListaArticoliRivistaOrdinati_itemDoubleClicked(QListWidgetItem *item){
    ui->ArticoloRivistaConsiderato_2->clear();

    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloRivistaConsiderato_2->appendPlainText(QString::fromStdString(stream.str()));
}

void MainWindow::AggiungiInListaArticoliConferenzaOrdinati(string nome, string acronimo, const Data& data){
    ui->ListaArticoliConferenzaOrdinati->clear();

    list<Articolo> articoli = g.articoli_conferenza_prezzo(nome, acronimo, data);

    for(auto articolo: articoli){
        stringstream stream;
        stream << articolo.get_identificativo();
        ui->ListaArticoliConferenzaOrdinati->addItem(QString::fromStdString(stream.str()));
    }
}

void MainWindow::on_VisualizzaArticoliConferenzaOrdinati_clicked(){
    string nome = (ui->NomeConferenzaDaOrdinare->text()).toStdString();
    string acronimo = (ui->AcronimoConferenzaDaOrdinare->text()).toStdString();

    QDate qdata = ui->DataConferenzaDaOrdinare->date();
    Data data(qdata.day(), qdata.month(), qdata.year());

    ui->NomeConferenzaDaOrdinare->clear();
    ui->AcronimoConferenzaDaOrdinare->clear();
    ui->DataConferenzaDaOrdinare->clear();

    AggiungiInListaArticoliConferenzaOrdinati(nome, acronimo, data);
}

void MainWindow::on_ListaArticoliConferenzaOrdinati_itemDoubleClicked(QListWidgetItem *item){
    ui->ArticoloConferenzaConsiderato_2->clear();

    string identificativo = (item->text()).toStdString();
    Articolo articolo = *(g.get_articolo(identificativo));

    stringstream stream;
    stream << articolo;

    ui->ArticoloConferenzaConsiderato_2->appendPlainText(QString::fromStdString(stream.str()));
}

//SEZIONE E

void MainWindow::AggiungiInListaRivisteNoAutori(string identificativo){
    ui->ListaRivisteNoAutore->clear();

    list<MezzoDivulgativo*> riviste = g.riviste_nonpubblicate_autore(identificativo);
    for(auto rivista: riviste){
        stringstream stream;
        stream << rivista->get_nome();

        ui->ListaRivisteNoAutore->addItem(QString::fromStdString(stream.str()));
    }
}

void MainWindow::on_VisualizzaRivisteNoAutore_clicked(){
    string identificativo = (ui->IdentificativoAutoreNoRivista->text()).toStdString();
    ui->IdentificativoAutoreNoRivista->clear();

    AggiungiInListaRivisteNoAutori(identificativo);
}

void MainWindow::on_ListaRivisteNoAutore_itemDoubleClicked(QListWidgetItem *item){
    ui->RivistaNoAutoreConsiderata->clear();

    string nome = (item->text()).toStdString();
    Rivista rivista = *(g.get_rivista(nome));

    stringstream stream;
    stream << rivista;

    ui->RivistaNoAutoreConsiderata->appendPlainText(QString::fromStdString(stream.str()));
}
