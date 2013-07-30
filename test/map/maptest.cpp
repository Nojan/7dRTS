// include
// Qt
#include <QtTest/QtTest>

// core
#include <generalmap.h>
#include <graphicmap.h>
#include <hardcodedmap.h>
#include <pathfindingmap.h>
#include <graphicpathfindingmap.h>
#include <pathfinder.h>

class TestMap : public QObject
{
  Q_OBJECT
private slots:
  void generalMap()
  {
    core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
    QCOMPARE(map.tileGrid().width(), std::size_t(64));
    QCOMPARE(map.tileGrid().height(), std::size_t(64));
    QCOMPARE(map.rooms().size(), std::size_t(11));
  }

  void graphicMap()
  {
    core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
    graphic::GraphicMap* gMap = new graphic::GraphicMap(&map);
    QImage img(gMap->pixmap().toImage());
    img.save("testGraphic.png");
  }

  void pathFindingMap()
  {
    core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
    core::PathFindingMap pfMap(&map);
    graphic::GraphicPathFindingMap* gpfMap = new graphic::GraphicPathFindingMap(&pfMap);
    QImage img(gpfMap->pixmap().toImage());
    img.save("testGraphicPF.png");
  }

  void pathFinder()
  {
    core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
    core::PathFindingMap pfMap(&map);
    core::PathFinder<core::PathFindingMap> pf;
    std::vector<core::TilePos> path = pf.find(pfMap, {0, 0}, {10, 10});
    std::vector<core::TilePos> expectedPath = {
      {0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{10,10},
    };
    QCOMPARE(path, expectedPath);

    path = pf.find(pfMap, {28, 46}, {24, 41});
    expectedPath = {
      {28,46},{29,46},{29,45},{29,44},{28,43},{27,42},{27,41},{26,41},{25,41},{24,41},
    };
    QCOMPARE(path, expectedPath);

  }
};

QTEST_MAIN(TestMap)
#include "maptest.moc"
