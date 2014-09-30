/***************************************************************************
 *   Copyright © 2012-2014 Aleix Pol Gonzalez <aleixpol@blue-systems.com>  *
 *   Copyright © 2013 Lukas Appelhans <l.appelhans@gmx.de>                 *
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

#include "PackageKitMessages.h"
#include <PackageKit/Transaction>
#include <Daemon>
#include <KLocalizedString>

namespace PackageKitMessages
{

QString errorMessage(PackageKit::Transaction::Error error)
{
    switch(error) {
        case PackageKit::Transaction::ErrorOom:
            return i18n("Out of memory");
        case PackageKit::Transaction::ErrorNoNetwork:
            return i18n("No network connection available");
        case PackageKit::Transaction::ErrorNotSupported:
            return i18n("Operation not supported");
        case PackageKit::Transaction::ErrorInternalError:
            return i18n("Internal error");
        case PackageKit::Transaction::ErrorGpgFailure:
            return i18n("GPG failure");
        case PackageKit::Transaction::ErrorPackageIdInvalid:
            return i18n("PackageID invalid");
        case PackageKit::Transaction::ErrorPackageNotInstalled:
            return i18n("Package not installed");
        case PackageKit::Transaction::ErrorPackageNotFound:
            return i18n("Package not found");
        case PackageKit::Transaction::ErrorPackageAlreadyInstalled:
            return i18n("Package is already installed");
        case PackageKit::Transaction::ErrorPackageDownloadFailed:
            return i18n("Package download failed");
        case PackageKit::Transaction::ErrorGroupNotFound:
            return i18n("Package group not found");
        case PackageKit::Transaction::ErrorGroupListInvalid:
            return i18n("Package group list invalid");
        case PackageKit::Transaction::ErrorDepResolutionFailed:
            return i18n("Dependency resolution failed");
        case PackageKit::Transaction::ErrorFilterInvalid:
            return i18n("Filter invalid");
        case PackageKit::Transaction::ErrorCreateThreadFailed:
            return i18n("Failed while creating a thread");
        case PackageKit::Transaction::ErrorTransactionError:
            return i18n("Transaction failure");
        case PackageKit::Transaction::ErrorTransactionCancelled:
            return i18n("Transaction canceled");
        case PackageKit::Transaction::ErrorNoCache:
            return i18n("No Cache available");
        case PackageKit::Transaction::ErrorRepoNotFound:
            return i18n("Cannot find repository");
        case PackageKit::Transaction::ErrorCannotRemoveSystemPackage:
            return i18n("Cannot remove system package");
        case PackageKit::Transaction::ErrorProcessKill:
            return i18n("Cannot kill process");
        case PackageKit::Transaction::ErrorFailedInitialization:
            return i18n("Initialization failure");
        case PackageKit::Transaction::ErrorFailedFinalise:
            return i18n("Failed to finalize transaction");
        case PackageKit::Transaction::ErrorFailedConfigParsing:
            return i18n("Config parsing failed");
        case PackageKit::Transaction::ErrorCannotCancel:
            return i18n("Cannot cancel transaction");
        case PackageKit::Transaction::ErrorCannotGetLock:
            return i18n("Cannot obtain lock");
        case PackageKit::Transaction::ErrorNoPackagesToUpdate:
            return i18n("No packages to update");
        case PackageKit::Transaction::ErrorCannotWriteRepoConfig:
            return i18n("Cannot write repo config");
        case PackageKit::Transaction::ErrorLocalInstallFailed:
            return i18n("Local install failed");
        case PackageKit::Transaction::ErrorBadGpgSignature:
            return i18n("Bad GPG signature found");
        case PackageKit::Transaction::ErrorMissingGpgSignature:
            return i18n("No GPG signature found");
        case PackageKit::Transaction::ErrorCannotInstallSourcePackage:
            return i18n("Cannot install source package");
        case PackageKit::Transaction::ErrorRepoConfigurationError:
            return i18n("Repo configuration error");
        case PackageKit::Transaction::ErrorNoLicenseAgreement:
            return i18n("No license agreement");
        case PackageKit::Transaction::ErrorFileConflicts:
            return i18n("File conflicts found");
        case PackageKit::Transaction::ErrorPackageConflicts:
            return i18n("Package conflict found");
        case PackageKit::Transaction::ErrorRepoNotAvailable:
            return i18n("Repo not available");
        case PackageKit::Transaction::ErrorInvalidPackageFile:
            return i18n("Invalid package file");
        case PackageKit::Transaction::ErrorPackageInstallBlocked:
            return i18n("Package install blocked");
        case PackageKit::Transaction::ErrorPackageCorrupt:
            return i18n("Corrupt package found");
        case PackageKit::Transaction::ErrorAllPackagesAlreadyInstalled:
            return i18n("All packages already installed");
        case PackageKit::Transaction::ErrorFileNotFound:
            return i18n("File not found");
        case PackageKit::Transaction::ErrorNoMoreMirrorsToTry:
            return i18n("No more mirrors available");
        case PackageKit::Transaction::ErrorNoDistroUpgradeData:
            return i18n("No distro upgrade data");
        case PackageKit::Transaction::ErrorIncompatibleArchitecture:
            return i18n("Incompatible architecture");
        case PackageKit::Transaction::ErrorNoSpaceOnDevice:
            return i18n("No space on device left");
        case PackageKit::Transaction::ErrorMediaChangeRequired:
            return i18n("A media change is required");
        case PackageKit::Transaction::ErrorNotAuthorized:
            return i18n("You have no authorization to execute this operation");
        case PackageKit::Transaction::ErrorUpdateNotFound:
            return i18n("Update not found");
        case PackageKit::Transaction::ErrorCannotInstallRepoUnsigned:
            return  i18n("Cannot install from unsigned repo");
        case PackageKit::Transaction::ErrorCannotUpdateRepoUnsigned:
            return i18n("Cannot update from unsigned repo");
        case PackageKit::Transaction::ErrorCannotGetFilelist:
            return i18n("Cannot get file list");
        case PackageKit::Transaction::ErrorCannotGetRequires:
            return i18n("Cannot get requires");
        case PackageKit::Transaction::ErrorCannotDisableRepository:
            return i18n("Cannot disable repository");
        case PackageKit::Transaction::ErrorRestrictedDownload:
            return i18n("Restricted download detected");
        case PackageKit::Transaction::ErrorPackageFailedToConfigure:
            return i18n("Package failed to configure");
        case PackageKit::Transaction::ErrorPackageFailedToBuild:
            return i18n("Package failed to build");
        case PackageKit::Transaction::ErrorPackageFailedToInstall:
            return i18n("Package failed to install");
        case PackageKit::Transaction::ErrorPackageFailedToRemove:
            return i18n("Package failed to remove");
        case PackageKit::Transaction::ErrorUpdateFailedDueToRunningProcess:
            return i18n("Update failed due to running process");
        case PackageKit::Transaction::ErrorPackageDatabaseChanged:
            return i18n("The package database changed");
        case PackageKit::Transaction::ErrorProvideTypeNotSupported:
            return i18n("The provided type is not supported");
        case PackageKit::Transaction::ErrorInstallRootInvalid:
            return i18n("Install root is invalid");
        case PackageKit::Transaction::ErrorCannotFetchSources:
            return i18n("Cannot fetch sources");
        case PackageKit::Transaction::ErrorCancelledPriority:
            return i18n("Canceled priority");
        case PackageKit::Transaction::ErrorUnfinishedTransaction:
            return i18n("Unfinished transaction");
        case PackageKit::Transaction::ErrorLockRequired:
            return i18n("Lock required");
        case PackageKit::Transaction::ErrorUnknown:
        default:
            return i18n("Unknown error");
    }
}

QString restartMessage(PackageKit::Transaction::Restart restart, const QString& pkgid)
{
    QString message;
    switch (restart) {
        case PackageKit::Transaction::RestartApplication:
            message = i18n("'%1' was changed and suggests to be restarted.", PackageKit::Daemon::packageName(pkgid));
            break;
        case PackageKit::Transaction::RestartSession:
            message = i18n("A change by '%1' suggests your session to be restarted.", PackageKit::Daemon::packageName(pkgid));
            break;
        case PackageKit::Transaction::RestartSecuritySession:
            message = i18n("'%1' was updated for security reasons, a restart of the session is recommended.", PackageKit::Daemon::packageName(pkgid));
            break;
        case PackageKit::Transaction::RestartSecuritySystem:
            message = i18n("'%1' was updated for security reasons, a restart of the system is recommended.", PackageKit::Daemon::packageName(pkgid));
            break;
        case PackageKit::Transaction::RestartSystem:
        case PackageKit::Transaction::RestartUnknown:
        case PackageKit::Transaction::RestartNone:
        default:
            message = i18n("A change by '%1' suggests your system to be rebooted.", PackageKit::Daemon::packageName(pkgid));
            break;
    }
    return message;
}

QString statusMessage(PackageKit::Transaction::Status status)
{
    switch (status) {
        case PackageKit::Transaction::StatusWait:
            return i18n("Waiting...");
        case PackageKit::Transaction::StatusSetup:
            return i18n("Setup...");
        case PackageKit::Transaction::StatusRunning:
            return i18n("Processing...");
        case PackageKit::Transaction::StatusRemove:
            return i18n("Remove...");
        case PackageKit::Transaction::StatusDownload:
            return i18n("Downloading...");
        case PackageKit::Transaction::StatusInstall:
            return i18n("Installing...");
        case PackageKit::Transaction::StatusUpdate:
            return i18n("Updating...");
        case PackageKit::Transaction::StatusCleanup:
            return i18n("Cleaning up...");
//         case PackageKit::Transaction::StatusObsolete:
        case PackageKit::Transaction::StatusDepResolve:
            return i18n("Resolving dependencies...");
        case PackageKit::Transaction::StatusSigCheck:
            return i18n("Checking signatures...");
        case PackageKit::Transaction::StatusTestCommit:
            return i18n("Test committing...");
        case PackageKit::Transaction::StatusCommit:
            return i18n("Committing...");
        //StatusRequest,
        case PackageKit::Transaction::StatusFinished:
            return i18n("Finished");
        case PackageKit::Transaction::StatusCancel:
            return i18n("Canceled");
        case PackageKit::Transaction::StatusWaitingForLock:
            return i18n("Waiting for lock...");
        case PackageKit::Transaction::StatusWaitingForAuth:
            return i18n("Waiting for authorization...");
            //StatusScanProcessList,
            //StatusCheckExecutableFiles,
            //StatusCheckLibraries,
        case PackageKit::Transaction::StatusCopyFiles:
            return i18n("Copying files...");
        case PackageKit::Transaction::StatusUnknown:
        default:
            return i18n("Unknown Status");
    }
}

QString statusDetail(PackageKit::Transaction::Status status)
{
    switch (status) {
        case PackageKit::Transaction::StatusWait:
            return i18n("We are waiting for something.");
        case PackageKit::Transaction::StatusSetup:
            return i18n("Setting up transaction...");
        case PackageKit::Transaction::StatusRunning:
            return i18n("The transaction is currently working...");
        case PackageKit::Transaction::StatusRemove:
            return i18n("The transaction is currently removing packages...");
        case PackageKit::Transaction::StatusDownload:
            return i18n("The transaction is currently downloading packages...");
        case PackageKit::Transaction::StatusInstall:
            return i18n("The transactions is currently installing packages...");
        case PackageKit::Transaction::StatusUpdate:
            return i18n("The transaction is currently updating packages...");
        case PackageKit::Transaction::StatusCleanup:
            return i18n("The transaction is currently cleaning up...");
            //case PackageKit::Transaction::StatusObsolete,
        case PackageKit::Transaction::StatusDepResolve:
            return i18n("The transaction is currently resolving the dependencies of the packages it will install...");
        case PackageKit::Transaction::StatusSigCheck:
            return i18n("The transaction is currently checking the signatures of the packages...");
        case PackageKit::Transaction::StatusTestCommit:
            return i18n("The transaction is currently testing the commit of this set of packages...");
        case PackageKit::Transaction::StatusCommit:
            return i18n("The transaction is currently committing its set of packages...");
            //StatusRequest,
        case PackageKit::Transaction::StatusFinished:
            return i18n("The transaction has finished!");
        case PackageKit::Transaction::StatusCancel:
            return i18n("The transaction was canceled");
        case PackageKit::Transaction::StatusWaitingForLock:
            return i18n("The transaction is currently waiting for the lock...");
        case PackageKit::Transaction::StatusWaitingForAuth:
            return i18n("Waiting for the user to authorize the transaction...");
            //StatusScanProcessList,
            //StatusCheckExecutableFiles,
            //StatusCheckLibraries,
        case PackageKit::Transaction::StatusCopyFiles:
            return i18n("The transaction is currently copying files...");
        case PackageKit::Transaction::StatusUnknown:
        default:
            return i18n("PackageKit does not tell us a useful status right now! Its status is %1.", status);
    }
}

}
