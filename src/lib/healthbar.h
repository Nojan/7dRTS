#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "graphicentity.h"
#include "pch.h"


class GraphicHealthBar : public GraphicEntity
{
public:
    GraphicHealthBar();

    void setColor(Qt::GlobalColor color);

private:
    QPointF _position;
    int _largeur;
    int _longueur;
    Qt::GlobalColor _color;
};

class GraphicHealthBarBack : public GraphicEntity
{
public:
    GraphicHealthBarBack();

private:
    QPointF _position;
    int _largeur;
    int _longueur;
    Qt::GlobalColor _color;
};


class HealthBar
{
public:
    HealthBar(size_t attachedEntityId);
    ~HealthBar();

    void update();
    void setHealthBarColor();

    GraphicHealthBarBack * graphicBack();
    GraphicHealthBar * graphicBar();

private:
    size_t _attachedEntityId;
    QPointF _position;

    float _HealthPercentage;

    GraphicHealthBarBack * _graphicBack;
    GraphicHealthBar * _graphicBar;

};


class HealthBarsManager
{
public:
    HealthBarsManager();


    void addHealthBar(HealthBar* healthBar);

    void evolve(const float deltas);

  private:
    std::vector<HealthBar*> _healthBars;
    QGraphicsScene * _scene;

};

#endif // HEALTHBAR_H
