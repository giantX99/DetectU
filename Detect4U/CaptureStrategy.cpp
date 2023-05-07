
#include "CaptureStrategy.h"

CaptureStrategy::CaptureStrategy() {}

CaptureStrategy::~CaptureStrategy() { if (cam_viewer) { delete cam_viewer; } }

void CaptureStrategy::set_cam_viewer(CameraViewer* c) { cam_viewer = c; }


QString CaptureStrategy::set_filename() {

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << "Detect4U_Capture@";
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d-%Hh-%Mm-%Ss.PNG");
    std::string file_name = ss.str();

    std::cout << file_name << std::endl;

    return QString::fromStdString(file_name);
}


void CaptureStrategy::start_capture() {

    //capture = new QImageCapture(cam_viewer->get_camera()); //Qt documentation is not update, this constructor is now a deleted function.
    cam_viewer->get_session()->setImageCapture(&capture);

    if (capture.isReadyForCapture()) { capture.captureToFile(this->set_filename()); }
    else { std::cout << "Not ready to capture image" << std::endl; }
}


void CaptureStrategy::do_strat(bool t) {
    if (t) { this->start_capture(); }
}
