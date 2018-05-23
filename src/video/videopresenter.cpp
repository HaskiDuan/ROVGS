#include <iostream>

#include "videopresenter.h"

// Qt

#include <QCamera>
#include <QCameraInfo>

using namespace presentation;

class VideoPresenter::Impl
{
public:
    QCamera* camera;
    QAbstractVideoSurface* videoSurface;

    void updateCameraVideoSurface()
    {
        if (!camera || !videoSurface) return;

        camera->setViewfinder(videoSurface);
        camera->start();
    }
};

VideoPresenter::VideoPresenter(QObject* parent):
    QObject(parent),
    d(new Impl())
{
    this->updateSource();
}

VideoPresenter::~VideoPresenter()
{
    delete d;
}

QAbstractVideoSurface* VideoPresenter::videoSurface() const
{
    return d->videoSurface;
}

void VideoPresenter::setVideoSurface(QAbstractVideoSurface* videoSurface)
{
    if (d->videoSurface == videoSurface) return;
    d->videoSurface = videoSurface;

    d->updateCameraVideoSurface();
}

void VideoPresenter::updateSource()
{
    if (d->camera) delete d->camera;

    QCameraInfo info("http://192.168.0.102:8080/?action=stream"); // TODO: to settings
    if (info.isNull())
    {
        d->camera = nullptr;
        std::cout << "the camera is not exist!" <<std::endl;
    }
    else
    {
        d->camera = new QCamera(info, this);
        d->updateCameraVideoSurface();
    }
}
