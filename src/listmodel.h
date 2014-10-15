#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QVariant>
#include <QList>
#include <QHash>
#include <QQmlEngine>

#include "ListItem.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ListModel(ListItem* prototype, QObject* parent = 0);
    ~ListModel();

    // QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE QVariant get(int row);

    // Helpers
    void appendRow(ListItem* item);
    void appendRows(const QList<ListItem*> &items);
    void insertRow(int row, ListItem* item);
    bool removeRow(int row, const QModelIndex& index = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex& index = QModelIndex());
    ListItem* takeRow(int row, const QModelIndex &index = QModelIndex());

    ListItem* find(const QString& itemId) const;
    QModelIndex indexFromItem(ListItem *item) const;
    Q_INVOKABLE void clear();

protected:
    ListItem* m_prototype;
    QList<ListItem*> m_items;

private slots :
    void updateItem();
};

#endif // LISTMODEL_H
