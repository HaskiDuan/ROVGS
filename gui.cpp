/**************************************************************************************
 * This file is part of ROVGS
 *
 * Copyright 2018 Duanshiqi <815832177@qq.com>(Harbin Institute of Technology at Weihai)
 *
 * ROVGS is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your opption) any later version.
 *
 * ROVGS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABLIITY of FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License along with ROVGS.
 *If not, see <http://www.gnu.org/licenses/>.
 *
 *ACKNOWLEDGEMENT : This project is fully referenced to the tum_ardrone project, the
 *github repository page of tum_ardrone is <https://github.com/tum-vision/tum_ardrone.git>
 *I would like to extend my sincere appreciation to the developers of the tum_ardrone.
 **************************************************************************************/

#include<gui.h>

GUIView::GUIView(QQuickView* parent):QQuickView(parent){

}

GUIView::~GUIView(){

}

int GUIView::setUpView(const QObject* w ){
    if (qgetenv("QT_QUICK_CORE_PROFILE").toInt()) {
        QSurfaceFormat f = this->format();
        f.setProfile(QSurfaceFormat::CoreProfile);
        f.setVersion(4, 4);
        this->setFormat(f);

        //
        //new QQmlFileSelector(this->engine(), this);

        /*
        this->setSource(QUrl("qrc:///dialcontrol.qml"));
        if (this->status() == QQuickView::Error)
            return -1;
        this->setResizeMode(QQuickView::SizeRootObjectToView);
        */

    }
}
