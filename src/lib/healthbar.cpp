#include "healthbar.h"

GraphicHealthBar::GraphicHealthBar()
{
    _longueur = 32;
    _largeur = 2;
    _color = Qt::green;
}

void GraphicHealthBar::setColor(Qt::GlobalColor color)
{
    _color = color;

}

GraphicHealthBarBack::GraphicHealthBarBack()
{
    _longueur = 32;
    _largeur = 2;
    _color = Qt::black;
}

HealthBar::HealthBar(size_t attachedEntityId)
{
    _attachedEntityId = attachedEntityId;
    _position = QPointF(.0f,.0f);   //temporaire pour test d'affichage en attendant de récupérer les valeurs de l'entity à partir de son id
    _HealthPercentage = 1.0f;       //temporaire pour tests, il faudra le calculer à partir des infos de l'entity
}

GraphicHealthBarBack * HealthBar::graphicBack()
{
    return _graphicBack;
}

GraphicHealthBar * HealthBar::graphicBar()
{
    return _graphicBar;
}

void HealthBar::update()
{
    // ajouter ici le calcul du pourcentage de vie, à récupérer sur l'entity dont on a l'id
}

void HealthBar::setHealthBarColor()
{
    if (_HealthPercentage >= 1)
        graphicBar()->setColor(Qt::green);
    else if (_HealthPercentage >= 0.5f)
        graphicBar()->setColor(Qt::yellow);
    else
        graphicBar()->setColor(Qt::red);


}

void HealthBarsManager::addHealthBar(HealthBar *healthBar)
{
    _healthBars.push_back(healthBar);
}

HealthBar::~HealthBar()
{
    if(_graphicBar->scene())
        _graphicBar->scene()->removeItem(_graphicBar);
    if(_graphicBack->scene())
        _graphicBack->scene()->removeItem(_graphicBack);
}
