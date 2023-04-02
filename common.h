#ifndef COMMON_H
#define COMMON_H

#include <QDebug>

#define CHECK_RESULT_RETURN(condition, var, message) \
    if(condition) { \
        qDebug() << message;\
        return var; \
    }

#endif // COMMON_H
