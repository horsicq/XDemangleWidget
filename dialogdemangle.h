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
#ifndef DIALOGDEMANGLE_H
#define DIALOGDEMANGLE_H

#include "xshortcutsdialog.h"

namespace Ui {
class DialogDemangle;
}

class DialogDemangle : public XShortcutsDialog {
    Q_OBJECT

public:
    explicit DialogDemangle(QWidget *pParent, const QString &sString = "");
    ~DialogDemangle();

    virtual void adjustView();

    void setData(const QString &sString);
    void setGlobal(XShortcuts *pShortcuts, XOptions *pXOptions);

private slots:
    void on_pushButton_clicked();

protected:
    virtual void registerShortcuts(bool bState);

private:
    Ui::DialogDemangle *ui;
};

#endif  // DIALOGDEMANGLE_H
