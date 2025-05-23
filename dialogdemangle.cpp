/* Copyright (c) 2021-2025 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "dialogdemangle.h"

#include "ui_dialogdemangle.h"

DialogDemangle::DialogDemangle(QWidget *pParent, const QString &sString) : XShortcutsDialog(pParent, false), ui(new Ui::DialogDemangle)
{
    ui->setupUi(this);

    ui->widgetDemangle->setData(sString);
}

DialogDemangle::~DialogDemangle()
{
    delete ui;
}

void DialogDemangle::adjustView()
{
}

void DialogDemangle::setData(const QString &sString)
{
    ui->widgetDemangle->setData(sString);
}

void DialogDemangle::setGlobal(XShortcuts *pShortcuts, XOptions *pXOptions)
{
    ui->widgetDemangle->setGlobal(pShortcuts, pXOptions);
    XShortcutsDialog::setGlobal(pShortcuts, pXOptions);
}

void DialogDemangle::on_pushButton_clicked()
{
    this->close();
}

void DialogDemangle::registerShortcuts(bool bState)
{
    Q_UNUSED(bState)
}
