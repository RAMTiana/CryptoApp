#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../crypto/AESUtils.h"
#include "../crypto/BlowfishUtils.h"
#include "../crypto/RSAUtils.h"
#include "../crypto/HashUtils.h"
#include "../core/FileManager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

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

void MainWindow::on_browseButton_clicked() {
    filePath = QFileDialog::getOpenFileName(this, "Choisir un fichier");
    ui->fileLabel->setText(filePath);
}

void MainWindow::on_encryptButton_clicked() {
    if(filePath.isEmpty()) { QMessageBox::warning(this, "Erreur", "Aucun fichier sélectionné."); return; }

    QString algo = ui->algorithmComboBox->currentText();
    QString keyInput = ui->keyLineEdit->text().trimmed();

    try {
        std::vector<unsigned char> data = FileManager::readFile(filePath.toStdString());
        std::vector<unsigned char> out;

        if(algo == "AES") {
            if(!(keyInput.size()==16 || keyInput.size()==24 || keyInput.size()==32)) {
                QMessageBox::warning(this, "Erreur", "La clé AES doit faire 16, 24 ou 32 octets.");
                return;
            }
            out = AESUtils::encrypt(std::string(data.begin(), data.end()), keyInput.toStdString());
        }
        else if(algo == "Blowfish") {
            if(!(keyInput.size() >= 4 && keyInput.size() <= 56)) {
                QMessageBox::warning(this, "Erreur", "La clé Blowfish doit faire entre 4 et 56 octets.");
                return;
            }
            out = BlowfishUtils::encrypt(std::string(data.begin(), data.end()), keyInput.toStdString());
        }
        else if(algo == "RSA") {
            // here keyInput should be path to public key
            if(keyInput.isEmpty() || !QFileInfo::exists(keyInput)) {
                QMessageBox::warning(this, "Erreur", "Pour RSA, entrez le chemin du fichier de clé publique (.pem) dans le champ clé.");
                return;
            }
            out = RSAUtils::encrypt(std::string(data.begin(), data.end()), keyInput.toStdString());
        }

        FileManager::writeFile(filePath.toStdString() + ".enc", out);
        QMessageBox::information(this, "Succès", "Fichier chiffré !");
    } catch(const std::exception& ex) {
        QMessageBox::critical(this, "Erreur", QString::fromStdString(ex.what()));
    }
}

void MainWindow::on_decryptButton_clicked() {
    if(filePath.isEmpty()) { QMessageBox::warning(this, "Erreur", "Aucun fichier sélectionné."); return; }

    QString algo = ui->algorithmComboBox->currentText();
    QString keyInput = ui->keyLineEdit->text().trimmed();

    try {
        std::vector<unsigned char> data = FileManager::readFile(filePath.toStdString());
        std::string out;

        if(algo == "AES") {
            if(!(keyInput.size()==16 || keyInput.size()==24 || keyInput.size()==32)) {
                QMessageBox::warning(this, "Erreur", "La clé AES doit faire 16, 24 ou 32 octets.");
                return;
            }
            out = AESUtils::decrypt(data, keyInput.toStdString());
        }
        else if(algo == "Blowfish") {
            if(!(keyInput.size() >= 4 && keyInput.size() <= 56)) {
                QMessageBox::warning(this, "Erreur", "La clé Blowfish doit faire entre 4 et 56 octets.");
                return;
            }
            out = BlowfishUtils::decrypt(data, keyInput.toStdString());
        }
        else if(algo == "RSA") {
            // keyInput should be path to private key
            if(keyInput.isEmpty() || !QFileInfo::exists(keyInput)) {
                QMessageBox::warning(this, "Erreur", "Pour RSA, entrez le chemin du fichier de clé privée (.pem) dans le champ clé.");
                return;
            }
            out = RSAUtils::decrypt(data, keyInput.toStdString());
        }

        FileManager::writeFile(filePath.toStdString() + ".dec", std::vector<unsigned char>(out.begin(), out.end()));
        QMessageBox::information(this, "Succès", "Fichier déchiffré !");
    } catch(const std::exception& ex) {
        QMessageBox::critical(this, "Erreur", QString::fromStdString(ex.what()));
    }
}

void MainWindow::on_hashButton_clicked() {
    if(filePath.isEmpty()) { QMessageBox::warning(this, "Erreur", "Aucun fichier sélectionné."); return; }

    try {
        std::vector<unsigned char> data = FileManager::readFile(filePath.toStdString());
        std::string md5hash = HashUtils::md5(std::string(data.begin(), data.end()));
        std::string sha256hash = HashUtils::sha256(std::string(data.begin(), data.end()));
        ui->hashTextEdit->setPlainText(QString::fromStdString("MD5: " + md5hash + "\nSHA-256: " + sha256hash));
    } catch(const std::exception& ex) {
        QMessageBox::critical(this, "Erreur", QString::fromStdString(ex.what()));
    }
}
