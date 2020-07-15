#ifndef SQLRELATIONALTABLEMODEL_H
#define SQLRELATIONALTABLEMODEL_H

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QtSql>
#include <QSqlRelationalTableModel>

class SqlRelationalTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

    Q_PROPERTY(QString tableName MEMBER m_tableName READ tableName WRITE setTableName NOTIFY tableNameChanged)
public:
    explicit SqlRelationalTableModel(QObject *parent = nullptr);

    // Basic functionality

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QString tableName() const;
    void setTableName(const QString &tableName);

    void generateRoles();

    QHash<int, QByteArray> roleNames() const override;
signals:
    void tableNameChanged();
public slots:
    void ontableNameChanged();
private:
    QHash<int, QByteArray> roles;
    QString m_tableName;

    // QAbstractItemModel interface

};

#endif // SQLRELATIONALTABLEMODEL_H
