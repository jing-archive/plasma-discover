/***************************************************************************
 *   Copyright © 2008 by Daniel Nicoletti <dantti85-pk@yahoo.com.br>       *
 *   Copyright © 2010 Jonathan Thomas <echidnaman@kubuntu.org>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; see the file COPYING. If not, write to       *
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,  *
 *   Boston, MA 02110-1301, USA.                                           *
 ***************************************************************************/

#ifndef APPLICATIONLAUCHER_H
#define APPLICATIONLAUCHER_H

#include <QtGui/QDialog>

class QCheckBox;
class QModelIndex;
class QStandardItemModel;

class KService;

class ApplicationLauncher : public QDialog
{
    Q_OBJECT
public:
    explicit ApplicationLauncher(const QVector<KService*> &applications, QWidget *parent = 0);
    ~ApplicationLauncher();

private:
    QStandardItemModel *m_model;
    QCheckBox *m_noShowCheckBox;

private Q_SLOTS:
    void onAppClicked(const QModelIndex &index);
    void addApplications(const QVector<KService*> &applications);
};

#endif
