/****************************************************************************
** Meta object code from reading C++ file 'pointcloud.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_demo/include/ros_qt_demo/pointcloud.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pointcloud.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PointCloud_t {
    QByteArrayData data[8];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PointCloud_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PointCloud_t qt_meta_stringdata_PointCloud = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PointCloud"
QT_MOC_LITERAL(1, 11, 13), // "_slotSet2DPos"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "_slotSet2DGoal"
QT_MOC_LITERAL(4, 41, 15), // "_slotMoveCamera"
QT_MOC_LITERAL(5, 57, 14), // "_slotSetSelect"
QT_MOC_LITERAL(6, 72, 14), // "_slotSetReturn"
QT_MOC_LITERAL(7, 87, 11) // "_slotReturn"

    },
    "PointCloud\0_slotSet2DPos\0\0_slotSet2DGoal\0"
    "_slotMoveCamera\0_slotSetSelect\0"
    "_slotSetReturn\0_slotReturn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PointCloud[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PointCloud::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PointCloud *_t = static_cast<PointCloud *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_slotSet2DPos(); break;
        case 1: _t->_slotSet2DGoal(); break;
        case 2: _t->_slotMoveCamera(); break;
        case 3: _t->_slotSetSelect(); break;
        case 4: _t->_slotSetReturn(); break;
        case 5: _t->_slotReturn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PointCloud::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PointCloud.data,
      qt_meta_data_PointCloud,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PointCloud::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PointCloud::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PointCloud.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PointCloud::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
