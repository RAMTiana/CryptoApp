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
#include <QtWidgets/QFrame>
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
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QFrame *line1;
    QHBoxLayout *fileLayout;
    QLabel *fileLabel;
    QPushButton *browseButton;
    QLineEdit *keyLineEdit;
    QHBoxLayout *algoLayout;
    QLabel *algoLabel;
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
        MainWindow->resize(700, 520);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(15);
        mainLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout->setObjectName("mainLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2E4053;"));

        mainLayout->addWidget(titleLabel);

        line1 = new QFrame(centralwidget);
        line1->setObjectName("line1");
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(line1);

        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(10);
        fileLayout->setObjectName("fileLayout");
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);

        fileLayout->addWidget(fileLabel);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");
        browseButton->setMinimumWidth(120);

        fileLayout->addWidget(browseButton);


        mainLayout->addLayout(fileLayout);

        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");
        keyLineEdit->setStyleSheet(QString::fromUtf8("padding: 8px; border: 1px solid #BDC3C7; border-radius: 6px;"));

        mainLayout->addWidget(keyLineEdit);

        algoLayout = new QHBoxLayout();
        algoLayout->setObjectName("algoLayout");
        algoLabel = new QLabel(centralwidget);
        algoLabel->setObjectName("algoLabel");

        algoLayout->addWidget(algoLabel);

        algorithmComboBox = new QComboBox(centralwidget);
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->setObjectName("algorithmComboBox");
        algorithmComboBox->setMinimumWidth(150);

        algoLayout->addWidget(algorithmComboBox);


        mainLayout->addLayout(algoLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(20);
        buttonLayout->setObjectName("buttonLayout");
        encryptButton = new QPushButton(centralwidget);
        encryptButton->setObjectName("encryptButton");
        encryptButton->setStyleSheet(QString::fromUtf8("background-color: #2ECC71; color: white; border-radius: 8px; padding: 8px 15px;"));

        buttonLayout->addWidget(encryptButton);

        decryptButton = new QPushButton(centralwidget);
        decryptButton->setObjectName("decryptButton");
        decryptButton->setStyleSheet(QString::fromUtf8("background-color: #E67E22; color: white; border-radius: 8px; padding: 8px 15px;"));

        buttonLayout->addWidget(decryptButton);

        hashButton = new QPushButton(centralwidget);
        hashButton->setObjectName("hashButton");
        hashButton->setStyleSheet(QString::fromUtf8("background-color: #3498DB; color: white; border-radius: 8px; padding: 8px 15px;"));

        buttonLayout->addWidget(hashButton);


        mainLayout->addLayout(buttonLayout);

        hashTextEdit = new QTextEdit(centralwidget);
        hashTextEdit->setObjectName("hashTextEdit");
        hashTextEdit->setReadOnly(true);
        hashTextEdit->setStyleSheet(QString::fromUtf8("background-color: #F4F6F7; border: 1px solid #BDC3C7; border-radius: 6px; padding: 8px;"));

        mainLayout->addWidget(hashTextEdit);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\360\237\224\220 CryptoApp - Chiffrement et Hachage", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\224\222 Outil de chiffrement et de hachage", nullptr));
        fileLabel->setText(QCoreApplication::translate("MainWindow", "Fichier choisi : Aucun", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202 Parcourir...", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\224\221 Entrez la cl\303\251 de chiffrement", nullptr));
        algoLabel->setText(QCoreApplication::translate("MainWindow", "Algorithme :", nullptr));
        algorithmComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "AES", nullptr));
        algorithmComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Blowfish", nullptr));
        algorithmComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "RSA", nullptr));

        encryptButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\220 Chiffrer", nullptr));
        decryptButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\223 D\303\251chiffrer", nullptr));
        hashButton->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 Hasher", nullptr));
        hashTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\247\276 Les r\303\251sultats des hachages MD5 et SHA-256 appara\303\256tront ici...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
