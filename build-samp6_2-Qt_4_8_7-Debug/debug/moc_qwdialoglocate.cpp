/****************************************************************************
** Meta object code from reading C++ file 'qwdialoglocate.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../samp6_2/qwdialoglocate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwdialoglocate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWDialogLocate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   16,   15,   15, 0x05,
      62,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      96,   84,   15,   15, 0x0a,
     118,   15,   15,   15, 0x08,
     142,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWDialogLocate[] = {
    "QWDialogLocate\0\0row,col,text\0"
    "changeCellText(int,int,QString&)\0"
    "changeActEnable(bool)\0rowNo,colNo\0"
    "setSpinValue(int,int)\0on_BtnSetText_clicked()\0"
    "on_BtnClose_clicked()\0"
};

void QWDialogLocate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QWDialogLocate *_t = static_cast<QWDialogLocate *>(_o);
        switch (_id) {
        case 0: _t->changeCellText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->changeActEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setSpinValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_BtnSetText_clicked(); break;
        case 4: _t->on_BtnClose_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QWDialogLocate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QWDialogLocate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QWDialogLocate,
      qt_meta_data_QWDialogLocate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWDialogLocate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWDialogLocate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWDialogLocate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWDialogLocate))
        return static_cast<void*>(const_cast< QWDialogLocate*>(this));
    return QDialog::qt_metacast(_clname);
}

int QWDialogLocate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QWDialogLocate::changeCellText(int _t1, int _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QWDialogLocate::changeActEnable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
