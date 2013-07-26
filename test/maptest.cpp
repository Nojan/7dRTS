// include
// Qt
#include <QtTest/QtTest>

// core
#include <generalmap.h>
#include <graphicmap.h>
#include <hardcodedmap.h>
#include <pathfindingmap.h>
#include <pathfinder.h>

class TestMap : public QObject
{
  Q_OBJECT
private slots:
  void generalMap()
  {
    core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
    graphic::GraphicMap* gMap = new graphic::GraphicMap(&map);
    QImage img(gMap->pixmap().toImage());
    img.save("test.png");
  }
  void graphicMap()
  {}
  void pathFindingMap()
  {}
};

QTEST_MAIN(TestMap)
#include "maptest.moc"
