#include "driverstablemodel.h"

DriversTableModel::DriversTableModel(QObject *parent)
    : QSqlRelationalTableModel(parent)
{

}

//QVariant DriversTableModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

//bool DriversTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
//{
//    if (value != headerData(section, orientation, role)) {
//        // FIXME: Implement me!
//        emit headerDataChanged(orientation, section, section);
//        return true;
//    }
//    return false;
//}


QVariant DriversTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(index.row() >= rowCount())
    {
        return QString("");
    }
    if(role < Qt::UserRole)
    {
        return QSqlQueryModel::data(index, role);
    }
    else
    {
        // search for relationships
        for (int i = 0; i < columnCount(); ++i)
        {
            if (this->relation(i).isValid())
            {
                return record(index.row()).value(role);
            }
        }
        // if no valid relationship was found
        return QSqlQueryModel::data(this->index(index.row(), role - Qt::UserRole - 1), Qt::DisplayRole);
    }
}

//bool DriversTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (data(index, role) != value) {
//        // FIXME: Implement me!
//        emit dataChanged(index, index, QVector<int>() << role);
//        return true;
//    }
//    return false;
//}

void DriversTableModel::generateRoles()
{
    roles.clear();
    qDebug() << "\r\n" << this->tableName();
    for(int i = 0; i < this->columnCount(); ++i) {
        QString role = this->headerData(i, Qt::Horizontal).toString();
        roles[Qt::UserRole + i + 1] = role.toLatin1();
        qDebug() << this->headerData(i, Qt::Horizontal);
    }

}

//bool DriversTableModel::insertRows(int row, int count, const QModelIndex &parent)
//{
//    beginInsertRows(parent, row, row + count - 1);
//    // FIXME: Implement me!
//    endInsertRows();
//}

//bool DriversTableModel::removeRows(int row, int count, const QModelIndex &parent)
//{
//    beginRemoveRows(parent, row, row + count - 1);
//    // FIXME: Implement me!
//    endRemoveRows();
//}


QHash<int, QByteArray> DriversTableModel::roleNames() const
{
    return roles;
}
