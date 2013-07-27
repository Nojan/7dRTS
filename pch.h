#ifndef PCH_H
#define PCH_H

// add C includes here

#ifdef __cplusplus
// add C++ includes here

// std
#include <assert.h>
#include <cfloat>
#include <cmath>
#include <climits>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <Eigen/Eigen>
#pragma GCC diagnostic pop

// Qt
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>

#endif // __cplusplus

#endif // PCH_H
