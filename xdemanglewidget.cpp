// Copyright (c) 2021 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "xdemanglewidget.h"
#include "ui_xdemanglewidget.h"

XDemangleWidget::XDemangleWidget(QWidget *pParent) :
    XShortcutsWidget(pParent),
    ui(new Ui::XDemangleWidget)
{
    ui->setupUi(this);

#if QT_VERSION >= QT_VERSION_CHECK(5,3,0)
    const QSignalBlocker blocker(ui->comboBoxMode);
#else
    const bool bBlocked1=ui->comboBoxMode->blockSignals(true);
#endif

//    QList<XDemangle::MODE> listModes=XDemangle::getAllModes();
    QList<XDemangle::MODE> listModes=XDemangle::getSupportedModes();

    qint32 nNumberOfModes=listModes.count();

    for(qint32 i=0;i<nNumberOfModes;i++)
    {
        XDemangle::MODE mode=listModes.at(i);
        ui->comboBoxMode->addItem(XDemangle::modeIdToString(mode),mode);
    }

#if QT_VERSION < QT_VERSION_CHECK(5,3,0)
    ui->comboBoxMode->blockSignals(bBlocked1);
#endif
}

XDemangleWidget::~XDemangleWidget()
{
    delete ui;
}

void XDemangleWidget::setData(QString sString)
{
    ui->plainTextEditInput->setPlainText(sString);
}

void XDemangleWidget::process()
{
    QString sText=ui->plainTextEditInput->toPlainText().trimmed();
    XDemangle::MODE mode=(XDemangle::MODE)(ui->comboBoxMode->currentData().toInt());

    if(mode==XDemangle::MODE_AUTO)
    {
        mode=XDemangle::detectMode(sText);
    }

    ui->labelMode->setText(XDemangle::modeIdToString(mode));

    QString sResult=XDemangle().demangle(sText,mode);

    ui->plainTextEditResult->setPlainText(sResult);
}

void XDemangleWidget::registerShortcuts(bool bState)
{
    Q_UNUSED(bState)
}

void XDemangleWidget::on_comboBoxMode_currentIndexChanged(int nIndex)
{
    Q_UNUSED(nIndex)

    process();
//    process_llvm();
}

void XDemangleWidget::on_plainTextEditInput_textChanged()
{
    process();
//    process_llvm();
}
