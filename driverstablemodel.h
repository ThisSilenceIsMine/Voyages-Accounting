#ifndef DRIVERSTABLEMODEL_H
#define DRIVERSTABLEMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include <QSqlRelationalTableModel>

class DriversTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit DriversTableModel(QObject *parent = nullptr);

    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
//    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
//    bool setData(const QModelIndex &index, const QVariant &value,
//                 int role = Qt::EditRole) override;
    void generateRoles();
private:
    QHash<int, QByteArray> roles;

public:
    QHash<int, QByteArray> roleNames() const override;
};

#endif // DRIVERSTABLEMODEL_H
