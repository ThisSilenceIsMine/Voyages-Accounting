#include "sqlrelationaltablemodel.h"

SqlRelationalTableModel::SqlRelationalTableModel(QObject *parent)
    : QSqlRelationalTableModel(parent)
{
    connect(this, &SqlRelationalTableModel::tableNameChanged, this, &SqlRelationalTableModel::ontableNameChanged);
}

QVariant SqlRelationalTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        qDebug() << index << " is not a valid index!";
        return QVariant();
    }
    if(index.row() >= rowCount())
    {
        qDebug() << "Out of bounds!";
        return QString("");
    }
    if(role < Qt::UserRole)
    {
        qDebug() << roles[role] << "< Qt::UserRole";
        qDebug() << "Getting data at " << index;

        return QSqlQueryModel::data(index, role);
    }
    else
    {
        // search for relationships
        for (int i = 0; i < columnCount(); ++i)
        {
            if (this->relation(i).isValid())
            {
                qDebug() << "Found relation on column " << i;
                qDebug() << "Returning value with role " << roles[role];
                return record(index.row()).value(role);
            }
        }
        // if no valid relationship was found
        qDebug() << "No relations found";
        qDebug() << "Returning data at " << index << " from column " << role - Qt::UserRole - 1;
        qDebug() << "===========================================================";
        return QSqlQueryModel::data(this->index(index.row(), role - Qt::UserRole - 1), Qt::DisplayRole);
    }
}

bool SqlRelationalTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags SqlRelationalTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || m_tableName.isEmpty()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QString SqlRelationalTableModel::tableName() const
{
    return m_tableName;
}

void SqlRelationalTableModel::setTableName(const QString &tableName)
{
    m_tableName = tableName;
    this->setTable(m_tableName);
    this->generateRoles();

    emit tableNameChanged();
}

void SqlRelationalTableModel::generateRoles()
{
    roles.clear();
    qDebug() << "\r\n" << this->tableName();
    for(int i = 0; i < this->columnCount(); ++i) {
        QString role = this->headerData(i, Qt::Horizontal).toString();
        roles[Qt::UserRole + i + 1] = role.toUtf8();
        qDebug() << this->headerData(i, Qt::Horizontal);
    }
}


QHash<int, QByteArray> SqlRelationalTableModel::roleNames() const
{
    return roles;
}

void SqlRelationalTableModel::ontableNameChanged()
{
    qDebug() << "Table set to: " << m_tableName << ", selecting!";
    this->select();
}
