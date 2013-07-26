TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = lib \
          bin

bin.depends += lib
