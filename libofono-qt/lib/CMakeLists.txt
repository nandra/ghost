PROJECT(ofono-qt)

ADD_DEFINITIONS("-DBUILD_OFONO_QT_LIBRARY")

SET(ofono-qt_SOURCES
	ofonocallbarring.cpp
	ofonocallvolume.cpp
	ofonomessage.cpp
	ofonomodeminterface.cpp
	ofonophonebook.cpp
	ofonovoicecall.cpp
	ofonocallforwarding.cpp
	ofonoconnmancontext.cpp
	ofonomessagemanager.cpp
	ofonomodemmanager.cpp
	ofonoradiosettings.cpp
	ofonovoicecallmanager.cpp
	ofonocallmeter.cpp
	ofonoconnman.cpp
	ofonomessagewaiting.cpp
	ofononetworkoperator.cpp
	ofonosimmanager.cpp
	ofonocallsettings.cpp
	ofonointerface.cpp
	ofonomodem.cpp
	ofononetworkregistration.cpp
	ofonosupplementaryservices.cpp
)

SET(ofono-qt_HEADERS
#ofono-qt_global.h
	ofonocallmeter.h
	ofonoconnmancontext.h
	ofonomessage.h
	ofonomodem.h
	ofononetworkoperator.h
	ofonopropertysetting.h  
	ofonosupplementaryservices.h
	ofonocallbarring.h
	ofonocallsettings.h
	ofonoconnman.h
	ofonomessagemanager.h
	ofonomodeminterface.h
	ofononetworkregistration.h
	ofonoradiosettings.h
	ofonovoicecall.h
	ofonocallforwarding.h
	ofonocallvolume.h
	ofonointerface.h
	ofonomessagewaiting.h
	ofonomodemmanager.h
	ofonophonebook.h
	ofonosimmanager.h
	ofonovoicecallmanager.h
)

INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_QTDBUS_INCLUDE_DIR})

SET(QT_USE_QTDBUS true)

QT4_WRAP_CPP(ofono-qt_HEADERS_MOC ${ofono-qt_HEADERS})

ADD_LIBRARY(ofono-qt SHARED ${ofono-qt_SOURCES}
    ${ofono-qt_HEADERS_MOC})

TARGET_LINK_LIBRARIES(ofono-qt
	${QT_QTCORE_LIBRARY}
	${QT_QTDBUS_LIBRARY}
)

INSTALL(TARGETS ofono-qt DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
