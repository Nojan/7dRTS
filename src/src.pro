TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = lib \
          game

game.depends += lib
