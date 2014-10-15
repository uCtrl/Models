#ifndef USCENARIO_H
#define USCENARIO_H

#include "nestedlistitem.h"
#include "nestedlistmodel.h"
#include "utask.h"

class UScenario : public NestedListItem
{
    Q_OBJECT

    enum ScenarioRoles
    {
        idRole = Qt::UserRole + 1,
        nameRole,
        activeRole
    };

public:
    explicit UScenario(QObject *parent = 0);
    ~UScenario();

    // NestedListItem
    QVariant data(int role) const;
    bool setData(const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;
    ListModel* nestedModel() const;

    // Properties
    inline QString id() const { return m_id; }
    inline void id(const QString& id) { m_id = id; emit dataChanged(); }
    inline QString name() const { return m_name; }
    inline void name(const QString& name) { m_name = name; emit dataChanged(); }
    inline bool active() const { return m_active; }
    inline void active(bool active) { m_active = active; emit dataChanged(); }

private:
    QString m_id;
    QString m_name;
    bool m_active;
    NestedListModel* m_tasks;
};

#endif // USCENARIO_H
