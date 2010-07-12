/***************************************************************************
 *   Copyright © 2010 Jonathan Thomas <echidnaman@kubuntu.org>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation; either version 2 of        *
 *   the License or (at your option) version 3 or any later version        *
 *   accepted by the membership of KDE e.V. (or its successor approved     *
 *   by the membership of KDE e.V.), which shall act as a proxy            *
 *   defined in Section 14 of version 3 of the license.                    *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// KDE includes
#include <KXmlGuiWindow>

// Qt includes
#include <QtCore/QVariantMap>

// LibQApt includes
#include <libqapt/globals.h>

class QSplitter;
class QStackedWidget;
class QToolBox;
class KAction;

class FilterWidget;
class ManagerWidget;
class ReviewWidget;
class DownloadWidget;
class CommitWidget;
class StatusWidget;

namespace QApt
{
    class Backend;
}

/**
 * This class serves as the main window for Muon.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author Jonathan Thomas <echidnaman@kubuntu.org>
 * @version 0.1
 */
class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    virtual bool queryExit();

private:
    QApt::Backend *m_backend;
    QList<QVariantMap> m_warningStack;
    QList<QVariantMap> m_errorStack;

    QStackedWidget *m_stack;
    QSplitter *m_mainWidget;
    KAction *m_updateAction;
    KAction *m_safeUpgradeAction;
    KAction *m_distUpgradeAction;
    KAction *m_previewAction;
    KAction *m_applyAction;
    KAction *m_undoAction;
    KAction *m_redoAction;
    KAction *m_revertAction;
    KAction *m_saveSelectionsAction;
    KAction *m_loadSelectionsAction;

    FilterWidget *m_filterBox;
    ManagerWidget *m_managerWidget;
    ReviewWidget *m_reviewWidget;
    DownloadWidget *m_downloadWidget;
    CommitWidget *m_commitWidget;
    StatusWidget *m_statusWidget;

    int m_powerInhibitor;
    bool m_canExit;

private Q_SLOTS:
    void initGUI();
    void initObject();
    void loadSplitterSizes();
    void saveSplitterSizes();
    void setupActions();
    void slotQuit();
    void markUpgrade();
    void markDistUpgrade();
    void checkForUpdates();
    void workerEvent(QApt::WorkerEvent event);
    void errorOccurred(QApt::ErrorCode code, const QVariantMap &args);
    void warningOccurred(QApt::WarningCode warning, const QVariantMap &args);
    void questionOccurred(QApt::WorkerQuestion question, const QVariantMap &details);
    void showQueuedWarnings();
    void showQueuedErrors();
    void previewChanges();
    void returnFromPreview();
    void startCommit();
    void initDownloadWidget();
    void initCommitWidget();
    void reload();
    void reloadActions();
    void setActionsEnabled(bool enabled);
    void undo();
    void redo();
    void revertChanges();
    void runSourcesEditor();
    void sourcesEditorFinished(int exitCode);
    bool saveSelections();
    void loadSelections();
    void easterEggTriggered();

signals:
    void backendReady(QApt::Backend *backend);
};

#endif // _MUON_H_
