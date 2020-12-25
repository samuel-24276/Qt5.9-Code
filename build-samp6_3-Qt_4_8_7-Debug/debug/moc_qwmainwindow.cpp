/****************************************************************************
** Meta object code from reading C++ file 'qwmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../samp6_3/qwmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      45,   13,   13,   13, 0x08,
      70,   13,   13,   13, 0x08,
     105,   13,   13,   13, 0x08,
     140,  134,   13,   13, 0x08,
     176,  134,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWMainWindow[] = {
    "QWMainWindow\0\0on_actWidgetInsite_triggered()\0"
    "on_actWidget_triggered()\0"
    "on_actMainWindowInside_triggered()\0"
    "on_actMainWindow_triggered()\0index\0"
    "on_tabWidget_tabCloseRequested(int)\0"
    "on_tabWidget_currentChanged(int)\0"
};

void QWMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QWMainWindow *_t = static_cast<QWMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actWidgetInsite_triggered(); break;
        case 1: _t->on_actWidget_triggered(); break;
        case 2: _t->on_actMainWindowInside_triggered(); break;
        case 3: _t->on_actMainWindow_triggered(); break;
        case 4: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QWMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QWMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QWMainWindow,
      qt_meta_data_QWMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWMainWindow))
        return static_cast<void*>(const_cast< QWMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QWMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
