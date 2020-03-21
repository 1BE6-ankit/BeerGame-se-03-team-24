#include "game_ui.h"

Game_ui::Game_ui(QWidget *parent, std::shared_ptr<Game> p)
    : QAbstractItemModel(parent){
}

QVariant Game_ui::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
