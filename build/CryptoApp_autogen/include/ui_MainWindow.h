/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *fileLabel;
    QPushButton *browseButton;
    QLineEdit *keyLineEdit;
    QComboBox *algorithmComboBox;
    QHBoxLayout *buttonLayout;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QPushButton *hashButton;
    QTextEdit *hashTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(fileLabel);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");

        verticalLayout->addWidget(browseButton);

        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");

        verticalLayout->addWidget(keyLineEdit);

        algorithmComboBox = new QComboBox(centralwidget);
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->setObjectName("algorithmComboBox");

        verticalLayout->addWidget(algorithmComboBox);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        encryptButton = new QPushButton(centralwidget);
        encryptButton->setObjectName("encryptButton");

        buttonLayout->addWidget(encryptButton);

        decryptButton = new QPushButton(centralwidget);
        decryptButton->setObjectName("decryptButton");

        buttonLayout->addWidget(decryptButton);

        hashButton = new QPushButton(centralwidget);
        hashButton->setObjectName("hashButton");

        buttonLayout->addWidget(hashButton);


        verticalLayout->addLayout(buttonLayout);

        hashTextEdit = new QTextEdit(centralwidget);
        hashTextEdit->setObjectName("hashTextEdit");
        hashTextEdit->setReadOnly(true);

        verticalLayout->addWidget(hashTextEdit);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        algorithmComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CryptoApp", nullptr));
        fileLabel->setText(QCoreApplication::translate("MainWindow", "Fichier choisi : Aucun", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Parcourir...", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez la cl\303\251 de chiffrement", nullptr));
        algorithmComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "AES", nullptr));
        algorithmComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Blowfish", nullptr));
        algorithmComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "RSA", nullptr));

        encryptButton->setText(QCoreApplication::translate("MainWindow", "Chiffrer", nullptr));
        decryptButton->setText(QCoreApplication::translate("MainWindow", "D\303\251chiffrer", nullptr));
        hashButton->setText(QCoreApplication::translate("MainWindow", "Hasher", nullptr));
        hashTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Les r\303\251sultats des hachages MD5 et SHA-256 appara\303\256tront ici...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
