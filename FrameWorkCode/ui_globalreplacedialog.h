/********************************************************************************
** Form generated from reading UI file 'globalreplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALREPLACEDIALOG_H
#define UI_GLOBALREPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GlobalReplaceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *GlobalReplaceDialog)
    {
        if (GlobalReplaceDialog->objectName().isEmpty())
            GlobalReplaceDialog->setObjectName(QStringLiteral("GlobalReplaceDialog"));
        GlobalReplaceDialog->resize(540, 394);
        GlobalReplaceDialog->setStyleSheet(QLatin1String("font: 11pt \"Work Sans\"; \n"
"background-color: rgb(32, 33, 72);"));
        verticalLayout = new QVBoxLayout(GlobalReplaceDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(GlobalReplaceDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("background-color: white; color:black;"));

        horizontalLayout_2->addWidget(listWidget);

        groupBox = new QGroupBox(GlobalReplaceDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);

        textBrowser = new QTextBrowser(GlobalReplaceDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(382, 122));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QLatin1String("font: 11pt \"Work Sans\"; \n"
"background-color: white;"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(GlobalReplaceDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(GlobalReplaceDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(applyButton);

        cancelButton = new QPushButton(GlobalReplaceDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GlobalReplaceDialog);

        QMetaObject::connectSlotsByName(GlobalReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *GlobalReplaceDialog)
    {
        GlobalReplaceDialog->setWindowTitle(QApplication::translate("GlobalReplaceDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        textBrowser->setHtml(QApplication::translate("GlobalReplaceDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; color:#000000;\">Click &quot;Yes&quot; to save the changes and replace the word in the unedited pages.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; color:#000000;\">Click &quot;No&quot; to save the changes and not replace the word in the unedited pages.</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GlobalReplaceDialog", "Preview", Q_NULLPTR));
        applyButton->setText(QApplication::translate("GlobalReplaceDialog", "Yes", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("GlobalReplaceDialog", "No", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GlobalReplaceDialog: public Ui_GlobalReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALREPLACEDIALOG_H
