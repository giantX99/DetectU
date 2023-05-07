
#include "RecordStrategy.h"

RecordStrategy::RecordStrategy(){}

RecordStrategy& RecordStrategy::getInstance() {
    static RecordStrategy recorder_instance;
    return recorder_instance;
}

RecordStrategy::~RecordStrategy(){ if (cam_viewer) { delete cam_viewer; } }

void RecordStrategy::set_cam_viewer(CameraViewer* c) { cam_viewer = c; }

void RecordStrategy::set_output() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << "Detect4U_Recording@";
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d-%Hh-%Mm-%Ss");
    std::string file_name = ss.str();
    //std::cout << "File Name: " << file_name << std::endl;

    recorder.setOutputLocation(QUrl::fromLocalFile(QString::fromStdString(file_name)));
}

void RecordStrategy::start_record() {

    cam_viewer->get_session()->setRecorder(&recorder);
    recorder.setQuality(QMediaRecorder::HighQuality);

    try{
        this->set_output();
    }
    catch (QMediaRecorder::Error e) {
        std::cout << "Error occurred" << std::endl;
        return;
    }

    recorder.record();
    std::cout << "RECORDING STARTED" << std::endl;
}

void RecordStrategy::stop_record() {
    if (recorder.recorderState()) {
        recorder.stop();
        std::cout << "RECORDING STOPPED" << std::endl;
    }
}


void RecordStrategy::do_strat(bool t){
    if (t) { this->start_record(); }
    else { this->stop_record(); }
}
