/****************************************************************************
** Meta object code from reading C++ file 'ClientWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/UI/ClientWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientWindow_t {
    QByteArrayData data[11];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientWindow_t qt_meta_stringdata_ClientWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ClientWindow"
QT_MOC_LITERAL(1, 13, 22), // "on_btnJoinGame_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "on_btnStartGame_clicked"
QT_MOC_LITERAL(4, 61, 25), // "on_btnAckNoServer_clicked"
QT_MOC_LITERAL(5, 87, 27), // "on_btnNavigateBoard_clicked"
QT_MOC_LITERAL(6, 115, 28), // "on_btnMakeSuggestion_clicked"
QT_MOC_LITERAL(7, 144, 20), // "on_btnRefute_clicked"
QT_MOC_LITERAL(8, 165, 28), // "on_btnMakeAccusation_clicked"
QT_MOC_LITERAL(9, 194, 26), // "on_btnViewNotebook_clicked"
QT_MOC_LITERAL(10, 221, 22) // "on_btnSendChat_clicked"

    },
    "ClientWindow\0on_btnJoinGame_clicked\0"
    "\0on_btnStartGame_clicked\0"
    "on_btnAckNoServer_clicked\0"
    "on_btnNavigateBoard_clicked\0"
    "on_btnMakeSuggestion_clicked\0"
    "on_btnRefute_clicked\0on_btnMakeAccusation_clicked\0"
    "on_btnViewNotebook_clicked\0"
    "on_btnSendChat_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientWindow *_t = static_cast<ClientWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnJoinGame_clicked(); break;
        case 1: _t->on_btnStartGame_clicked(); break;
        case 2: _t->on_btnAckNoServer_clicked(); break;
        case 3: _t->on_btnNavigateBoard_clicked(); break;
        case 4: _t->on_btnMakeSuggestion_clicked(); break;
        case 5: _t->on_btnRefute_clicked(); break;
        case 6: _t->on_btnMakeAccusation_clicked(); break;
        case 7: _t->on_btnViewNotebook_clicked(); break;
        case 8: _t->on_btnSendChat_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ClientWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ClientWindow.data,
      qt_meta_data_ClientWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
